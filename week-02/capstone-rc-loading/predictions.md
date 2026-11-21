# Week 2 Integrated Capstone — Analytical Predictions

## 1. Purpose

This document records the theoretical calculations and pre-experimental predictions for the Week 2 integrated capstone.

The investigation examines how instrument loading, intentional resistive loading, component tolerances, and electrical constraints affect an RC timing circuit.

All values in this document are **analytical predictions**, not experimental measurements, unless specifically identified as a measured component or supply value.

## 2. Circuit Parameters

| Parameter | Symbol | Value |
|---|---|---:|
| Nominal supply voltage | Vs | 5.000 V |
| Measured supply, initial experiment | Vs | 4.45 V |
| Measured supply, follow-up experiment | Vs | 4.46 V |
| Charging resistor | R1 | 99.2 kΩ |
| Additional load resistor | R2 | 9.95 kΩ |
| Capacitor | C1 | 100 µF |
| Capacitor voltage rating | — | 50 V |
| Nominal DMM input resistance | Rm | 10 MΩ |
| Resistor power rating | — | 0.25 W |
| Required control threshold | Vth | 3.00 V |

The DMM input resistance is modeled as a constant 10 MΩ. Actual meter input resistance and capacitance were not independently verified.

The nominal capacitor value is used in the calculations; actual capacitance was not independently measured.

---

## 3. Problem 1 — Ideal RC Timing

Assume an initially discharged capacitor with no DMM loading and no additional load resistor.

### 3.1 Time Constant

The RC time constant is:

`τ = R1 × C1`

Substituting:

`τ = 99,200 Ω × 100 × 10^-6 F`

**Predicted time constant: 9.920 s**

### 3.2 Voltage at One Time Constant

The ideal charging equation is:

`Vc(t) = Vs × (1 - exp(-t/τ))`

At `t = τ`:

`Vc(τ) = 5.000 × (1 - exp(-1))`

`Vc(τ) = 5.000 × 0.6321206`

**Predicted capacitor voltage: 3.161 V**

### 3.3 Voltage at Five Seconds

`Vc(5) = 5.000 × (1 - exp(-5/9.920))`

**Predicted capacitor voltage: approximately 1.979 V**

### 3.4 Time to Reach 3.00 V

Starting with:

`3.00 = 5.000 × (1 - exp(-t/9.920))`

Rearranging:

`exp(-t/9.920) = 1 - 3.00/5.000 = 0.400`

Taking the natural logarithm:

`-t/9.920 = ln(0.400)`

`t = -9.920 × ln(0.400)`

**Predicted threshold-crossing time: 9.09 s**

### 3.5 Initial Charging Current

At the instant charging begins, the capacitor is uncharged, so the full supply voltage appears across R1.

`I0 = Vs/R1`

`I0 = 5.000/99,200`

`I0 = 0.000050403 A`

**Predicted initial current: 50.4 µA**

### Engineering Interpretation

Kirchhoff's Voltage Law gives:

`Vs = Vr + Vc`

Therefore:

`Vr = Vs - Vc`

As capacitor voltage increases, the resistor voltage decreases.

From Ohm's Law:

`I = Vr/R1`

The charging current therefore decreases as the capacitor approaches its final voltage.

Since:

`I = C × dVc/dt`

the rate of voltage increase also decreases.

The capacitor approaches the supply voltage asymptotically.

---

## 4. Problem 2 — Digital Multimeter Loading

The DMM is connected across the capacitor and modeled as a 10 MΩ resistor.

### 4.1 Effective Resistance

`Rth = R1 || Rm`

`Rth = (R1 × Rm)/(R1 + Rm)`

`Rth = (99.2 × 10,000)/(99.2 + 10,000) kΩ`

**Predicted effective resistance: 98.2256 kΩ**

### 4.2 Loaded Time Constant

`τ_DMM = Rth × C1`

`τ_DMM = 98,225.6 × 100 × 10^-6`

**Predicted time constant: 9.823 s**

### 4.3 Final Capacitor Voltage

The DMM forms a voltage divider with R1.

`V∞ = Vs × Rm/(R1 + Rm)`

`V∞ = 5.000 × 10,000/(99.2 + 10,000)`

**Predicted final voltage: 4.9509 V**

### 4.4 Voltage Loading Error

`Error (%) = [(Vloaded - Videal)/Videal] × 100`

`Error (%) = [(4.9509 - 5.000)/5.000] × 100`

**Predicted steady-state voltage error: −0.982%**

### 4.5 Time to Reach 3.00 V

For the DMM-loaded circuit:

`Vc(t) = V∞ × (1 - exp(-t/τ_DMM))`

Solving for the threshold-crossing time:

`t = -τ_DMM × ln(1 - 3.00/V∞)`

`t = -9.8226 × ln(1 - 3.00/4.9509)`

**Predicted threshold-crossing time: 9.15 s**

### Engineering Interpretation

The DMM slightly decreases the circuit's time constant but also decreases its steady-state voltage.

A smaller time constant indicates a faster approach to the circuit's own final voltage. It does not necessarily imply an earlier crossing of an absolute threshold.

For the nominal 5.000 V supply:

| Configuration | Time constant | Final voltage | Time to 3.00 V |
|---|---:|---:|---:|
| Ideal | 9.920 s | 5.000 V | 9.09 s |
| DMM connected | 9.823 s | 4.9509 V | 9.15 s |

The DMM-loaded circuit reaches the 3.00 V threshold slightly later.

---

## 5. Problem 3 — Additional Resistive Loading

Connect R2 = 9.95 kΩ in parallel with the capacitor while leaving the DMM connected.

### 5.1 Equivalent Load Resistance

`RL = R2 || Rm`

`RL = (9.95 × 10,000)/(9.95 + 10,000) kΩ`

**Predicted load resistance: 9.94011 kΩ**

### 5.2 Final Capacitor Voltage

At steady state, the capacitor behaves as an open circuit.

`V∞ = Vs × RL/(R1 + RL)`

For the nominal 5.000 V supply:

`V∞ = 5.000 × 9.94011/(99.2 + 9.94011)`

**Predicted final voltage at 5.000 V supply: 0.45538 V**

### 5.3 Loaded Time Constant

To find the Thevenin resistance seen by the capacitor, replace the ideal voltage source with a short circuit.

`Rth = R1 || R2 || Rm`

Equivalently:

`Rth = R1 || RL`

**Predicted Thevenin resistance: 9.03480 kΩ**

`τ_loaded = Rth × C1`

**Predicted loaded time constant: 0.90348 s**

### 5.4 Capacitor Voltage at Five Seconds

For the nominal 5.000 V supply:

`Vc(5) = 0.45538 × (1 - exp(-5/0.90348))`

**Predicted voltage at 5 seconds: 0.45358 V**

### 5.5 Threshold Feasibility

For an initially discharged capacitor:

`Vc(t) = V∞ × (1 - exp(-t/τ_loaded))`

For all finite `t ≥ 0`:

`0 ≤ Vc(t) < V∞`

Since:

`V∞ = 0.45538 V < 3.00 V`

**The required 3.00 V threshold cannot be reached.**

The load decreases both the final capacitor voltage and the time constant.

The circuit settles faster but cannot produce the required triggering signal.

---

## 6. Supply-Adjusted Experimental Predictions

The Arduino's measured supply voltage was below the ideal 5.000 V assumed in the analytical exercises.

The predictions below incorporate the measured supply voltages.


### 6.1 Configuration A — DMM Connected, R2 Disconnected

Parameters:

- R1 = 99.2 kΩ
- C1 = 100 µF
- Rm = 10 MΩ
- R2 disconnected
- Effective time constant ≈ 9.823 s

For the initial experiment, using Vs = 4.45 V:

**Predicted steady-state voltage: 4.4063 V**

The predictions below use the nominal DMM-loaded charging model:

`Vc(t) = V∞ × (1 - exp(-t/τ))`

where:

- `V∞ = 4.4063 V`
- `τ = 9.8226 s`
- `Vc(0) = 0 V`

| Time (s) | Predicted Vc (V) |
|---:|---:|
| 0 | 0.000 |
| 5 | 1.758 |
| 10 | 2.814 |
| 15 | 3.449 |
| 20 | 3.831 |
| 30 | 4.198 |
| 40 | 4.331 |
| 50 | 4.379 |
| 60 | 4.396 |

These predictions assume an initially discharged capacitor.

The experimentally measured initial capacitor voltage was 6.6 mV (0.0066 V), a small departure from the zero-voltage assumption.

For a nonzero initial capacitor voltage, the more general charging equation is:

`Vc(t) = V∞ + [Vc(0) - V∞] × exp(-t/τ)`

The measured initial voltage is incorporated into the comparisons documented in `measurements.md`.


### 6.2 Configuration A — Follow-Up Charging Experiment

Using Vs = 4.46 V:

**Predicted steady-state voltage: 4.4162 V**

The measured initial capacitor voltage was 0.0039 V.

For a nonzero initial voltage, use:

`Vc(t) = V∞ + [Vc(0) - V∞] × exp(-t/τ)`

| Time (s) | Predicted Vc (V) |
|---:|---:|
| 0 | 0.0039 |
| 30 | 4.208 |
| 60 | 4.406 |
| 90 | 4.416 |

Values are rounded to three decimal places.

### 6.3 Configuration B — DMM and R2 Connected

Parameters:

- Vs = 4.46 V
- R1 = 99.2 kΩ
- R2 = 9.95 kΩ
- Rm = 10 MΩ
- C1 = 100 µF

**Predicted steady-state voltage: 0.40620 V**

**Predicted time constant: 0.90348 s**

| Time (s) | Predicted Vc (V) |
|---:|---:|
| 0 | 0.0000 |
| 1 | 0.2719 |
| 2 | 0.3618 |
| 3 | 0.3915 |
| 5 | 0.4046 |
| 10 | 0.4062 |
| 20 | 0.4062 |
| 30 | 0.4062 |

The small initial capacitor voltage of approximately 0.1 mV is neglected in this prediction table.

Measurements at 5 seconds and later are primarily useful for verifying the settled voltage; they do not adequately characterize the fast initial transient.

---

## 7. Problem 4 — Component Tolerance Analysis

The following hypothetical tolerances were used:

| Parameter | Nom