import numpy as np
import matplotlib.pyplot as plt

# data
settings = np.array([1, 2, 3, 4])
stopping_voltages = np.array([0.940478, 0.942780, 0.945039, 0.959013])
photocurrent_voltages = np.array([0.385258, 0.375707, 0.361990, 0.346112])

# convert photocurrent volts to amps
resistance = 100000  # 100kΩ
photocurrents = photocurrent_voltages / resistance

# uncertainties
stopping_voltage_uncertainty = 0.0055 * stopping_voltages + 0.0007 * 1
photocurrent_voltage_uncertainty = 0.0055 * photocurrent_voltages + 0.0007 * 1
photocurrent_uncertainty = photocurrent_voltage_uncertainty / resistance

# stopping voltage
plt.figure(figsize=(8, 5))
plt.errorbar(settings, stopping_voltages, yerr=stopping_voltage_uncertainty, fmt='o-', capsize=5, label="Stopping Voltage")
plt.xlabel("Setting")
plt.ylabel("Stopping Voltage (V)")
plt.title("Stopping Voltage as a Function of Intensity Setting")
plt.legend()
plt.grid(True)
plt.show()

# photocurrent
plt.figure(figsize=(8, 5))
plt.errorbar(settings, photocurrents * 1e3, yerr=photocurrent_uncertainty * 1e3, fmt='o-', capsize=5, label="Photocurrent")
plt.xlabel("Setting")
plt.ylabel("Photocurrent (mA)")
plt.title("Photocurrent as a Function of Intensity Setting")
plt.legend()
plt.grid(True)
plt.show()
