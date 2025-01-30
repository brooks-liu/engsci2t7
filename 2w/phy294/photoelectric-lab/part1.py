import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import linregress

# constants
c = 3.0e8
h_actual = 6.626e-34
e = 1.602e-19

# (Wavelength (nm), Stopping Voltage (V)), infrared was not included because it did not produce a photocurrent
data = {
    "Red": (640, 0.506920),
    "Red-orange": (615, 0.543984),
    "Amber": (590, 0.612666),
    "Green": (535, 0.896813),
    "Cyan": (505, 0.970690),
    "Blue": (455, 1.26891),
    "UV": (390, 1.61444),
}

# convert to frequency
wavelengths = np.array([item[0] for item in data.values()]) * 1e-9  #nm to m
frequencies = c / wavelengths  # f = c / lambda
stopping_voltages = np.array([item[1] for item in data.values()])

# stop voltage uncertainty (from datasheet)
stopping_voltage_uncertainties = 0.0055 * stopping_voltages + 0.0007 * 1

# least squares fit)
slope, intercept, r_value, p_value, std_err = linregress(frequencies, stopping_voltages)

# planck's
h_calculated = slope * e

# work function
Eo_calculated = intercept * e

# threshold frequency
fo_calculated = -intercept / slope

# chi-squared
expected_values = slope * frequencies + intercept
chi_squared = np.sum(((stopping_voltages - expected_values) / stopping_voltage_uncertainties) ** 2)
degrees_of_freedom = len(stopping_voltages) - 2  # 2 parameters (slope and intercept)
reduced_chi_squared = chi_squared / degrees_of_freedom

print(f"Linear Fit: Vstop = ({slope:.3e} ± {std_err:.3e}) * f + ({intercept:.3e})")
print(f"R^2 Value: {r_value**2:.5f}")
print(f"Chi-Squared: {chi_squared:.3f}")
print(f"Reduced Chi-Squared: {reduced_chi_squared:.3f}")

#plot residuals and best fit line
fig, axs = plt.subplots(2, 1, figsize=(8, 8), gridspec_kw={'height_ratios': [3, 1]})

axs[0].errorbar(frequencies, stopping_voltages, yerr=stopping_voltage_uncertainties, fmt='o', label="Data Points", capsize=5)
axs[0].plot(frequencies, slope * frequencies + intercept, linestyle='-', color='r', alpha=0.7, label=f"Best Fit Line (R^2={r_value**2:.3f})")
axs[0].set_xlabel("Frequency (Hz)")
axs[0].set_ylabel("Stopping Voltage (V)")
axs[0].set_title("Stopping Voltage Applied for Zero Current as a Function of the Frequency of Incident Light")
axs[0].legend()
axs[0].grid(True)

# residuals
residuals = stopping_voltages - expected_values
axs[1].errorbar(frequencies, residuals, yerr=stopping_voltage_uncertainties, fmt='o', label="Residuals", capsize=5)
axs[1].axhline(0, color='r', linestyle='--', label="Zero Residual Line")
axs[1].set_xlabel("Frequency (Hz)")
axs[1].set_ylabel("Residuals (V)")
axs[1].grid(True)

plt.tight_layout()
plt.show()