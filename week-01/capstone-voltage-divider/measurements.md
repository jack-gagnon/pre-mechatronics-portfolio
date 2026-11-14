
# Measurements — Week 1 Friday Capstone

## Voltage Divider Design and Fault Diagnosis

**Course:** Mechatronics Preparatory Course  
**Week:** 1  
**Session:** Friday — Integrated Theory and Lab

## 1. Experimental Objectives

This capstone verifies:

1. Ohm's law.
2. Series and parallel equivalent resistance.
3. Voltage-divider operation.
4. Voltage-divider loading.
5. Kirchhoff's Voltage Law (KVL).
6. Controlled open-circuit fault diagnosis.
7. Restoration of normal circuit operation.

## 2. Equipment

- Arduino Uno, USB-powered
- ELEGOO breadboard and jumper wires
- Commercial Electric DMM-8301S
- Alligator clip adapters
- Three 0.25 W axial-lead resistors

The Arduino supplied low-voltage DC power.

All electrical measurements were performed using the external multimeter.

## 3. Component Verification

Resistance measurements were performed with the network unpowered.

| Component | Nominal Value | Measured Value |
|---|---:|---:|
| R1 | 220 Ω | 217.8 Ω |
| R2 | 330 Ω | 328.2 Ω |
| R3 | 1,000 Ω | 992 Ω |

The reported resistor power rating was 0.25 W per component.

## 4. Circuit Configurations

### Configuration A — Unloaded Divider

R1 and R2 connected in series.

Connections:

- R1: H50–H54
- R2: F54–F58
- Arduino 5V: J50
- Arduino GND: J58
- Output node: I54
- Ground reference: I58
- R3: disconnected

Circuit equation:

R_total = R1 + R2

### Configuration B — Loaded Divider

R1 in series with the parallel combination of R2 and R3.

Connections:

- R1: H50–H54
- R2: F54–F58
- R3: E54–E58
- Node A bridge: G54–D54
- Ground bridge: H58–D58
- Arduino 5V: J50
- Arduino GND: J58

Circuit equation:

R_total = R1 + (R2 || R3)

## 5. Equivalent Resistance Verification

### Configuration A

Predicted:

R_total = 217.8 + 328.2

R_total = 546.0 Ω

Measured:

547 Ω

Percent difference:

|547 - 546| / 546 × 100 = 0.183%

### Configuration B

Parallel combination:

R_parallel = (328.2 × 992) / (328.2 + 992)

R_parallel = 246.610 Ω

Total:

R_total = 217.8 + 246.610

R_total = 464.410 Ω

Measured:

465 Ω

Percent difference:

|465 - 464.410| / 464.410 × 100 = 0.127%

### Resistance Summary

| Configuration | Predicted | Measured | Percent Difference |
|---|---:|---:|---:|
| A — Unloaded | 546.000 Ω | 547 Ω | 0.183% |
| B — Loaded | 464.410 Ω | 465 Ω | 0.127% |

## 6. Nominal 5.00 V Predictions

These calculations were made using the measured resistor values and an assumed 5.00 V supply.

| Quantity | Configuration A | Configuration B |
|---|---:|---:|
| Equivalent resistance | 546.000 Ω | 464.410 Ω |
| Total current | 9.158 mA | 10.766 mA |
| R1 voltage drop | 1.995 V | 2.345 V |
| Output voltage | 3.005 V | 2.655 V |
| R2 branch current | 9.158 mA | 8.090 mA |
| R3 branch current | Not connected | 2.677 mA |

The nominal calculations predicted that connecting R3 would lower the output by approximately 0.350 V.

These predictions were documented before powering the circuit.

## 7. Configuration A — Unloaded Measurements

### Supply and Node Measurements

| Measurement | Result |
|---|---:|
| Arduino 5V-to-GND | 4.45 V |
| Breadboard J50-to-GND | 4.43 V |
| Output I54-to-I58 | 2.669 V |

The breadboard voltage of 4.43 V is used for supply-adjusted predictions.

### Supply-Adjusted Output Prediction

Vout = Vin × R2 / (R1 + R2)

Vout = 4.43 × 328.2 / 546

Vout = 2.66287 V

Measured Vout = 2.669 V

Percent difference:

(2.669 - 2.66287) / 2.66287 × 100

= +0.230%

### Inferred R1 Voltage Drop

Using the measured node voltages:

VR1 = Vin - Vout

VR1 = 4.430 - 2.669

VR1 = 1.761 V

This value is inferred from two node measurements.

### Inferred R1 Current

I1 = VR1 / R1

I1 = 1.761 / 217.8

I1 = 8.085 mA

