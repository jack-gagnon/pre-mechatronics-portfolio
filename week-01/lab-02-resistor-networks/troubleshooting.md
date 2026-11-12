
# Lab 02 — Troubleshooting Log

**Course:** Mechatronics Preparatory Course
**Week:** 01 — Thursday
**Date:** November 12, 2026

## Issue 1 — Supply Voltage Below Nominal

### Expected behavior

The Arduino Uno's 5V output was initially assumed to provide
5.00 V to the resistor network.

### Observed behavior

- Arduino 5V-to-GND: 4.460 V
- Breadboard J50-to-GND: 4.430 V
- Difference: 0.030 V

The measured voltage was lower than the nominal 5.00 V
assumption.

### Investigation

1. Measured the Arduino supply voltage directly.
2. Measured the voltage at the breadboard input (J50).
3. Compared the readings.
4. Recalculated theoretical circuit values using the
   measured 4.430 V input.
5. Compared revised predictions against experimental
   resistor voltages and currents.

### Findings

The revised predictions agreed much more closely with
the measured electrical behavior.

The observed difference between Arduino 5V and J50
was approximately 0.67% of the Arduino rail voltage.

Possible explanations include:

- USB supply characteristics
- Connection or contact resistance
- Measurement uncertainty
- Small variations in supply voltage between readings

These explanations have not been individually verified.

### Resolution

The circuit calculations were updated to use the
measured supply voltage.

The underlying cause of the low supply voltage
was not conclusively determined.

**Status:** Experimental analysis completed;
root cause remains unconfirmed.

---

## Issue 2 — Current Measurement Differences

### Expected behavior

At a measured breadboard supply voltage of 4.430 V:

- Total current: approximately 9.545 mA
- R2 current: approximately 7.173 mA
- R3 current: approximately 2.372 mA

### Observed behavior

- Total current: 9.41 mA
- R2 current: 7.04 mA
- R3 current: 2.34 mA

All measured currents were slightly below the
theoretical predictions.

### Investigation

Compared measured currents with predictions and
calculated percentage differences.

Verified KCL:

9.41 mA - (7.04 mA + 2.34 mA) = 0.03 mA

Percentage imbalance: approximately 0.319%.

### Findings

The measured currents were consistent with KCL.

Potential contributors to the differences include:

- Ammeter burden voltage
- Supply-voltage variation
- Connection resistance
- Measurement uncertainty

No individual contributor was isolated experimentally.

### Resolution

Documented the measured currents, prediction differences,
and KCL residual.

**Status:** Measurements accepted within experimental
limitations; exact sources of error unconfirmed.

---

## Lessons Learned

1. Nominal voltage is an assumption until verified.
2. Predictions should be updated using measured inputs
   without replacing the original pre-power predictions.
3. Current measurements require inserting the meter
   in series, which may alter circuit conditions.
4. Small KCL and KVL residuals should be calculated
   and reported rather than ignored.
5. Plausible explanations are not confirmed root causes.

## Final Circuit State

All resistors and jumpers were restored to their
original positions.

Arduino USB power was disconnected after testing.
