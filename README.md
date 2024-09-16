# Stepper_Knob
Hardware, firmware development of an automatable kitchen knob.

![image](https://github.com/user-attachments/assets/f60eb6ef-5f02-48cc-b8e3-cc1882c6f467)


## Documentation

The CAD files have been drawn up in Solidworks 2024.

The main assembly to view is Knob_Assembly_SM.sldasm.

CAD files made by me are for the potentiometer, stepper motor, knob, and chassis.

Full size chassis drawings may be found in the Documentation folder and the Summary Sheet.

Other parts drawings may be found in the BOM references.

The summary sheet can be opened with LibreOffice and its equivalents.

The stepper schematic can be opened with Fritzing (v.1.0.3 recommended as of 09/16/2024). https://fritzing.org/

### Chassis Sheet Metal Flat Drawing
![image](https://github.com/user-attachments/assets/58dd75d5-2be1-4fcd-9dfb-024b5247f055)

### Chassis Sheet Metal Flat Drawing
![image](https://github.com/user-attachments/assets/ab4e0f1a-96de-4a25-80cb-5e718c31a1eb)

### Wiring Diagram
![Wiring_Diag_Breadboard](https://github.com/user-attachments/assets/685f8440-5a24-4d5c-8a70-a5ffe71dd556)

### Wiring Schematic
![Wiring_Diag_Schem](https://github.com/user-attachments/assets/f49502c5-4490-4d8b-a98a-bb0b77eae295)

### PCB Mockup
![PCB_Prototype](https://github.com/user-attachments/assets/31be55ea-b267-450f-94f9-cd82bbb88921)

### BOM
See Documentation -> Summary Sheet -> BOM.
Total material cost is ~$150.29 sans shipping, wiring, and manufacturing costs.

| Part                          | Description                                                               | Vendor                  |   Number | Unit Price   | Total Cost   | Link(s)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|:------------------------------|:--------------------------------------------------------------------------|:------------------------|---------:|:-------------|:-------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| HT17-222_RevD                 | Double Sided Double Pole 0.9 Deg Step Stepper Motor                       | Applied Motion Products |        1 | $56.00       | $56.00       | https://applied-motion.s3.amazonaws.com/documents/2D-Drawing/HT17-222_RevD.pdf https://www.applied-motion.com/s/product/step-motor-9-degreeht17222d/01t5i000000y0ElAAI?name=HT17-222D-NEMA-17-High-Torque-Stepper-Motor-0.9-Degree-w-double-shaft                                                                                                                                                                                                             |
| 5mm Vertical Slide Switch      | Slide Switch                                                              | uxCell                  |        1 | $0.51        | $0.51        | https://www.amazon.com/uxcell-Vertical-Switch-Terminals-Latching/dp/B07GSJHGD2                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| ESP32 WROOM RevE               | Microcontroller                                                           | Esspressif              |        1 | $10.00       | $10.00       | https://www.digikey.com/en/products/detail/espressif-systems/ESP32-DEVKITC-32E/12091810 https://www.digikey.com/en/models/9356990 https://forum.fritzing.org/t/esp32-wroom-32u/12978 https://grabcad.com/library/esp32-19                                                                                                                                                                                                                                                                              |
| 10k Ohm Through Hole Resistor  | Standard throughhole resistor                                             | Adafruit                |        1 | $0.03        | $0.03        | https://grabcad.com/library/resistors-0-5w-pitch-10-2mm-401-57mil-1 https://www.adafruit.com/product/2784                                                                                                                                                                                                                                                                                                                                                                                             |
| DRV8833                        | Stepper motor controller                                                   | Adafruit                |        1 | $5.95        | $5.95        | https://www.adafruit.com/product/3297#technical-details https://github.com/adafruit/Fritzing-Library https://grabcad.com/library/stepper-motor-driver-drv8825-1                                                                                                                                                                                                                                                                                                                                       |
| 5mm Universal Joint            | Universal Joint                                                           | Befenybay               |        1 | $2.75        | $2.75        | https://www.amazon.com/Befenybay-Universal-Joint-Coupling-Screws/dp/B07VC9F1RH                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| RH24PC                         | Potentiometer                                                             | P3 America              |        1 | $16.00       | $16.00       | https://p3america.com/rh24pc-110mm-series/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| NXFT15XH103FA2B090             | Thermistor                                                                | NXF                     |        1 | $0.48        | $0.48        | https://grabcad.com/library/thermistor-nxft15xh103fa2b090-1 https://www.digikey.com/en/products/detail/murata-electronics/NXFT15XH103FA2B090/5797782                                                                                                                                                                                                                                                                                                                                                   |
| 9262K623                       | Oil Resistant O-Ring 1mm wide 24mm ID                                      | McMaster-Carr           |        1 | $0.13        | $0.13        | https://www.mcmaster.com/9262K623/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| 90591A109                      | Zinc-Plated Steel Nut M1.6x035mm                                           | McMaster-Carr           |        2 | $0.23        | $0.46        | https://www.mcmaster.com/90591A109/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 91292A265                      | 18-8 Stainless Steel Socket Head Screw M1.6x0.35 10mm long                 | McMaster-Carr           |        2 | $0.27        | $0.53        | https://www.mcmaster.com/91292A265/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 92095A119                      | Button Head Hex Drive Head Screw 18-8 SS M3x0.5 15 long                    | McMaster-Carr           |        4 | $0.06        | $0.25        | https://www.mcmaster.com/92095A119/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 92095A183                      | Button Head Hex Drive Screw 18-8 SS M3x0.5mm 12mm long                    | McMaster-Carr           |        3 | $0.07        | $0.20        | https://www.mcmaster.com/92095A183/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 92095A451                      | Button Head Hex Drive Screw M2x0.04mm 4mm long 18-8 SS M3x0.5mm 12mm long | McMaster-Carr           |        2 | $0.18        | $0.36        | https://www.mcmaster.com/92095A451/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 92470A144                      | Phillips Rounded Head Screw 18-8 SS No. 6 ¼” long                         | McMaster-Carr           |        2 | $0.07        | $0.13        | https://www.mcmaster.com/92470A144/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| U Joint Cover                  | U Joint Sock (Provided Example)                                           | McMaster-Carr           |        1 | $10.00       | $10.00       | https://woodmaxx.com/product/u-joint-rubber-boot-cover/?srsltid=AfmBOopjSPO4uOqQSOcNj2fHIlsJ4rvmo4TqwxTfwn4w8pyyCbhFCV4BASo                                                                                                                                                                                                                                                                                                                                                                                                                   |
| 94000A330                      | 18-8 Stainless Steel Cap Screw Nut M3x0.5mm                               | McMaster-Carr           |        3 | $0.47        | $1.40        | https://www.mcmaster.com/94000A330/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 94868A718                      | Female Thread Hex Standoff 18-8 SS 4.5mm Hex 7mm Long M3x0.5mm            | McMaster-Carr           |        3 | $4.08        | $12.24       | https://www.mcmaster.com/94868A718/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 8983K135                       | SS 304 Sheet 12”x12” 0.06” thick                                          | McMaster-Carr           |        1 | $32.85       | $32.85       | https://www.mcmaster.com/8983K42/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |


### Code
See Documentation -> Stepper_Knob_Code.

This code controls a stepper motor using an ESP32, WiFi, and Bluetooth Low Energy (BLE) communication. It includes features for reading a thermistor, potentiometer, and handling motor control.
  - WiFi and BLE: It initializes WiFi and BLE to allow remote monitoring and control of the motor's position. The current potentiometer angle is transmitted via BLE notifications.
  - Stepper Motor Control: The code controls a stepper motor using a DRV8833 motor driver. It steps the motor based on the angle read from a potentiometer and allows for switching between "Free" and "Automated" modes via a toggle switch:
      - Free Mode: The motor is disabled, but the potentiometer angle is still read.
      - Automated Mode: The motor moves to match the potentiometer's position.
  - Thermistor: A thermistor is used to monitor temperature. If the temperature exceeds a set threshold (70°C), the motor is disabled to prevent thermal runaway.
  - Potentiometer: The potentiometer's analog reading is mapped to a specific angle (0 to 340 degrees) and used to control the stepper motor’s position.
  - Motor Step Calculation: The motor is stepped based on the target angle, which is calculated from the potentiometer reading. The motor control logic handles the necessary steps to rotate the motor.

This setup allows remote control and monitoring of the motor's behavior while incorporating safety measures against overheating.

### Design Philosophy Explanations
See Documentation -> Summary Sheet -> Justification.

| Feature                      | Description                                                                                                                                                                 |
|------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **General Design**            | Reduced volume/area taken by knob. Integrated PCB and assembly, allowing space for future proofing.                                                   |
| **Dual shaft stepper**        | Less torque, but less power requirements. UL1061 wiring sufficient for 80 deg temperatures.                                                                                  |
| **Motor Controller**          | Cheap, low voltage/power. Has built-in Wifi & BLE capability.                                                                                                                 |
| **U-Joint**                   | Ensures rotational accuracy, single joint for cost and space. Joint protected by a neoprene sock for chemical and heat protection.                                           |
| **PCB Design**                | Minimized hand wiring for assembly, including the switch. Used dev board for prototyping with extra ports for additional features.                                           |
| **Thermistor**                | Added for thermal runaway shutoff protection.                                                                                                                               |
| **Power**                     | 5V microUSB rail, also serves as a bootstrap port. Enclosed to avoid hacking, but inline with available stove source gaps.                                                   |
| **PCB Wiring**                | Can be routed through a hole into the mounting space.                                                                                                                       |
| **Sheet Metal Chassis**       | Cheaper for mass production, leveraging material tolerances.                                                                                                               |
| **Sheet Metal Material & Wall Thickness**       | Stainless 304 for cheap SS and corrosion resistance. Thickness calculated to be the cheapest option while avoiding ultimate strength failure (see bending_stress_calcs.py).|                                                                              
| **Sheet Metal Wall Design**   | Walls angle outwards as mounting screws tighten, staying flush. Internal edges shield against contaminants and don't interfere with the stepper.                             |
| **Gaps**                      | Tolerances allow for manufacturing defects.                                                                                                                                 |
| **Base Sealing for Knob**     | Gasket added for chemical resistance.                                                                                                                                       |
| **Buna-M O ring**             | Seals against oil and contaminants, borrowed tolerance from pot.                                                                                                            |
| **Rail Mount**                | Slot designed for blockages and mounting surface spots. More self-tapping screws can be added if needed.                                                                     |
| **Screws vs adhesives**       | Adhesives lose shear strength over time, especially in heat. Screws offer permanent, easier cleanup.                                                                         |

### Assembly Instructions
See Documentation => Summary Sheet -> Assembly with the steps w/ pictures.

**Note**: All bolts should be hand-tight to avoid stripping, with the exception of the sheet metal screws.

#### General Assembly Requirements:
- **Fastening**: You may need to solder the thermistor onto the PCB. The PCB should have plug-and-play connections for the factory stepper and potentiometer connectors.
- **Estimated Assembly Time**: 15-30 minutes max.

#### Steps:

1. **Screw standoffs** to the PCB with the 3 12mm long hex button screws.
   
2. **Mount the PCB** with the standoffs in place along the 3 holes on the sheet metal chassis. Secure with the 3 corresponding 3mm cap screws.
   
3. **Mount the vertical switch** with the 2mm bolts. The switch already has threads, so tighten until the switch is secure.
   
4. **Slide the U-joint sock** over the U-joint.
   
5. **Connect and mount one of the U-joint holes** to the shorter shaft of the stepper motor (should be the 15mm long end, where there is no raise from the base of the stepper motor). Secure the set screws.
   
6. **Add the 2 1.6mm socket head bolts** to the potentiometer such that the head of the bolt is placed at the back face of the potentiometer (where the tabs of the potentiometer fillet from). These bolts should be fed through the holes, NOT THE SLOTS, of the potentiometer.
   
7. **Push in the potentiometer** onto the other side of the stepper motor (long shaft side) such that the back face of the potentiometer (where the socket screw head should be) is as close to the stepper motor base as possible. The shaft of the stepper motor should be 5mm OD, which is identical to the maximum distance from the chord of the potentiometer. The material of the potentiometer hole is also brass, so a press fit is possible.
   
8. **Add the O-ring** on the ridge of the potentiometer.
   
9. **Mount the stepper motor/potentiometer** on the sheet metal chassis such that the universal joint is facing towards the open end of the chassis.
   
10. **Secure the stepper motor/potentiometer** with the 4 M3x0.5, 15mm long bolts and the 2 M1.6 nuts.
    
11. **Connect all electrical connections** to the PCB (stepper motor, primarily). This assumes the switch and thermistor are already connected to the PCB. For the thermistor, tape the ends to a wall onto the chassis and solder the leads onto the PCB.
    
12. **Ensure that the top of the chassis** is aligned with the top of the stove. You should see the open slotted chassis tab towards the top and the words “Free” and “Auto” displayed horizontally.
    
13. **Route the USB cable** from the stove and connect it to the microcontroller to provide power.
    
14. **Mount the universal joint end** to the stove shaft, and tighten the corresponding set screw.
    
15. **Screw into the mounting surface** with the self-tapping screws. Stop screwing the screws after you notice the top and bottom tabs to be flush against the mounting surface.
    
16. **Mount the knob** onto the exposed shaft by pushing it in. This should be a tight press fit.

### Prototype to Manufacturing

#### Timeline:
**1 month for prototyping & testing, 1-2 months for manufacturing 200 units**.
*(may take longer depending on shipment times)*

1. **Test for corrosion/water leaks from design.** Can do this by spraying oil, water for leak test, acetic acid for corrosion test.
   
2. **Resize microcontroller for fewer pins** if there is no future plan for adding more capabilities; consider using a tiny ASIC.
   
3. **Critical dimension check** for the length of the chassis.
   
4. **Streamline vendors** for hardware/electronic components.
   
5. **Resize PCB.** Initially wanted to keep the number of layers to 1 for ease of repair and manufacturability, but if space becomes a higher priority then to be considered.
   
6. **Consider sheet metal thickness.** There may be cheaper stainless steel sheets with thicknesses sufficient to allow for the “borrowed toleranced” side walls to flex as the mounting screws tighten. Can be calculated with cantilevered beam analysis for maximum deflection (currently 5mm).
   
7. **Use of component connectors** whenever possible to avoid additional manufacturing labor.
   
8. **Use fewer components if possible.**  Depending on space constraints, this is not always doable.

## Additional References

| Topic                             | Link                                                                                                                                                   |
|-----------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| Fastener Conversion               | [https://docs.clearpathrobotics.com/docs/robots/common/components/fasteners/screw_round_head/](https://docs.clearpathrobotics.com/docs/robots/common/components/fasteners/screw_round_head/)  |
| Stepper Motors with Arduino       | [https://dronebotworkshop.com/stepper-motors-with-arduino/](https://dronebotworkshop.com/stepper-motors-with-arduino/)                                  |
| Arduino Thermistor                | [https://www.electronicwings.com/arduino/thermistor-interfacing-with-arduino-uno](https://www.electronicwings.com/arduino/thermistor-interfacing-with-arduino-uno)                            |
| Arduino Pot                       | [https://docs.arduino.cc/learn/electronics/potentiometer-basics/](https://docs.arduino.cc/learn/electronics/potentiometer-basics/)                      |
| 1.6 mm PCB Thickness Standard      | [https://www.wevolver.com/article/pcbs-thickness-understanding-thickness-variations](https://www.wevolver.com/article/pcbs-thickness-understanding-thickness-variations)                      |
| UL1007 wire temp range of up to 80 deg C | [https://www.awcwire.com/allied-university/informatic/ul-1007-dual-ratings](https://www.awcwire.com/allied-university/informatic/ul-1007-dual-ratings)                                        |
| UL1061 wire temp up to 80 deg C   | [https://www.pololu.com/file/0J611/SS242x.pdf](https://www.pololu.com/file/0J611/SS242x.pdf)                                                           |
| Bending Stress                    | [https://smalltridesign.com/Trimaran-Articles/Stress-calcs.html](https://smalltridesign.com/Trimaran-Articles/Stress-calcs.html)                        |
| SS 304                            | [https://www.matweb.com/search/DataSheet.aspx?MatGUID=4b43bf1211e84673bae1b2b81c7a2c01](https://www.matweb.com/search/DataSheet.aspx?MatGUID=4b43bf1211e84673bae1b2b81c7a2c01)              |