This current was calculated, not directly measured.

### Direct Resistor Voltage Measurements

| Component | Predicted at 4.43 V | Direct Measurement | Percent Difference |
|---|---:|---:|---:|
| R1 | 1.767 V | 1.771 V | +0.219% |
| R2 | 2.663 V | 2.668 V | +0.193% |

The small difference between the inferred and directly measured R1 drops reflects separate measurements taken at different times.

### Kirchhoff's Voltage Law

Measured:

- Supply = 4.430 V
- VR1 = 1.771 V
- VR2 = 2.668 V

KVL residual:

4.430 - 1.771 - 2.668

= -0.009 V

KVL residual = -9 mV

The measured resistor drops exceed the measured supply by 9 mV.

This small residual is consistent with normal experimental variation and non-simultaneous measurements.

## 8. Configuration B — Loaded Measurements

### Supply and Node Measurements

| Measurement | Result |
|---|---:|
| Arduino 5V-to-GND | 4.45 V |
| Breadboard input I50-to-I58 | 4.43 V |
| Loaded output I54-to-I58 | 2.357 V |

### Supply-Adjusted Output Prediction

R_parallel = 246.610 Ω

R_total = 464.410 Ω

Vout = Vin × R_parallel / R_total

Vout = 4.43 × 246.610 / 464.410

Vout = 2.35241 V

Measured Vout = 2.357 V

Percent difference:

(2.357 - 2.35241) / 2.35241 × 100

= +0.195%

### Supply-Adjusted Current Predictions

Total current:

I_total = 4.43 / 464.410

I_total = 9.539 mA

R2 branch current:

I2 = 2.35241 / 328.2

I2 = 7.168 mA

R3 branch current:

I3 = 2.35241 / 992

I3 = 2.371 mA

KCL prediction:

I_total = I2 + I3

9.539 mA ≈ 7.168 mA + 2.371 mA

These are calculated predictions.

Branch currents were not directly measured during this Friday capstone.

### Direct Voltage-Drop Measurements

| Component | Predicted at 4.43 V | Direct Measurement | Percent Difference |
|---|---:|---:|---:|
| R1 | 2.0776 V | 2.081 V | +0.164% |
| R2 | 2.3524 V | 2.350 V | -0.102% |
| R3 | 2.3524 V | 2.350 V | -0.102% |

### KVL Loop 1 — R1 and R2

4.430 - 2.081 - 2.350

= -0.001 V

KVL residual = -1 mV

### KVL Loop 2 — R1 and R3

4.430 - 2.081 - 2.350

= -0.001 V

KVL residual = -1 mV

Both independent KVL loops agree with the supply voltage within 1 mV.

### Parallel Voltage Verification

Measured:

VR2 = 2.350 V

VR3 = 2.350 V

Difference:

VR2 - VR3 = 0.000 V

The parallel branches exhibited equal measured voltage drops.

## 9. Voltage-Divider Loading

Original unloaded output:

2.669 V

Loaded output:

2.357 V

Measured output reduction:

2.669 - 2.357 = 0.312 V

Percentage reduction relative to unloaded output:

0.312 / 2.669 × 100 = 11.69%

### Theoretical Loading at 4.43 V

Predicted unloaded output:

2.66287 V

Predicted loaded output:

2.35241 V

Predicted reduction:

2.66287 - 2.35241

= 0.31046 V

The measured and predicted loading effects agree closely.

### Explanation

Connecting R3 in parallel with R2 decreases the lower network's equivalent resistance.

This reduces the complete circuit's equivalent resistance and increases total current.

The increased current through R1 increases its voltage drop.

Consequently, less voltage remains across the parallel output network.

## 10. Controlled Open-R3 Fault

### Fault Procedure

With USB power disconnected, the upper lead of R3 was removed from E54.

The lower lead remained at E58.

The disconnected lead was kept isolated.

This intentionally created an open circuit in the R3 branch.

### Predicted Effects

| Quantity | Predicted Effect |
|---|---|
| Total equivalent resistance | Increase |
| Total current | Decrease |
| Output voltage | Increase |
| R3 current | Approximately zero |
| R2 voltage | Increase |

### Fault Resistance Measurement

Predicted:

R_fault = R1 + R2

R_fault = 546.0 Ω

Measured:

547 Ω

Percent difference:

0.183%

### Fault Voltage Measurement

Measured supply:

4.430 V

Predicted output:

4.43 × 328.2 / 546

= 2.66287 V

Measured output:

2.668 V

Percent difference:

(2.668 - 2.66287) / 2.66287 × 100

= +0.193%

### Observed Output Recovery

Healthy loaded output:

2.357 V

