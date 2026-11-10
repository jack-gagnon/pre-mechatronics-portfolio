# Lab 01 — Predicted Electrical Values

## Objective

Predict the voltage, current, and power dissipation in a simple DC resistive circuit using Ohm's law and electrical power equations.

## Circuit Configuration

- Power source: Arduino Uno 5 V output
- Resistor: R1, nominal 330 Ω
- Measured resistor resistance: 328.6 Ω
- Circuit: Arduino 5V → R1 → Arduino GND

## 1. Initial Predictions (Before Power-Up)

Assume an ideal Arduino supply of 5.00 V.

**Voltage:**

\[
V_R=V_S=5.00\text{ V}
\]

**Current:**

\[
I=\frac{V}{R}
=\frac{5.00}{328.6}
=0.015216\text{ A}
\]

\[
\boxed{I=15.22\text{ mA}}
\]

**Power:**

\[
P=\frac{V^2}{R}
=\frac{5.00^2}{328.6}
=0.07608\text{ W}
\]

\[
\boxed{P=76.08\text{ mW}}
\]

### Initial Prediction Summary

| Quantity | Predicted |
|---|---:|
| Supply voltage | 5.00 V |
| Resistor voltage | 5.00 V |
| Resistance | 328.6 Ω |
| Circuit current | 15.22 mA |
| Resistor power | 76.08 mW |

## 2. Revised Predictions (After Initial Voltage Measurement)

The first voltage measurement across R1 was 4.41 V.

This measurement was obtained before the independent current measurement and was used to update the predictions.

**Revised current:**

\[
I=\frac{4.41}{328.6}
=0.0134206\text{ A}
\]

\[
\boxed{I=13.42\text{ mA}}
\]

**Revised power:**

\[
P=\frac{4.41^2}{328.6}
=0.05918\text{ W}
\]

\[
\boxed{P=59.18\text{ mW}}
\]

### Revised Prediction Summary

| Quantity | Revised prediction |
|---|---:|
| Resistor voltage | 4.41 V |
| Resistance | 328.6 Ω |
| Circuit current | 13.42 mA |
| Resistor power | 59.18 mW |

## 3. Final Voltage-Based Calculation (After Supply Investigation)

Further measurements were taken with the original circuit restored:

- Arduino supply voltage: 4.45 V
- Resistor voltage: 4.42 V

Using 4.42 V across R1:

\[
I=\frac{4.42}{328.6}
=0.013451\text{ A}
\]

\[
\boxed{I=13.45\text{ mA}}
\]

\[
P=\frac{4.42^2}{328.6}
=0.05945\text{ W}
\]

\[
\boxed{P=59.45\text{ mW}}
\]

These calculations describe the later voltage-measurement configuration. They should not be mistaken for predictions recorded before the first power-up.

## 4. Engineering Notes

1. The nominal 5 V supply was not equal to the measured voltage during USB operation.
2. Calculations based on measured component values provide a more realistic basis for predicting circuit behavior.
3. The current measurement required placing the multimeter in series, which can slightly alter circuit behavior.
4. Voltage and current were measured in separate circuit configurations rather than simultaneously.
5. A standard 0.25 W resistor has sufficient nominal power capacity for all the calculated operating points in this experiment.

## Conclusion

The initial theoretical model predicted 15.22 mA using a nominal 5.00 V supply.

After measuring the actual voltage across the resistor, the updated prediction was 13.42 mA.

This illustrates why practical circuit analysis should distinguish between nominal values, measured values, and predictions derived from measurements.