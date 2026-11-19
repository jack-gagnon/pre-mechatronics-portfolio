
# Lab 4 — RC Charging and Discharging: Measurements

**Course:** Mechatronics Preparatory Course  
**Week:** 2  
**Lab:** 4  
**Date:** November 19, 2026  
**Experiment:** RC Charging, Discharging, and Time-Constant Verification

## 1. Experimental Objectives

This experiment investigated the charging and discharging behavior of an RC circuit.

The primary objectives were to:

1. Observe the transient voltage response of a capacitor.
2. Compare measured charging voltages with exponential predictions.
3. Verify the discharge time constant experimentally.
4. Examine the influence of DMM loading.
5. Identify sources of measurement uncertainty.
6. Demonstrate controlled capacitor discharge.
7. Document the experiment through measurements and video.

## 2. Equipment

| Equipment | Specification |
|---|---|
| Microcontroller | Arduino Uno |
| Breadboard | Solderless breadboard |
| Charging/discharge resistor R1 | 99.2 kΩ |
| Capacitor C1 | 100 µF, 50 V electrolytic |
| Initial discharge resistor R2 | 9.95 kΩ |
| Resistor power rating | 0.25 W |
| Digital multimeter | Commercial Electric DMM-8301S |
| Nominal DMM input resistance | 10 MΩ |
| Switching component | Four-terminal normally-open pushbutton |
| Timing equipment | Stopwatch and video recording device |

## 3. Circuit Configuration

### Initial RC Circuit

| Component | Breadboard placement |
|---|---|
| R1 | H50–H54 |
| C1 positive | F54 |
| C1 negative | F56 |
| Positive supply input | J50 |
| Ground input | J56 |
| Capacitor voltage measurement | I54 (+) to I56 (−) |

The capacitor's negative polarity stripe was verified at F56.

### Revised Pushbutton-Controlled Circuit

Following the initial investigation, a normally-open pushbutton was added.

| Connection | Breadboard placement |
|---|---|
| Pushbutton terminals | E43, F43, E45, F45 |
| Positive supply input | D43 |
| Pushbutton output to R1 | D45–J50 |
| R1 | H50–H54 |
| C1 positive | F54 |
| C1 negative | F56 |
| Ground input | J56 |

The pushbutton was independently tested.

| Test | Result |
|---|---|
| D43–J50, button released | Open |
| D43–J50, button pressed | Continuity |
| D43–I54, button pressed | 99.2 kΩ |
| D43–I54, button released | Open |

These results verified that charging current passed through R1 only when the pushbutton was pressed.

## 4. Theoretical Parameters

### Ideal Time Constant

\[
\tau=RC
\]

\[
\tau=(99,200)(100\times10^{-6})
\]

\[
\boxed{\tau_{\text{ideal}}=9.920\text{ s}}
\]

### DMM-Loaded Time Constant

The nominal 10 MΩ DMM input resistance was modeled in parallel with the capacitor.

\[
R_{\text{effective}}=R_1\parallel R_M
\]

\[
R_{\text{effective}}\approx98.225\text{ kΩ}
\]

\[
\boxed{\tau_{\text{loaded}}\approx9.823\text{ s}}
\]

### Steady-State Voltage

For a DMM connected across the capacitor:

\[
V_\infty=V_S\frac{R_M}{R_1+R_M}
\]

The independent Arduino supply measurement fluctuated between:

\[
4.45\text{ V}\leq V_S\leq4.46\text{ V}
\]

Using the midpoint:

\[
V_S\approx4.455\text{ V}
\]

The predicted steady-state capacitor voltage was:

\[
\boxed{V_\infty\approx4.411\text{ V}}
\]

The supply voltage was measured separately from the charging run. Therefore, this comparison assumes similar supply conditions during the experiment.

## 5. Initial Capacitor Verification

Before the first charging experiment:

| Test | Result |
|---|---|
| Capacitor previously energized | No |
| Initial capacitor voltage | 0.0 mV |
| USB disconnected | Yes |
| Capacitor polarity verified | Yes |
| Final pre-power inspection | Passed |

The capacitor's initial condition was consistent with:

\[
V_C(0)\approx0\text{ V}
\]

## 6. Initial Charging Test

The capacitor was charged through R1 using the Arduino supply.

| Observation | Result |
|---|---|
| Stabilized capacitor voltage | 4.41 V |
| Stabilization period | Approximately 60 s |
| Gradual rise visibly observed | No |
| Unexpected electrical behavior | None |
| USB disconnected afterward | Yes |

