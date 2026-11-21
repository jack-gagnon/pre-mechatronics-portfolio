# Week 2 Integrated Capstone — Experimental Measurements

## 1. Purpose

This document records the measured electrical quantities, experimental observations, and comparisons with theoretical predictions for the Week 2 integrated capstone.

The investigation evaluates a pushbutton-controlled RC timing circuit under two conditions:

1. A capacitor charged through a 99.2 kΩ resistor while monitored by a digital multimeter.
2. The same circuit with an additional 9.95 kΩ load resistor connected across the capacitor.

Three powered charging tests were conducted:

- **Experiment A1:** Initial unloaded charging experiment.
- **Experiment A2:** Follow-up unloaded charging experiment.
- **Experiment B:** Intentional resistive-loading experiment.

The term *unloaded* means no additional 9.95 kΩ resistor was connected. The DMM remained connected and therefore introduced a nominal finite input resistance.

The purpose of recording these experiments separately is to preserve the integrity of the observations, including the discrepancy found during the initial charging test.

---

## 2. Equipment and Circuit Parameters

| Parameter | Value | Basis |
|---|---:|---|
| Charging resistor, R1 | 99.2 kΩ | Previously measured component |
| Load resistor, R2 | 9.95 kΩ | Measured during capstone |
| Capacitor, C1 | 100 µF | Nominal marking |
| Capacitor voltage rating | 50 V | Component marking |
| DMM input resistance | 10 MΩ | Assumed nominal value |
| Arduino supply, initial test | 4.45 V | Measured |
| Arduino supply, follow-up test | 4.46 V | Measured |
| Arduino supply, loaded test | 4.46 V | Prior measured value used for prediction |
| Control threshold | 3.00 V | Design requirement |
| Resistor power rating | 0.25 W | Assumed rating |

The actual capacitance, DMM input resistance, and resistor tolerances were not independently characterized during this experiment.

All calculated voltages are nominal model predictions.

### Measurement conventions

Voltage readings were taken across the capacitor:

- DMM positive: breadboard I54
- DMM negative: breadboard I56
- Measurement mode: DC voltage

The Arduino USB supply was disconnected before rewiring.

The pushbutton controlled the connection between the supply and charging resistor.

The temporary discharge jumper was removed before each powered charging experiment.

---

## 3. Pre-Power Verification

### 3.1 Initial Hardware Inspection

Before the first charging test, the following conditions were verified:

| Check | Result |
|---|---|
| Arduino USB disconnected | Yes |
| Supply jumper ends disconnected initially | Yes |
| Capacitor voltage | 0.0 mV |
| Capacitor polarity stripe visible | Yes |
| R1 available | Yes |
| R2 available but disconnected | Yes |
| Pushbutton available | Yes |
| DMM operational | Yes |
| Existing RC circuit assembled | Yes |
| Unexpected hardware concerns | None |

### 3.2 Switch and Charging Path Verification

After removing the temporary discharge jumper:

| Measurement | Recorded result |
|---|---:|
| D43–I54, pushbutton released | OL |
| D43–I54, pushbutton pressed | 99.2 kΩ |
| Capacitor voltage I54–I56 | 0.0 mV |

These measurements supported the intended switch-controlled resistance path.

### 3.3 Supply Verification

An initial breadboard supply measurement returned 0.0 V.

Direct measurement at the Arduino pins subsequently confirmed:

**Arduino 5V-to-GND voltage: 4.45 V**

Inspection suggested that the positive supply jumper had initially been placed at D45 instead of D43.

After correcting the connection:

**Supply voltage at D43: 4.45 V**

Further switch-output checks produced:

| Measurement | Result |
|---|---:|
| I50–I56, switch released | −0.1 mV |
| I50–I56, switch pressed | 4.45 V |

The released switch output was effectively near zero during this measurement. Because the node can be floating, this result does not establish that it is always held at 0 V.

The supply and switch measurements supported proceeding with the charging experiment.

---

## 4. Experiment A1 — Initial Charging Test

### 4.1 Objective

Measure the voltage across the capacitor as it charges through R1, without the additional 9.95 kΩ load.

Compare the observed charging curve with the nominal DMM-loaded RC model.

### 4.2 Starting Conditions

| Parameter | Value |
|---|---:|
| Supply voltage | 4.45 V |
| Charging resistor | 99.2 kΩ |
| Capacitor | 100 µF nominal |
| Additional load resistor | Disconnected |
| DMM input resistance | 10 MΩ assumed |
| Initial capacitor voltage | 6.6 mV |
| Temporary discharge jumper | Removed |

The pushbutton was pressed to begin charging.

### 4.3 Theoretical Model

The effective resistance is:

`Rth = R1 || Rm`

`Rth = 98.2256 kΩ`

The nominal time constant is:

`τ = Rth × C1`

**τ = 9.82256 s**

The predicted steady-state voltage is:

`V∞ = Vs × Rm/(R1 + Rm)`

**V∞ = 4.40629 V**

Because the measured initial voltage was not exactly zero, predictions use:

`Vc(t) = V∞ + [Vc(0) - V∞] × exp(-t/τ)`

where:

`Vc(0) = 0.0066 V`

### 4.4 Experimental Results

| Time (s) | Predicted (V) | Measured (V) | Measured − Predicted (V) | Error (%) |
|---:|---:|---:|---:|---:|
| 5 | 1.7617 | 1.160 | −0.6017 | −34.16 |
| 10 | 2.8167 | 2.451 | −0.3657 | −12.98 |
| 15 | 3.4508 | 3.214 | −0.2368 | −6.86 |
| 20 | 3.8320 | 3.674 | −0.1580 | −4.12 |
| 30 | 4.1988 | 4.110 | −0.0888 | −2.11 |
| 40 | 4.3313 | 4.280 | −0.0513 | −1.18 |
| 50 | 4.3792 | 4.310 | −0.0692 | −1.58 |
| 60 | 4.3965 | 4.310 | −0.0865 | −1.97 |

