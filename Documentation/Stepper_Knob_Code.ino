#include <WiFi.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Pin Definitions for DRV8833 (Motor control pins)
#define MOTOR_IN1 13   // Stepper motor winding A+
#define MOTOR_IN2 14   // Stepper motor winding A-
#define MOTOR_IN3 27   // Stepper motor winding B+
#define MOTOR_IN4 26   // Stepper motor winding B-
#define ENABLE_PIN 12  // Enable/Disable motor (to simulate power cut)
#define TOGGLE_PIN 25  // Pin for the toggle switch (Free/Automated mode)
#define THERMISTOR_PIN 34  // Analog pin for the thermistor
#define POTENTIOMETER_PIN 35  // Analog pin for the potentiometer

// WiFi Credentials
const char *ssid = "yourSSID";
const char *password = "yourPASSWORD";

// BLE Service UUID
BLEServer *bleServer;
BLEService *bleService;
BLECharacteristic *bleChar;
const char *bleServiceUUID = "0000180A-0000-1000-8000-00805F9B34FB";
const char *bleCharUUID = "00002A29-0000-1000-8000-00805F9B34FB";

// Thermistor Parameters
#define NOMINAL_RESISTANCE 10000    // Resistance at 25 degrees Celsius
#define NOMINAL_TEMPERATURE 25      // Temperature for nominal resistance (Celsius)
#define B_COEFFICIENT 3950          // Beta coefficient of the thermistor
#define SERIES_RESISTOR 10000       // Value of the series resistor

// Potentiometer Configuration (RH24PC Potentiometer)
#define POT_MIN_ANGLE 0             // Min angle of potentiometer
#define POT_MAX_ANGLE 340           // Max angle of potentiometer (340° as per specs)
#define ADC_MAX_VALUE 4095          // 12-bit ADC on ESP32

// Stepper Motor Configurations
#define STEPS_PER_REV 400           // 0.9° per step (360 / 0.9 = 400)
#define MICROSTEP_MODE 1            // No microstepping in DRV8833 (full step control)
#define STEP_DELAY 2                // Delay between steps in milliseconds

// Thermal Runaway Threshold
#define MAX_TEMP_CELSIUS 70.0

// Function to read temperature from the thermistor
float readThermistor() {
  int analogValue = analogRead(THERMISTOR_PIN);
  float resistance = SERIES_RESISTOR / ((4096.0 / analogValue) - 1);
  float steinhart;
  steinhart = resistance / NOMINAL_RESISTANCE;           // (R/Ro)
  steinhart = log(steinhart);                            // ln(R/Ro)
  steinhart /= B_COEFFICIENT;                            // 1/B * ln(R/Ro)
  steinhart += 1.0 / (NOMINAL_TEMPERATURE + 273.15);     // + (1/To)
  steinhart = 1.0 / steinhart;                           // Invert
  steinhart -= 273.15;                                   // Convert to Celsius
  return steinhart;
}

// Function to prevent thermal runaway
void thermalRunawayPrevention() {
  float temperature = readThermistor();
  if (temperature > MAX_TEMP_CELSIUS) {
    Serial.println("Warning: Thermal Runaway Detected! Shutting down motor.");
    digitalWrite(ENABLE_PIN, HIGH);  // Disable stepper motor (cut power)
  } else {
    digitalWrite(ENABLE_PIN, LOW);   // Enable motor if temperature is within safe limits
  }
}

// Function to initialize BLE
void initBLE() {
  BLEDevice::init("MotorizedKnob");
  bleServer = BLEDevice::createServer();
  bleService = bleServer->createService(bleServiceUUID);
  
  bleChar = bleService->createCharacteristic(
               bleCharUUID,
               BLECharacteristic::PROPERTY_READ |
               BLECharacteristic::PROPERTY_NOTIFY
             );
  bleService->start();
  BLEDevice::startAdvertising();
  Serial.println("BLE Initialized.");
}

// Function to connect to WiFi
void initWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi.");
}

// Function to read angle from potentiometer
float readPotentiometer() {
  int potValue = analogRead(POTENTIOMETER_PIN);  // Read the potentiometer's analog value
  float angle = map(potValue, 0, ADC_MAX_VALUE, POT_MIN_ANGLE, POT_MAX_ANGLE);  // Map the potentiometer reading to an angle (0-340 degrees)
  Serial.print("Current Angle: ");
  Serial.println(angle);
  return angle;
}

// Function to move the stepper motor by one step (DRV8833 H-Bridge control)
void stepMotor(int step) {
  switch (step % 4) {
    case 0:
      digitalWrite(MOTOR_IN1, HIGH);
      digitalWrite(MOTOR_IN2, LOW);
      digitalWrite(MOTOR_IN3, HIGH);
      digitalWrite(MOTOR_IN4, LOW);
      break;
    case 1:
      digitalWrite(MOTOR_IN1, LOW);
      digitalWrite(MOTOR_IN2, HIGH);
      digitalWrite(MOTOR_IN3, HIGH);
      digitalWrite(MOTOR_IN4, LOW);
      break;
    case 2:
      digitalWrite(MOTOR_IN1, LOW);
      digitalWrite(MOTOR_IN2, HIGH);
      digitalWrite(MOTOR_IN3, LOW);
      digitalWrite(MOTOR_IN4, HIGH);
      break;
    case 3:
      digitalWrite(MOTOR_IN1, HIGH);
      digitalWrite(MOTOR_IN2, LOW);
      digitalWrite(MOTOR_IN3, LOW);
      digitalWrite(MOTOR_IN4, HIGH);
      break;
  }
  delay(STEP_DELAY);
}

// Function to move stepper motor to a specific angle
void moveStepperToAngle(float targetAngle) {
  int steps = (targetAngle / 360.0) * (STEPS_PER_REV * MICROSTEP_MODE);
  for (int i = 0; i < steps; i++) {
    stepMotor(i);
  }
}

// Function to handle Free and Automated mode toggle
void handleToggleSwitch() {
  int toggleState = digitalRead(TOGGLE_PIN);

  if (toggleState == HIGH) {
    // Free Mode: Disable the motor but still read the knob angle
    Serial.println("Free Mode Activated");
    digitalWrite(ENABLE_PIN, HIGH);  // Disable stepper motor (cut power)
  } else {
    // Automated Mode: Enable the motor and control the angle
    Serial.println("Automated Mode Activated");
    digitalWrite(ENABLE_PIN, LOW);   // Enable stepper motor
  }
}

void setup() {
  Serial.begin(115200);

  // Initialize WiFi and BLE
  initWiFi();
  initBLE();

  // Initialize motor and toggle switch
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_IN3, OUTPUT);
  pinMode(MOTOR_IN4, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(TOGGLE_PIN, INPUT_PULLUP); // Toggle switch input, using pull-up resistor

  // Set the motor to disabled by default
  digitalWrite(ENABLE_PIN, HIGH);

  Serial.println("Setup completed.");
}

void loop() {
  // Read temperature and prevent thermal runaway
  thermalRunawayPrevention();

  // Read angle from potentiometer and send via BLE
  float currentAngle = readPotentiometer();
  bleChar->setValue(String(currentAngle).c_str());
  bleChar->notify();

  // Check the state of the toggle switch
  handleToggleSwitch();

  // If in automated mode, move the motor to the desired angle
  if (digitalRead(TOGGLE_PIN) == LOW) {
    moveStepperToAngle(currentAngle);  // Move the stepper motor to the current potentiometer angle
  }

  delay(1000);  // Adjust delay as needed
}
