# Lab 01 — Troubleshooting Log

## Entry 001: Arduino Supply Voltage Below Nominal

**Project:** Ohm's Law Verification  
**Date:** November 10, 2026  
**Status:** Workaround verified; root cause not conclusively isolated

---

## 1. Problem Description

During an Ohm's law verification experiment, the Arduino Uno's nominal 5 V output measured substantially below its expected voltage when powered through USB.

The circuit consisted of one 328.6 Ω resistor connected between the Arduino's 5 V and GND terminals.

**Expected behavior:** Approximately 5.00 V across the resistor.

**Observed behavior:** The initial voltage measurement across the resistor was 4.41 V.

This difference required investigation because it exceeded the laboratory's approximate 10% discrepancy threshold.

## 2. Initial Observations

| Parameter | Value |
|---|---:|
| Nominal supply voltage | 5.00 V |
| Initial resistor voltage | 4.41 V |
| Nominal resistor resistance | 330 Ω |
| Measured resistance | 328.6 Ω |
| Initial current prediction | 15.22 mA |
| Measured current | 13.13 mA |

The measured current was below the initial prediction, consistent with the lower operating voltage.

## 3. Hypotheses

Several possible explanations were considered:

1. **USB power path:** The USB source, cable, or Arduino power-path components could be contributing to a voltage reduction.
2. **Breadboard connections:** Contact resistance or poorly seated jumper wires could be producing a voltage drop between the Arduino and resistor.
3. **Measurement conditions:** Meter loading, instrument uncertainty, or supply changes between measurements could affect readings.
4. **Component tolerance:** The resistor might differ from its nominal value, changing the expected current.

The resistor measured 328.6 Ω, only approximately 0.42% below nominal, making resistor tolerance an unlikely explanation for the large current discrepancy by itself.

## 4. Investigation Procedure

### Test A — Measure the Arduino Supply

With the original resistor circuit connected and powered through USB, voltage was measured directly between the Arduino's 5 V and GND terminals.

**Result: 4.45 V**

This was approximately 11.0% below nominal.

### Test B — Measure Voltage Across the Resistor

Voltage was measured directly across the resistor under the same general circuit configuration.

**Result: 4.42 V**

The difference between the Arduino terminals and resistor was:

\[
\Delta V = 4.45-4.42=0.03\text{ V}
\]

Relative to the Arduino voltage:

\[
\%\text{ Difference}=
\frac{0.03}{4.45}\times100
=0.67\%
\]

This relatively small difference suggests that wiring losses between the Arduino and resistor were not the primary contributor to the reduced supply voltage.

Measurement uncertainty could also account for part of the observed difference.

### Test C — Compare Earlier Barrel-Power Results

In a previous experiment, the Arduino was powered through its barrel-jack input.

The measured 5 V rail voltage under load was:

**5.02 V**

This earlier observation suggested that the supply voltage was sensitive to the power-input configuration.

However, the barrel-powered and USB-powered measurements were not performed as a controlled side-by-side experiment. Differences in power supply, cable, loading, and measurement conditions may have contributed.

The result supports investigating the USB power path but does not independently prove the root cause.

## 5. Corrective Action

Rather than continuing to calculate current from an assumed 5.00 V supply, the actual measured resistor voltage was used.

The revised current prediction was:

\[
I=\frac{V}{R}
\]

\[
I=\frac{4.41}{328.6}
\]

\[
I_{\text{predicted}}=13.42\text{ mA}
\]

The independently measured current was:

\[
I_{\text{measured}}=13.13\text{ mA}
\]

Percentage difference:

\[
\frac{|13.13-13.4206|}{13.4206}\times100
=\boxed{2.17\%}
\]

Using the observed voltage reduced the discrepancy between the current prediction and measurement.

This was a correction to the analytical assumptions, not a physical repair to the supply.

## 6. Results

| Investigation | Finding |
|---|---|
| Resistor tolerance | Approximately 0.42% from nominal |
| USB-powered Arduino voltage | 4.45 V |
| Resistor voltage | 4.42 V in follow-up test |
| Arduino-to-resistor voltage difference | 0.03 V |
| Earlier barrel-powered voltage | 5.02 V |
| Revised current prediction | 13.42 mA |
| Measured current | 13.13 mA |
| Revised current difference | 2.17% |

### Conclusion

The reduced resistor voltage was primarily associated with the low measured Arduino supply voltage, rather than a large voltage drop across the external wiring.

The USB power path is a plausible contributor. The exact source of the voltage reduction remains unverified.

The circuit's observed current was consistent with Ohm's law after using its measured operating voltage.

## 7. Lessons Learned

1. **Do not assume nominal voltage equals measured voltage.** Always verify supply conditions when precision matters.

2. **Measure at multiple locations.** Comparing source and load voltages helps distinguish supply problems from wiring losses.

3. **Separate observations from hypotheses.** A suspected cause is not confirmed until appropriately tested.

4. **Use updated measurements to improve predictions.** Circuit models become more accurate when actual component and operating values are incorporated.

5. **Consider measurement effects.** An ammeter introduces burden voltage, and sequential measurements may not reflect identical operating conditions.

## 8. Future Investigation

To identify the exact cause of the low USB-powered voltage:

- Measure the USB supply voltage under load using a suitable USB power measurement method.
- Repeat the experiment with another known-good USB cable and power source.
- Compare USB and appropriately rated barrel-jack power under matched loading conditions.
- Investigate the Arduino power-path components if the voltage reduction persists.
- Measure the ammeter's burden voltage to quantify its effect on current.

These tests were not performed during this laboratory session and remain optional future work.

---

**Final status:** The analytical discrepancy was resolved by using actual measured voltage. The suspected USB supply-path issue remains open for further investigation.