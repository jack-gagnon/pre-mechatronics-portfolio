
# Measurements — Precision DC Measurement and Instrument Loading

## Mechatronics Preparatory Course

- Week: 2
- Session: Tuesday Lab 3
- Topic: Measurement Uncertainty and Instrument Loading
- Instrument: Commercial Electric DMM-8301S
- Power source: Arduino Uno USB-powered 5 V output

## 1. Experimental Objectives

This laboratory investigates:

1. DC voltage-divider operation.
2. Equivalent resistance.
3. Kirchhoff's Voltage Law (KVL).
4. Voltmeter input resistance.
5. Instrument loading.
6. Measurement accuracy and resolution.
7. Measurement repeatability.
8. Experimental uncertainty.

Two resistor-divider networks were constructed and measured.

Circuit A used relatively low resistance values.

Circuit B used higher resistance values.

## 2. Component Measurements

All component resistance measurements were performed with
power disconnected.

| Component | Nominal Resistance | Measured Resistance |
|---|---:|---:|
| R1 | 220 Ω | 217.9 Ω |
| R2 | 330 Ω | 328.3 Ω |
| R3 | 100 kΩ | 99.2 kΩ |
| R4 | 10 kΩ | 9.95 kΩ |

All four resistors were identified as 0.25 W components.

## 3. Multimeter Specifications

Instrument: Commercial Electric DMM-8301S

Published specifications:

- DC voltage input resistance: 10 MΩ
- DC voltage accuracy: ±(0.5% of reading + 5 digits)
  for the ranges used in this experiment
- Nominal 400.0 mV range resolution: 0.1 mV
- Nominal 4.000 V range resolution: 1 mV

The DMM was operated in auto-ranging mode.

A 405.6 mV reading was observed despite being slightly above
the nominal 400.0 mV range. The precise automatic range-switching
threshold was not independently verified.

The reported display readings are preserved as observed.

## 4. Circuit A — Low-Resistance Divider

### Circuit Configuration

R1 = 217.9 Ω
R2 = 328.3 Ω

R1 connected between H50 and H54.

R2 connected between F54 and F58.

Arduino 5 V connected to J50.

Arduino GND connected to J58.

Output measured between I54 and I58.

### Equivalent Resistance

Predicted:

Rtotal = R1 + R2

Rtotal = 217.9 + 328.3

Rtotal = 546.2 Ω

Measured:

0.547 kΩ = 547 Ω

Absolute difference:

547 - 546.2 = 0.8 Ω

Percentage difference:

0.8 / 546.2 × 100 = 0.1465%

### Nominal 5 V Predictions

Total current:

I = 5.00 / 546.2

I = 9.154 mA

R1 voltage:

VR1 = 1.995 V

Output voltage:

Vout = 3.005 V

### Actual Supply Voltage

Measured breadboard supply:

Vs = 4.430 V

### Supply-Adjusted Predictions

Predicted current:

I = 4.430 / 546.2

I approximately 8.111 mA

Predicted output:

Vout = 4.430 × 328.3 / 546.2

Vout = 2.662704 V

Predicted R1 voltage:

VR1 = 4.430 - 2.662704

VR1 = 1.767296 V

### Direct Measurements

| Quantity | Predicted at 4.43 V | Measured |
|---|---:|---:|
| Supply voltage | 4.430 V | 4.430 V |
| R1 voltage | 1.767296 V | 1.770 V |
| R2 voltage | 2.662704 V | 2.668 V |

### Output Percentage Difference

Measured minus predicted:

2.668 - 2.662704 = +0.005296 V

Percentage difference:

0.005296 / 2.662704 × 100

= +0.199%

### R1 Percentage Difference

Measured minus predicted:

1.770 - 1.767296 = +0.002704 V

Percentage difference:

0.002704 / 1.767296 × 100

= +0.153%

### KVL Verification

KVL requires:

Vs - VR1 - VR2 = 0

Using independently measured voltage drops:

4.430 - 1.770 - 2.668

= -0.008 V

KVL residual = -8 mV

Residual relative to supply:

0.008 / 4.430 × 100 = 0.181%

The measured resistor drops exceeded the previously measured
supply by 8 mV.

This residual is consistent with experimental measurement
limitations and non-simultaneous readings.

## 5. Circuit A — Thevenin Resistance

Rth = R1 || R2

Rth = (217.9 × 328.3) / (217.9 + 328.3)

Rth = 130.97 Ω

### Predicted Meter Loading

DMM input resistance:

Rm = 10,000,000 Ω

Loading error:

Rth / (Rth + Rm) × 100

= 0.00131%

The predicted loading effect is much smaller than the
instrument's stated DC voltage accuracy allowance.