The measured final voltage was consistent with the predicted steady-state voltage.

The initial lack of a visible transient response prompted a controlled timed charging experiment.

## 7. Timed Charging Experiment

### Recorded Measurements

| Time (s) | Measured capacitor voltage (V) |
|---:|---:|
| 0 | 0.000 |
| 10 | 2.800 |
| 20 | 3.600 |
| 30 | 4.000 |
| 40 | 4.160 |
| 50 | 4.240 |
| 60 | 4.290 |

The voltage increased progressively, with smaller voltage changes at later times.

### Comparison With Theory

The theoretical meter-loaded charging equation is:

\[
V_C(t)=V_\infty(1-e^{-t/\tau_{\text{loaded}}})
\]

Using:

\[
V_\infty\approx4.411\text{ V}
\]

and:

\[
\tau_{\text{loaded}}\approx9.823\text{ s}
\]

the approximate comparison is:

| Time (s) | Predicted (V) | Measured (V) |
|---:|---:|---:|
| 0 | 0.000 | 0.000 |
| 10 | 2.818 | 2.800 |
| 20 | 3.835 | 3.600 |
| 30 | 4.203 | 4.000 |
| 40 | 4.336 | 4.160 |
| 50 | 4.384 | 4.240 |
| 60 | 4.401 | 4.290 |

The initial charging response agreed closely with theory.

The later measurements were systematically lower than the modeled values.

Potential causes include:

- Supply-voltage variation.
- Capacitor tolerance.
- Capacitor leakage.
- DMM autoranging.
- Timing uncertainty.
- Measurement update delays.

A single exponential time constant did not explain every charging observation equally well.

## 8. Supply-Voltage Verification

After the initial charging experiments, the Arduino supply was measured independently.

| Measurement | Result |
|---|---|
| Arduino 5V-to-GND | 4.45–4.46 V |
| Breadboard connected during test | No |
| USB disconnected afterward | Yes |
| Unexpected behavior | None |

The measured supply supported the reasonableness of the 4.41 V steady-state capacitor voltage.

## 9. Initial Discharge Investigation

An initial attempt to preserve capacitor charge by disconnecting USB was unsuccessful.

The capacitor voltage fell toward zero while its electrical connections to the Arduino remained in place.

A subsequent pushbutton-controlled circuit allowed the positive supply path to be opened before USB disconnection.

### Pushbutton Isolation Results

| Measurement | Voltage |
|---|---:|
| Initial voltage, button released | −7.4 mV |
| After approximately 90 s charging | 4.36 V |
| Immediately after releasing button | 4.31 V |
| 10 s after button release | 4.23 V |

The capacitor retained most of its charge after the pushbutton was released.

The 80 mV decrease over 10 seconds was greater than predicted from nominal DMM loading alone.

Possible explanations include capacitor leakage, measurement uncertainty, or other circuit loading.

## 10. Discharge Video and Timing Reference

A video was recorded to document the capacitor discharge.

The temporary discharge jumper connecting I50 to H56 was installed at:

**Video timestamp: 1:14 (74 seconds).**

The original measurements extracted from 0:00–1:00 represented the period before the discharge connection was established.

Those readings were:

| Video time (s) | Capacitor voltage (V) |
|---:|---:|
| 0 | 2.621 |
| 10 | 2.597 |
| 20 | 2.572 |
| 30 | 2.550 |
| 40 | 2.526 |
| 50 | 2.502 |
| 60 | 2.480 |

These readings describe the slow pre-discharge voltage decay.

They must not be used to estimate the time constant of the intended R1 discharge path.

The correct experimental time origin is the moment the discharge jumper makes electrical contact.

## 11. Corrected Timed Discharge Results

### Actual Discharge Measurements

| Video timestamp | Discharge time (s) | Measured voltage |
|---|---:|---:|
| 1:14 | 0 | 2.355 V |
| 1:24 | 10 | 0.787 V |
| 1:34 | 20 | 0.2844 V |
| 1:44 | 30 | 0.1115 V |
| 1:54 | 40 | 0.0433 V |
| 2:04 | 50 | 0.0202 V |
| 2:14 | 60 | 0.0103 V |

The capacitor voltage decreased exponentially after the temporary jumper connected R1 across the capacitor.

### Theoretical Discharge Model

