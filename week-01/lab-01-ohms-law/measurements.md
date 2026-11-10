# Lab 01 — Measured vs. Predicted Values

## Objective

Compare theoretically predicted electrical quantities with experimentally measured values to verify Ohm's law and evaluate measurement accuracy.

## 1. Equipment and Circuit Configuration

- Microcontroller: Arduino Uno
- Power source: USB (nominal 5 V)
- Resistor: 330 Ω nominal, 328.6 Ω measured
- Multimeter: Commercial Electric DMM-8301S
- Additional equipment: Breadboard, jumper wires, alligator clip adapters

**Circuit:**

Arduino 5V → R1 (328.6 Ω) → Arduino GND

## 2. Measurement Results

### A. Initial Predictions vs. Measurements

Predictions calculated before applying power:

| Quantity | Predicted | Measured | Difference |
|---|---:|---:|---:|
| Resistance | 330 Ω | 328.6 Ω | 0.42% |
| Supply voltage | 5.00 V | 4.45 V | 11.00% |
| Resistor voltage | 5.00 V | 4.41 V (initial) | 11.80% |
| Circuit current | 15.22 mA | 13.13 mA | 13.71% |
| Resistor power | 76.08 mW | 56.65 mW* | 25.54% |

*Resistor power is calculated from measured current and resistance, not measured directly. Voltage and current readings were obtained in separate circuit configurations.*

### B. Revised Predictions vs. Measurements

After the initial resistor voltage measurement of 4.41 V, the current and power predictions were recalculated.

| Quantity | Revised prediction | Measured / derived | Difference |
|---|---:|---:|---:|
| Resistance | 328.6 Ω | 328.6 Ω | Reference value |
| Resistor voltage | 4.41 V | 4.41 V | Reference value |
| Circuit current | 13.42 mA | 13.13 mA | 2.17% |
| Resistor power | 59.18 mW | 56.65 mW* | 4.27% |

The revised predictions are based on the initial measured voltage. They are not independent predictions of that voltage.

### C. Additional Supply Investigation

A subsequent experiment compared voltage at the Arduino terminals with voltage directly across the resistor.

| Measurement location | Voltage |
|---|---:|
| Arduino 5V-to-GND | 4.45 V |
| Across R1 | 4.42 V |
| Difference | 0.03 V |

Relative difference:

\[
\frac{|4.45-4.42|}{4.45}\times100=0.67\%
\]

The small voltage difference is consistent with minor losses in wiring and connections, although measurement uncertainty may also contribute.

An earlier experiment using barrel-jack power produced an Arduino 5 V rail measurement of 5.02 V. This result was obtained separately and was not part of the present USB-powered measurement series.

## 3. Percentage Difference Calculations

Percentage difference is calculated using:

\[
\%\text{ Difference}=
\frac{|\text{Measured}-\text{Reference}|}
{|\text{Reference}|}\times100
\]

### A. Resistance

\[
\frac{|328.6-330|}{330}\times100
=\boxed{0.42\%}
\]

The measured resistance is consistent with a nominal 330 Ω resistor.

### B. Supply Voltage

\[
\frac{|4.45-5.00|}{5.00}\times100
=\boxed{11.00\%}
\]

The USB-powered Arduino rail was below its nominal voltage.

### C. Current

Using the initial measured resistor voltage:

\[
I_{\text{predicted}}=
\frac{4.41}{328.6}
=13.4206\text{ mA}
\]

Measured current:

\[
I_{\text{measured}}=13.13\text{ mA}
\]

Percentage difference:

\[
\frac{|13.13-13.4206|}{13.4206}\times100
=\boxed{2.17\%}
\]

### D. Power

Predicted resistor power based on 4.41 V:

\[
P_{\text{predicted}}=
\frac{4.41^2}{328.6}
\approx59.18\text{ mW}
\]

Power calculated from measured current:

\[
P_{\text{derived}}=
(0.01313)^2(328.6)
\approx56.65\text{ mW}
\]

Percentage difference:

\[
\frac{|56.65-59.18|}{59.18}\times100
\approx\boxed{4.27\%}
\]

## 4. Sources of Measurement Differences

### Supply Voltage Variation

The largest deviation was the approximately 11% difference between the nominal 5.00 V supply and the measured 4.45 V USB-powered Arduino rail.

Possible contributing factors include:

- USB cable resistance and voltage drop
- USB power-source characteristics
- Voltage drops through Arduino power-path components

The specific cause was not isolated.

### Multimeter Burden Voltage

During current measurements, the multimeter was connected in series with the resistor.

An ammeter introduces a small additional voltage drop, called *burden voltage*, that can reduce circuit current.

This is one possible explanation for the difference between predicted and measured current.

### Contact Resistance

Breadboard contacts, jumper wires, and alligator clips introduce small amounts of electrical resistance.

These effects may contribute to the observed 0.03 V difference between the Arduino terminals and resistor.

### Measurement Uncertainty

The multimeter has finite resolution and accuracy. Readings obtained at different times may also vary because of changing electrical conditions.

## 5. Engineering Conclusions

1. The measured resistor value was within approximately 0.42% of its nominal resistance.

2. The USB-powered Arduino rail measured approximately 11% below its nominal 5 V value.

3. Using the initial measured voltage improved the predicted-current agreement from a 13.71% difference to approximately 2.17%.

4. Power calculated from measured current was approximately 56.65 mW, compared with a revised prediction of 59.18 mW.

5. The results are consistent with Ohm's law within the limits of our measurement procedure.

6. The experiment demonstrates why engineers should distinguish nominal component values, measured quantities, calculated predictions, and measurement uncertainty.

## 6. Final Assessment

**Result: Successful verification of Ohm's law for a simple resistive DC circuit.**

The experiment demonstrated a close relationship between predicted and measured current after accounting for actual operating voltage.

Further investigation would be required to isolate the cause of the USB supply-voltage reduction and quantify the effect of the ammeter's burden voltage.