Therefore, the Circuit A measurements do not independently
resolve the meter-loading effect.

## 6. Circuit A — Measurement Accuracy Allowance

Measured output:

2.668 V

Published accuracy model:

±(0.5% of reading + 5 digits)

Using the 1 mV display increment:

Percentage contribution:

0.005 × 2.668 = 0.01334 V

Digit contribution:

5 × 0.001 = 0.005 V

Combined accuracy allowance:

±0.01834 V

Approximate interval:

2.64966 V to 2.68634 V

This is an accuracy-limit calculation, not a statistical
confidence interval.

The supply-adjusted theoretical value falls inside this interval.

## 7. Circuit B — Higher-Resistance Divider

### Circuit Configuration

R3 = 99.2 kΩ

R4 = 9.95 kΩ

R3 connected between H50 and H54.

R4 connected between F54 and F58.

Arduino 5 V connected to J50.

Arduino GND connected to J58.

Output measured between I54 and I58.

### Equivalent Resistance

Predicted:

Rtotal = R3 + R4

Rtotal = 99.2 + 9.95

Rtotal = 109.15 kΩ

Measured:

109.2 kΩ

Absolute difference:

109.2 - 109.15 = 0.05 kΩ

= 50 Ω

Percentage difference:

0.05 / 109.15 × 100

= 0.0458%

### Nominal 5 V Predictions

Total current:

I = 5.00 / 109150

I = 45.81 µA

R3 voltage:

VR3 = 4.5442 V

R4 voltage:

VR4 = 0.4558 V

## 8. Circuit B — Actual Supply

Measured supply:

Vs = 4.450 V

### Supply-Adjusted Current

I = 4.450 / 109150

I = 40.77 µA

This current was calculated, not measured directly.

### Predicted Unloaded Output

Vout = Vs × R4 / (R3 + R4)

Vout = 4.450 × 9950 / 109150

Vout = 0.405657 V

= 405.657 mV

### Predicted R3 Voltage

VR3 = 4.450 - 0.405657

VR3 = 4.044343 V

## 9. Circuit B — Thevenin Equivalent

Thevenin voltage:

Vth = 405.657 mV

Thevenin resistance:

Rth = R3 || R4

Rth = (99200 × 9950) / (99200 + 9950)

Rth = 9,042.97 Ω

## 10. Circuit B — Meter Loading Across R4

Meter input resistance:

Rm = 10 MΩ

Predicted measured output:

Vm = Vth × Rm / (Rth + Rm)

Vm = 0.405657 × 10000000 / (10000000 + 9042.97)

Vm = 0.405291 V

= 405.291 mV

### Predicted Loading Disturbance

Unloaded output:

405.657 mV

Meter-loaded output:

405.291 mV

Difference:

405.657 - 405.291

= 0.366 mV

Approximately 0.367 mV using unrounded calculations.

### Relative Loading Error

Loading error:

Rth / (Rth + Rm) × 100

= 0.09035%

## 11. Circuit B — Measured Output

Initial DMM reading:

405.6 mV

Meter mode:

Auto-ranging DC voltage

Predicted meter-loaded output:

405.291 mV

Absolute difference:

405.6 - 405.291

= +0.309 mV

Percentage difference:

0.309 / 405.291 × 100

= +0.076%

The measurement is consistent with the circuit model.

This comparison does not independently establish the exact
voltmeter-loading effect.

## 12. Circuit B — Measurement Accuracy Allowance

Measured output:

405.6 mV

Published accuracy model:

±(0.5% of reading + 5 digits)

Using the observed 0.1 mV display increment:

Percentage contribution:

0.005 × 405.6 = 2.028 mV

Digit contribution:

5 × 0.1 = 0.5 mV

Combined allowance:

±2.528 mV

This calculation assumes the stated accuracy specification
applies under the observed auto-ranging condition.

The predicted meter-loading disturbance of approximately
0.367 mV is smaller than this accuracy allowance.

Therefore, the loading effect was not independently resolved.

## 13. Circuit B — Direct R3 Measurement

Measured R3 voltage:

4.046 V

Predicted R3 voltage without meter loading:

4.044343 V

Difference:

4.046 - 4.044343

= +0.001657 V

= +1.657 mV

### Meter Loading Across R3

When measuring R3, the meter is connected in parallel
with R3 rather than R4.

Loaded upper resistance:

Rupper = R3 || Rm

Rupper = (99200 × 10000000) / (99200 + 10000000)

Rupper = 98,225.60 Ω

Expected voltage across the loaded upper branch:

VR3,meter = 4.45 × 98225.60 / (98225.60 + 9950)

VR3,meter = 4.04069 V

Actual reading:

4.046 V

Difference:

4.046 - 4.04069 = +0.00531 V

The difference is small relative to the meter's stated
accuracy allowance.

## 14. Circuit B — KVL Verification

Measured supply:

4.450 V

Measured R3 voltage:

4.046 V

Measured R4 voltage:

0.4056 V

KVL residual:

4.450 - 4.046 - 0.4056

= -0.0016 V

KVL residual:

-1.6 mV

Residual relative to supply:

0.0016 / 4.450 × 100

= 0.036%

The measured voltage drops sum to 4.4516 V.

The readings were taken sequentially.

Additionally, moving the voltmeter from R4 to R3 changes
which resistor is loaded by the instrument.

Therefore, the KVL residual is an experimental comparison
of non-simultaneous measurements rather than a simultaneous
measurement of an unchanged circuit.

## 15. Circuit B — Repeatability Test

Five consecutive output measurements were collected.

| Trial | Voltage |
|---|---:|
| 1 | 405.9 mV |
| 2 | 405.7 mV |
| 3 | 405.7 mV |
| 4 | 405.8 mV |
| 5 | 405.8 mV |

### Arithmetic Mean

Mean = (405.9 + 405.7 + 405.7 + 405.8 + 405.8) / 5

Mean = 405.78 mV

### Minimum and Maximum

Minimum = 405.7 mV

Maximum = 405.9 mV

### Measurement Range

Range = 405.9 - 405.7

Range = 0.2 mV

### Sample Standard Deviation

s = sqrt(sum((Vi - mean)^2) / (n - 1))

Sum of squared deviations:

0.028 mV²

Sample variance:

0.028 / 4 = 0.007 mV²

Sample standard deviation:

s = 0.0837 mV

### Mean Versus Meter-Loaded Prediction

Mean measurement:

405.780 mV

Predicted meter-loaded voltage:

405.291 mV

Difference:

405.780 - 405.291

= +0.489 mV

Percentage difference:

0.489 / 405.291 × 100

= +0.121%

The readings demonstrated good short-term repeatability.

The sample standard deviation does not represent the
instrument's total measurement uncertainty.

## 16. Circuit A Versus Circuit B

| Verification | Circuit A | Circuit B |
|---|---:|---:|
| Measured equivalent resistance | 547 Ω | 109.2 kΩ |
| Resistance difference | 0.1465% | 0.0458% |
| Measured supply | 4.430 V | 4.450 V |
| Measured lower resistor voltage | 2.668 V | 0.4056 V |
| Measured upper resistor voltage | 1.770 V | 4.046 V |
| KVL residual | -8 mV | -1.6 mV |
| Thevenin resistance | 130.97 Ω | 9.043 kΩ |
| Predicted DMM loading error | 0.00131% | 0.09035% |

Circuit B has substantially higher Thevenin output resistance.

Therefore, its output is more susceptible to loading from
the same 10 MΩ measuring instrument.

## 17. Measurement Limitations

The experiment was subject to:

1. Finite DMM input resistance.
2. Instrument accuracy limits.
3. Display resolution.
4. Possible Arduino USB supply variation.
5. Contact and jumper resistance.
6. Resistor measurement uncertainty.
7. Sequential rather than simultaneous voltage readings.
8. Small changes caused by repositioning the voltmeter.

The predicted loading effect was smaller than the DMM's
calculated accuracy allowance.

Consequently, the experiment cannot independently establish
the exact voltmeter-loading disturbance.

## 18. Troubleshooting Summary

No unexpected wiring faults, component failures, or safety
incidents were reported.

The principal experimental limitation was that the available
instrument could not conclusively resolve the predicted
loading effect.

This limitation and potential improvements are documented
in troubleshooting.md.

## 19. Safety

- Low-voltage DC only.
- Resistors rated at 0.25 W.
- Power disconnected during wiring changes.
- Resistance measured only while unpowered.
- DMM used in DC voltage mode for powered measurements.
- Current-measurement sockets not used across the supply.
- USB disconnected after measurements.
- No unexpected safety incidents reported.

## 20. Final Conclusions

Both voltage dividers produced measurements consistent with
theoretical circuit analysis.

Circuit A demonstrated accurate agreement between predicted
and measured voltage-divider behavior within stated
instrument limitations.

Circuit B demonstrated that higher output resistance makes
a circuit more susceptible to instrument loading.

Five repeated Circuit B measurements showed a narrow range
and low sample standard deviation.

However, excellent repeatability does not establish
absolute accuracy.

The predicted loading effect was smaller than the
instrument's accuracy allowance and therefore could not
be independently resolved.

The laboratory demonstrated the importance of evaluating
instrument capabilities before interpreting measured data.