Open-R3 output:

2.668 V

Increase:

2.668 - 2.357

= 0.311 V

Increase relative to healthy loaded output:

0.311 / 2.357 × 100

= 13.19%

### Comparison With Original Unloaded State

Original unloaded output:

2.669 V

Open-R3 output:

2.668 V

Difference:

2.668 - 2.669

= -0.001 V

The faulted circuit reproduced the original unloaded behavior within 1 mV.

## 11. Restoration and Repair Verification

With power disconnected, R3 was reinserted at E54–E58.

Both parallel-network bridges were inspected.

### Unpowered Resistance Verification

Predicted loaded equivalent resistance:

464.410 Ω

Measured restored resistance:

465 Ω

Percent difference:

0.127%

### Final Powered Measurement

Breadboard supply:

4.44 V

Predicted restored output:

Vout = 4.44 × 246.610 / 464.410

Vout = 2.35772 V

Measured restored output:

2.357 V

Percent difference:

(2.357 - 2.35772) / 2.35772 × 100

= -0.0305%

USB power was disconnected after the final measurement.

## 12. Complete Fault-Diagnosis Sequence

| Circuit Condition | Equivalent Resistance | Output Voltage |
|---|---:|---:|
| Original unloaded | 547 Ω | 2.669 V |
| Healthy loaded | 465 Ω | 2.357 V |
| Open-R3 fault | 547 Ω | 2.668 V |
| Restored loaded | 465 Ω | 2.357 V |

The output returned to exactly the original loaded reading at the recorded precision.

The controlled fault was successfully introduced, identified, corrected, and verified.

## 13. Power Analysis

The following values are calculated predictions using the measured resistor values and nominal 5.00 V supply.

### Configuration A — Unloaded

Total current:

I = 5 / 546

I = 9.1575 mA

R1 power:

P1 = I² × R1

P1 ≈ 18.26 mW

R2 power:

P2 = I² × R2

P2 ≈ 27.52 mW

Total power:

P_total ≈ 45.79 mW

### Configuration B — Loaded

Predicted total current:

I_total = 10.7664 mA

Predicted output:

Vout = 2.65509 V

R1 power:

P1 ≈ 25.25 mW

R2 power:

P2 ≈ 21.48 mW

R3 power:

P3 ≈ 7.11 mW

Total:

P_total ≈ 53.83 mW

Source power:

Ps = 5 × 0.0107664

Ps ≈ 53.83 mW

The calculated source power agrees with the sum of resistor power dissipation.

### Resistor Rating Check

Reported power rating:

0.25 W = 250 mW

Maximum predicted individual resistor dissipation:

27.52 mW

Fraction of rating:

27.52 / 250 × 100

= 11.01%

All calculated resistor dissipations are below the reported ratings.

## 14. Final Verification Summary

| Verification | Experimental Result |
|---|---|
| Unloaded equivalent resistance | 0.183% difference |
| Loaded equivalent resistance | 0.127% difference |
| Unloaded output voltage | +0.230% difference |
| Loaded output voltage | +0.195% difference |
| Unloaded KVL | -9 mV residual |
| Loaded KVL Loop 1 | -1 mV residual |
| Loaded KVL Loop 2 | -1 mV residual |
| Parallel branch voltage equality | 0.000 V difference |
| Loading effect | 0.312 V measured reduction |
| Open-R3 resistance | 0.183% difference |
| Open-R3 output | +0.193% difference |
| Fault recovery | Output increased 0.311 V |
| Final restored resistance | 0.127% difference |
| Final restored output | -0.0305% difference |
| Power conservation | Verified analytically |
| Direct current measurement | Not performed during this capstone |
| Final safety inspection | Passed |
| Final shutdown | USB disconnected |

## 15. Measurement Limitations

The following factors can affect measurement accuracy:

1. Arduino USB supply voltage varies under load.
2. Breadboard contacts and jumper connections have small resistances.
3. Multimeter resolution and accuracy are finite.
4. Voltage measurements were taken sequentially rather than simultaneously.
5. Calculated currents are not independent current measurements.
6. Reported resistor wattage was established from kit specifications.

The observed voltage and resistance discrepancies were small.

No measurement in this record showed a discrepancy greater than 10%.

## 16. Conclusion

The experiment confirmed that resistor-network loading changes the total current and voltage distribution.

Both loaded KVL loops agreed with the measured supply voltage within 1 mV.

Disconnecting R3 increased the measured output from 2.357 V to 2.668 V.

Restoring R3 returned the output to 2.357 V, confirming the diagnosis.

The experiment successfully demonstrated circuit analysis, measurement technique, and controlled electrical fault diagnosis.
