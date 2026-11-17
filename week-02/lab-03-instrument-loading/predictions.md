# Predictions — Precision DC Measurement and Instrument Loading

## Week 2 — Tuesday Lab 3

All predictions were calculated before powering the circuits.

## 1. Measured Resistor Values

| Component | Nominal | Measured | Power Rating |
|---|---:|---:|---:|
| R1 | 220 Ω | 217.9 Ω | 0.25 W |
| R2 | 330 Ω | 328.3 Ω | 0.25 W |
| R3 | 100 kΩ | 99.2 kΩ | 0.25 W |
| R4 | 10 kΩ | 9.95 kΩ | 0.25 W |

## 2. Assumed Supply

Nominal supply voltage: 5.00 V

Actual USB-powered Arduino voltage will be measured later.

All voltage predictions will be adjusted using the measured
supply before evaluating experimental differences.

## 3. Circuit A — Low-Resistance Divider

R1 = 217.9 Ω
R2 = 328.3 Ω

Rtotal = R1 + R2
Rtotal = 546.2 Ω

I = Vs / Rtotal
I = 5.00 / 546.2
I = 9.154 mA

VR1 = I × R1
VR1 = 1.995 V

Vout = I × R2
Vout = 3.005 V

Rth = (R1 × R2) / (R1 + R2)
Rth = 130.97 Ω

### Power Dissipation

PR1 = I² × R1 = 18.26 mW
PR2 = I² × R2 = 27.51 mW

Total resistor power = 45.77 mW

## 4. Circuit B — Higher-Resistance Divider

R3 = 99,200 Ω
R4 = 9,950 Ω

Rtotal = R3 + R4
Rtotal = 109,150 Ω

I = Vs / Rtotal
I = 5.00 / 109150
I = 45.81 µA

VR3 = I × R3
VR3 = 4.5442 V

Vout = I × R4
Vout = 0.4558 V

Rth = (R3 × R4) / (R3 + R4)
Rth = 9,042.97 Ω

### Power Dissipation

PR3 = I² × R3 = 0.2082 mW
PR4 = I² × R4 = 0.0209 mW

Total resistor power = 0.2290 mW

## 5. Comparison

| Quantity | Circuit A | Circuit B |
|---|---:|---:|
| Equivalent resistance | 546.2 Ω | 109,150 Ω |
| Predicted current | 9.154 mA | 45.81 µA |
| Predicted output | 3.005 V | 0.4558 V |
| Thevenin resistance | 130.97 Ω | 9,042.97 Ω |

Circuit B has substantially higher output resistance.

Therefore, a voltmeter of the same finite input resistance
will produce a larger relative loading effect on Circuit B.

## 6. Instrument Loading Model

The unloaded circuit can be modeled using its Thevenin
equivalent voltage and output resistance.

Vmeasured = Vth × Rmeter / (Rth + Rmeter)

Relative loading error:

Loading error = Rth / (Rth + Rmeter)

Percentage loading error:

Loading error (%) = 100 × Rth / (Rth + Rmeter)

The actual DMM-8301S input resistance must be established
before calculating its expected loading effect.

## Verified DMM-8301S Specifications

Source: Commercial Electric DMM-8301S technical specifications.

DC voltage input resistance: 10 MΩ

DC voltage accuracy:
±(0.5% of reading + 5 digits)

Selected voltage-range specifications:

| Range | Resolution |
|---|---:|
| 4.000 V | 0.001 V |
| 40.00 V | 0.01 V |

### Predicted Loading Errors

Circuit A:

Rth = 130.97 Ω

Loading error = 130.97 / (130.97 + 10,000,000) × 100

Predicted loading error = 0.00131%

Circuit B:

Rth = 9,042.97 Ω

Loading error = 9042.97 / (9042.97 + 10,000,000) × 100

Predicted loading error = 0.09035%

### Circuit B Voltage Disturbance

Nominal unloaded output = 0.455795 V

Expected meter-loaded output = 0.455383 V

Expected reduction = 0.000412 V = 0.412 mV

The expected loading effect is smaller than the meter's
1 mV resolution on its 4.000 V range.

The stated accuracy allowance is also larger than the
predicted loading effect.

Therefore, this experiment can verify the divider's
overall behavior but cannot conclusively resolve the
small loading effect using a single DMM reading.

This limitation must be included in the final analysis.

## 7. Illustrative Meter Loading

These are hypothetical examples, NOT verified specifications
for the DMM-8301S.

| Assumed Meter Input Resistance | Circuit A Loading Error | Circuit B Loading Error |
|---|---:|---:|
| 1 MΩ | 0.0131% | 0.8962% |
| 10 MΩ | 0.00131% | 0.09035% |

The expected effect must be compared against the actual
instrument accuracy and display resolution.

A loading effect smaller than the measurement uncertainty
cannot be claimed as experimentally resolved.

## 8. Safety Verification

- Resistors measured with power disconnected.
- All resistor ratings confirmed as 0.25 W.
- Calculated resistor power remains below rated limits.
- No powered measurements performed before predictions.
- USB power remains disconnected.
- Circuit wiring and final inspection pending.

## 9. Pre-Power Status

Predictions: Complete
Component verification: Complete
Instrument specification verification: Pending
Breadboard assembly: Pending
Final safety inspection: Pending

POWER AUTHORIZATION: NOT YET GRANTED