Percentage error is calculated as:

`Error (%) = [(Measured − Predicted)/Predicted] × 100`

Values are rounded independently.

### 4.5 Observations

The capacitor voltage increased monotonically across the recorded sequence, reaching approximately 4.31 V.

However, the measured voltage was lower than the theoretical prediction at every recorded time.

The largest discrepancy occurred at the earliest measurement:

- Predicted voltage at 5 seconds: approximately 1.762 V
- Measured voltage at 5 seconds: 1.160 V
- Difference: approximately −0.602 V

At later times, the discrepancy became smaller, although the final measurements remained below prediction.

The measured voltage was 4.31 V at both 50 and 60 seconds.

### 4.6 Recording Limitation

The demonstration video captured approximately 42 seconds of the initial charging experiment.

The remaining measurements were recorded after repeating the final portion of the experiment.

Therefore, the full table should not be interpreted as a continuously recorded, uninterrupted 60-second charging trace.

The video provides visual evidence of the early charging behavior, while the full numerical record includes measurements gathered outside the recorded interval.

### 4.7 Preliminary Interpretation

Possible sources of discrepancy include:

- Timing synchronization between switch actuation and stopwatch readings.
- Actual capacitance differing from its nominal value.
- Electrical loading or leakage not fully represented by the model.
- Supply variation.
- Differences in how the repeated measurements were obtained.

The available evidence does not identify a unique cause.

In particular, the 4.31 V reading was not treated as proof that the circuit's actual steady-state voltage was 4.31 V.

A separate follow-up experiment was conducted to investigate this issue.

---

## 5. Experiment A2 — Follow-Up Charging Test

### 5.1 Objective

Determine whether the capacitor can approach the predicted DMM-loaded steady-state voltage when charging is maintained for a longer interval.

The follow-up test was designed to distinguish a genuine low steady-state voltage from an apparent plateau observed during the initial experiment.

### 5.2 Starting Conditions

| Parameter | Value |
|---|---:|
| Arduino supply voltage | 4.46 V |
| Charging resistor | 99.2 kΩ |
| Capacitor | 100 µF nominal |
| Additional load resistor | Disconnected |
| DMM input resistance | 10 MΩ assumed |
| Initial capacitor voltage | 0.0039 V |
| Temporary discharge jumper | Removed |

The experiment used the same switch-controlled charging arrangement.

### 5.3 Supply-Adjusted Prediction

Using the measured 4.46 V supply:

`V∞ = 4.46 × 10,000,000/(10,000,000 + 99,200)`

**Predicted steady-state voltage: 4.41619 V**

The nominal DMM-loaded time constant remains:

**τ = 9.82256 s**

Predictions account for the measured initial voltage of 0.0039 V.

### 5.4 Experimental Results

| Time (s) | Predicted (V) | Measured (V) | Difference (V) | Error (%) |
|---:|---:|---:|---:|---:|
| 0 | 0.0039 | 0.0039 | 0.0000 | 0.00 |
| 30 | 4.2081 | 4.170 | −0.0381 | −0.91 |
| 60 | 4.4064 | 4.380 | −0.0264 | −0.60 |
| 90 | 4.4157 | 4.390 | −0.0257 | −0.58 |

The Arduino supply was measured as 4.46 V while the pushbutton remained pressed near the end of the experiment.

### 5.5 Steady-State Comparison

Predicted final voltage:

**4.41619 V**

Measured capacitor voltage at 90 seconds:

**4.390 V**

Difference:

`ΔV = 4.390 − 4.41619`

**ΔV ≈ −0.02619 V**

Relative difference:

`Error = (−0.02619/4.41619) × 100`

**Error ≈ −0.59%**

The 90-second voltage was close to the nominal model's steady-state prediction.

Because the voltage was still being measured at a finite time and no independent long-duration stability assessment was performed, 4.390 V is reported as the 90-second result rather than an independently proven asymptotic voltage.

### 5.6 Engineering Interpretation

The follow-up experiment demonstrated that the capacitor could reach at least 4.39 V under the tested conditions.

This is significantly higher than the 4.31 V plateau suggested by the initial experiment.

The result supports the conclusion that 4.31 V was not a confirmed steady-state limit.

However, it does not establish exactly why the initial measurements differed.

Possible influences include timing, measurement procedure, loading, leakage, and component-value uncertainty.

No single explanation was experimentally isolated.

---

## 6. Controlled Discharge Measurements

### 6.1 Discharge Following Experiment A1

After the initial charging test and USB disconnection:

**Measured residual capacitor voltage: 2.70 V**

The I50–H56 temporary discharge jumper was installed with the pushbutton released and USB disconnected.

The capacitor was discharged through R1.

Final recorded voltage:

**0.0 V**

No unexpected behavior was reported.

### 6.2 Discharge Following Experiment A2

After the follow-up charging test and USB disconnection:

**Measured residual capacitor voltage: 3.65 V**

The same controlled resistor-discharge procedure was performed.

Final recorded voltage:

**0.2 mV**

No unexpected behavior was reported.

### 6.3 Interpretation

The capacitor retained measurable voltage after external power was removed.

This confirmed the need to measure stored voltage and use a controlled discharge path before modifying the circuit.

The nominal resistor-based discharge time constant is approximately 9.92 seconds without meter loading and approximately 9.82 seconds with a nominal 10 MΩ DMM connected.

No timed discharge series was recorded during this capstone, so those time constants remain calculated predictions rather than new experimental measurements.

---

## 7. Experiment B — Intentional Resist