\[
V_C(t)=V_0e^{-t/\tau}
\]

Using:

\[
V_0=2.355\text{ V}
\]

and:

\[
\tau_{\text{loaded}}\approx9.823\text{ s}
\]

the predicted discharge equation is:

\[
\boxed{V_C(t)=2.355e^{-t/9.823}}
\]

### Measured Versus Predicted

| Time (s) | Measured (V) | Predicted (V) | Approx. difference (mV) |
|---:|---:|---:|---:|
| 0 | 2.3550 | 2.3550 | 0 |
| 10 | 0.7870 | 0.851 | −64 |
| 20 | 0.2844 | 0.307 | −23 |
| 30 | 0.1115 | 0.111 | ≈0 |
| 40 | 0.0433 | 0.0402 | +3.1 |
| 50 | 0.0202 | 0.0145 | +5.7 |
| 60 | 0.0103 | 0.0052 | +5.1 |

The discharge measurements were consistent with a first-order exponential response.

## 12. Experimental Time-Constant Calculation

Rearranging the discharge equation:

\[
V_C(t)=V_0e^{-t/\tau}
\]

gives:

\[
\boxed{\tau=-\frac{t}{\ln(V_C(t)/V_0)}}
\]

Using the 30-second reading:

\[
\tau=-\frac{30}{\ln(0.1115/2.355)}
\]

\[
\boxed{\tau_{\text{experimental}}\approx9.83\text{ s}}
\]

Comparison:

| Model | Time constant |
|---|---:|
| Ideal RC | 9.920 s |
| Nominal DMM-loaded | 9.823 s |
| Experimental estimate at 30 s | Approximately 9.83 s |

The 30-second estimate closely agreed with the predicted meter-loaded time constant.

However, individual point estimates differed due to measurement limitations and experimental nonidealities.

The supported conclusion is that the circuit exhibited a discharge time constant near 10 seconds.

## 13. Measurement Uncertainty

Potential sources of uncertainty included:

1. Stopwatch synchronization with jumper contact.
2. DMM autoranging and display response.
3. Capacitor capacitance tolerance.
4. Capacitor leakage current.
5. Resistor and jumper contact resistance.
6. Supply-voltage variation.
7. DMM input resistance and voltage accuracy.
8. Video timestamp and frame-selection uncertainty.

Low-voltage measurements near the end of discharge are especially sensitive to small absolute errors.

The close agreement of one time-constant estimate does not establish the overall measurement uncertainty.

## 14. Troubleshooting Summary

Three important observations occurred:

### Observation A — Charging Response Not Initially Visible

The initial charging test reached approximately 4.41 V, but the transient rise was not clearly observed.

A later timed charging run confirmed a gradual increase.

### Observation B — Capacitor Lost Charge After USB Disconnection

Disconnecting USB did not immediately isolate the capacitor from the Arduino circuitry.

A pushbutton was added to open the positive supply path before disconnecting power.

The revised circuit retained charge substantially better.

### Observation C — Apparent Extremely Slow Discharge

An initial calculation suggested a discharge time constant of approximately 1,085 seconds.

Video review revealed that the analyzed measurements occurred before the discharge jumper was installed.

After correcting the timing reference, the measured discharge agreed much more closely with the predicted approximately 10-second time constant.

The initial slow-decay estimate must not be reported as the time constant of the R1 discharge circuit.

## 15. Final Safety Verification

At the conclusion of the experiment:

| Safety item | Status |
|---|---|
| Arduino USB | Disconnected |
| Capacitor voltage | Verified below 0.05 V |
| Temporary discharge jumper | Connected between rows 50 and 56 |
| Discharge video | Saved locally |
| Video shows DMM and jumper connection | Confirmed |
| Outstanding hardware concerns | None |

No further powered testing was required.

## 16. Conclusions

The experiment demonstrated:

- Capacitor charging through a series resistor.
- Exponential voltage rise toward a steady-state value.
- Exponential discharge through a resistive path.
- The influence of multimeter loading on the theoretical response.
- The importance of capacitor isolation after supply disconnection.
- The importance of establishing the correct experimental time origin.
- Practical limitations of manually timed measurements.

The measured discharge behavior was consistent with a time constant near 10 seconds.

The independently calculated ideal and meter-loaded values were 9.920 s and approximately 9.823 s, respectively.

The experiment reinforced the importance of combining circuit theory, careful measurement, and systematic troubleshooting.
