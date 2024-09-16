def calculate_force(E, I, delta_max, L):
    # Calculate the applied force P based on deflection
    P = (3 * E * I * delta_max) / (L ** 3)
    return P

def calculate_bending_stress(P, L, h, I):
    # Calculate the maximum bending stress
    c = h / 2  # Distance from the neutral axis to the outermost fiber
    sigma_max = (P * L * c) / I
    return sigma_max

def check_failure(sigma_max, sigma_u):
    # Compare calculated stress with ultimate strength
    if sigma_max > sigma_u:
        return "The beam will fail (ultimate tensile strength exceeded)."
    else:
        return "The beam will not fail (within ultimate tensile strength)."

# Updated inputs
E = 193e9  # Young's modulus in Pa (for 304 stainless steel)
L = 0.0715  # Length of the beam in meters (71.5 mm)
delta_max = 0.005  # Maximum deflection in meters (5 mm)
b = 0.070  # Width of the beam in meters (64.8 mm)
h = 0.06 * 0.0254  # Thickness (height) of the beam in meters (1.5 mm)
sigma_u = 515e6  # Ultimate tensile strength in Pa (515 MPa for 304 stainless steel)

# Link to Matweb material:
# https://www.matweb.com/search/DataSheet.aspx?MatGUID=4b43bf1211e84673bae1b2b81c7a2c01

# Calculate the moment of inertia I for a rectangular cross-section
I = (b * h ** 3) / 12

# Calculate the applied force P
P = calculate_force(E, I, delta_max, L)

# Calculate the maximum bending stress
sigma_max = calculate_bending_stress(P, L, h, I)

# Check if the beam will fail
failure_message = check_failure(sigma_max, sigma_u)

print(f"Applied Force P: {P:.2f} N")
print(f"Maximum Bending Stress: {sigma_max / 1e6:.2f} MPa")
print(f"Tensile Ultimate Strength: {sigma_u / 1e6:.2f} MPa")
print(failure_message)
