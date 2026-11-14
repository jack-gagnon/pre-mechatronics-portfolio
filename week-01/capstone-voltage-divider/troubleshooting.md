
# Troubleshooting Log — Voltage Divider Design and Fault Diagnosis

## Project Information

- Course: Mechatronics Preparatory Course
- Week: 1
- Session: Friday Capstone
- Project: Voltage Divider Design and Fault Diagnosis
- Fault type: Controlled open-circuit fault
- Fault location: Upper connection of R3 at breadboard E54

## 1. Troubleshooting Objective

Investigate how an open circuit in a parallel resistor branch
affects equivalent resistance, current distribution, and output
voltage.

Use calculated predictions and multimeter measurements to:

1. Establish normal operating conditions.
2. Introduce a controlled fault.
3. Identify the resulting electrical changes.
4. Locate and explain the fault.
5. Restore the original circuit.
6. Verify successful recovery.

## 2. Initial Circuit Configuration

The healthy loaded circuit consisted of:

- R1 = 217.8 ohms
- R2 = 328.2 ohms
- R3 = 992 ohms

Circuit topology:

R1 in series with the parallel combination of R2 and R3.

R_total = R1 + (R2 || R3)

The circuit was powered by the Arduino Uno 5 V output.

### Baseline Measurements

| Measurement | Result |
|---|---:|
| Breadboard supply voltage | 4.43 V |
| Loaded equivalent resistance | 465 ohms |
| Loaded output voltage | 2.357 V |

These measurements established the normal operating condition
against which the simulated fault could be compared.

## 3. Controlled Fault Introduction

### Fault Description

The upper lead of R3 was intentionally removed from breadboard
hole E54 while USB power was disconnected.

R3's lower lead remained connected at E58.

This created an open circuit in the R3 branch.

The disconnected lead was kept isolated from other conductors.

### Safety Precautions

- USB power disconnected before modifying wiring.
- Circuit isolated before resistance measurements.
- Motor control circuit remained electrically isolated.
- No intentional short circuits were introduced.
- Circuit inspected before powered voltage measurements.

## 4. Predicted Fault Behavior

Before taking measurements, the following predictions were made:

| Quantity | Predicted Change |
|---|---|
| Equivalent resistance | Increase |
| Current through R1 | Decrease |
| Output voltage | Increase |
| Current through R3 | Decrease to approximately zero |
| Voltage across R2 | Increase |

### Explanation

With R3 disconnected, the lower resistor network no longer
contains two parallel conducting branches.

The remaining circuit consists of R1 and R2 in series.

Removing the R3 branch increases the equivalent resistance
of the network.

At a fixed supply voltage, the increased equivalent resistance
reduces the total circuit current.

Because R1 carries the total current, its voltage drop decreases.

According to Kirchhoff's Voltage Law, the voltage remaining
across R2 consequently increases.

No steady-state current can flow through the disconnected
R3 branch.

## 5. Fault Measurements

### Equivalent Resistance

Predicted resistance:

R_fault = R1 + R2

R_fault = 217.8 + 328.2

R_fault = 546.0 ohms

Measured resistance:

547 ohms

Percent difference:

|547 - 546| / 546 * 100 = 0.183%

### Fault Output Voltage

Measured breadboard supply:

4.43 V

Predicted output:

Vout = Vin * R2 / (R1 + R2)

Vout = 4.43 * 328.2 / 546

Vout approximately 2.663 V

Measured output:

2.668 V

Percent difference:

Approximately 0.193%

### Comparison With Healthy Circuit

| Condition | Equivalent Resistance | Output Voltage |
|---|---:|---:|
| Healthy loaded | 465 ohms | 2.357 V |
| Open-R3 fault | 547 ohms | 2.668 V |

The fault increased the measured output voltage by:

2.668 - 2.357 = 0.311 V

Relative to the healthy loaded output:

0.311 / 2.357 * 100 = 13.19%

The observed changes matched the predicted fault behavior.

## 6. Root-Cause Analysis

The intentional disconnection of R3 removed a parallel current
path from the circuit.

This increased the equivalent resistance of the lower branch
and of the complete network.

The total circuit current decreased, reducing the voltage
drop across R1.

The resulting increase in the voltage across R2 explains
the higher measured output voltage.

The fault was an open circuit, not a short circuit.

## 7. Corrective Action

With USB power disconnected:

1. R3's upper lead was reinserted into E54.
2. R3's lower lead was confirmed at E58.
3. The G54-D54 bridge was verified.
4. The H58-D58 bridge was verified.
5. The motor circuit remained isolated.
6. The restored network was checked using an unpowered
   resistance measurement.

The restored equivalent resistance measured 465 ohms.

## 8. Repair Verification

After the final safety inspection, the restored circuit
was briefly powered for voltage verification.

| Quantity | Result |
|---|---:|
| Restored equivalent resistance | 465 ohms |
| Restored breadboard supply | 4.44 V |
| Restored output voltage | 2.357 V |
| Original healthy output voltage | 2.357 V |

The restored output voltage exactly matched the original
healthy loaded measurement at the recorded precision.

USB power was disconnected afterward.

### Diagnosis Result

PASS — The controlled fault was successfully introduced,
identified, corrected, and verified.

## 9. Unexpected Issues

No unexpected circuit failures or measurement difficulties
were reported during this capstone.

The R3 disconnection was a deliberate training exercise,
not an accidental hardware failure.

## 10. Engineering Lessons

1. An open circuit in a parallel branch increases the
   equivalent resistance of the network.

2. Increasing equivalent resistance reduces total current
   when the supply voltage remains constant.

3. Reduced current through the upper divider resistor
   decreases its voltage drop.

4. An open load can cause the output voltage of a
   resistor divider to increase.

5. Resistance measurements can help detect an open
   circuit when performed with power removed.

6. Voltage measurements can establish whether a fault
   produces the predicted change in operating conditions.

7. Restoring the original measurements provides strong
   evidence that the fault has been correctly repaired.

## 11. Final Status

- Controlled fault diagnosis: Complete
- Root cause: Identified
- Corrective action: Complete
- Recovery verification: Passed
- Circuit restored: Yes
- USB power disconnected: Yes
- Unexpected safety incidents: None reported

The experiment successfully demonstrated systematic
electrical fault diagnosis and repair verification.
