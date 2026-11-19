# Lab 4 — RC Charging, Discharging, and Time-Constant Verification

**Mechatronics Preparatory Course — Week 2**  
**Date:** November 19, 2026  
**Student:** Jack Gagnon  
**Topic:** Capacitors, RC Transients, Measurement Uncertainty, and Instrument Loading

## Overview

This experiment investigated the charging and discharging behavior of a resistor-capacitor (RC) circuit using an Arduino Uno, breadboard, electrolytic capacitor, and digital multimeter.

The objective was to compare measured capacitor voltages against first-order exponential circuit models.

The experiment also examined the effects of measurement loading, capacitor isolation, and experimental timing.

An unexpected discharge behavior prompted a circuit modification using a normally-open pushbutton. A separate timing-reference error was identified and corrected through video review.

The final discharge measurements were consistent with an RC time constant near 10 seconds.

## Learning Objectives

The experiment was designed to demonstrate:

1. Capacitor charge storage and transient behavior.
2. RC charging and discharging equations.
3. Experimental determination of an RC time constant.
4. The influence of digital multimeter input resistance.
5. Measurement uncertainty and instrument limitations.
6. Safe handling and controlled discharge of capacitors.
7. Systematic troubleshooting using experimental evidence.

## Equipment

| Component | Specification |
|---|---|
| Microcontroller | Arduino Uno |
| Breadboard | Solderless breadboard |
| Resistor R1 | 99.2 kΩ, 0.25 W |
| Auxiliary discharge resistor | 9.95 kΩ, 0.25 W |
| Capacitor C1 | 100 µF, 50 V |
| Capacitor type | Polarized electrolytic |
| Multimeter | Commercial Electric DMM-8301S |
| DMM input resistance | Nominal 10 MΩ |
| Switch | Four-terminal normally-open pushbutton |
| Timing equipment | Stopwatch |
| Documentation | Bench photographs, schematics, and video |

## Theory

### RC Time Constant

The time constant describes how quickly a capacitor charges or discharges through a resistance.

\[
\tau=RC
\]

Using the measured resistor and nominal capacitor:

\[
\tau=(99,200)(100\times10^{-6})
\]

\[
\boxed{\tau_{\text{ideal}}=9.920\text{ s}}
\]

### Capacitor Charging

The charging voltage of an initially discharged capacitor is:

\[
V_C(t)=V_S(1-e^{-t/RC})
\]

After one time constant, the capacitor reaches approximately 63.2% of its final voltage.

After five time constants, it reaches approximately 99.3%.

### Capacitor Discharging

For a capacitor discharging through a resistor:

\[
V_C(t)=V_0e^{-t/RC}
\]

After one time constant, approximately 36.8% of the initial voltage remains.

### Instrument Loading

A real digital multimeter has finite input resistance.

When connected across the capacitor, the DMM introduces an additional current path.

The effective discharge resistance is:

\[
R_{\text{effective}}=R_1\parallel R_M
\]

Using a nominal DMM input resistance of 10 MΩ:

\[
R_{\text{effective}}\approx98.225\text{ kΩ}
\]

The predicted meter-loaded time constant is:

\[
\boxed{\tau_{\text{loaded}}\approx9.823\text{ s}}
\]

## Circuit Construction

### Initial Configuration

The original RC circuit used:

| Component | Breadboard connection |
|---|---|
| R1 | H50–H54 |
| Capacitor positive | F54 |
| Capacitor negative | F56 |
| Positive supply | J50 |
| Ground | J56 |
| Voltage measurement | I54 (+) to I56 (−) |

The capacitor's negative polarity stripe was verified at F56.

### Revised Switch-Controlled Configuration

A normally-open pushbutton was introduced into the positive supply path.

| Component | Breadboard connection |
|---|---|
| Pushbutton | E43, F43, E45, F45 |
| Positive supply input | D43 |
| Switch output jumper | D45–J50 |
| R1 | H50–H54 |
| Capacitor positive | F54 |
| Capacitor negative | F56 |
| Ground | J56 |

When pressed, the pushbutton connected the Arduino supply to R1.

When released, the pushbutton opened the positive charging path.

The switch behavior was verified through unpowered continuity and resistance measurements.

### Controlled Discharge

The final discharge experiment used R1 as the discharge resistor.

After opening the charging switch, a temporary jumper connected:

**I50–H56**

This placed R1 across the capacitor.

The experiment was performed with Arduino USB disconnected.

## Experimental Results

### 1. Steady-State Charging Voltage

The capacitor reached approximately:

\[
\boxed{V_C\approx4.41\text{ V}}
\]

The independently measured Arduino supply was approximately 4.45–4.46 V.

Accounting for nominal DMM loading, the predicted steady-state capacitor voltage was approximately 4.411 V.

The measured steady-state voltage was consistent with this prediction.

### 2. Timed Charging Measurements

| Time (s) | Measured capacitor voltage (V) |
|---:|---:|
| 0 | 0.000 |
| 10 | 2.800 |
| 20 | 3.600 |
| 30 | 4.000 |
| 40 | 4.160 |
| 50 | 4.240 |
| 60 | 4.290 |

The measured voltage increased progressively.

The voltage increments decreased as the capacitor approached its steady-state voltage.

The 10-second reading closely matched the theoretical prediction.

Later readings were below the nominal meter-loaded charging curve.

Potential sources of discrepancy included component tolerances, supply variation, capacitor leakage, DMM autoranging, and manual timing uncertainty.

### 3. Pushbutton Isolation Verification

The switch-controlled configuration was independently tested.

| Measurement | Result |
|---|---|
| D43–J50, released | Open |
| D43–J50, pressed | Continuity |
| D43–I54, pressed | 99.2 kΩ |
| D43–I54, released | Open |

After charging the capacitor:

| Observation | Voltage |
|---|---:|
| After approximately 90 s charging | 4.36 V |
| Immediately after switch release | 4.31 V |
| 10 s after switch release | 4.23 V |

The revised circuit retained most of the capacitor's charge after the positive supply path was opened.

### 4. Timed Discharge Measurements

The final discharge was recorded on video.

The discharge jumper was installed at video timestamp **1:14**.

This point was designated as the experimental time origin.

| Time after jumper connection (s) | Measured voltage |
|---:|---:|
| 0 | 2.355 V |
| 10 | 0.787 V |
| 20 | 0.2844 V |
| 30 | 0.1115 V |
| 40 | 0.0433 V |
| 50 | 0.0202 V |
| 60 | 0.0103 V |

The resulting curve was consistent with exponential discharge.

## Experimental Time Constant

The discharge equation was rearranged to estimate the experimental time constant:

\[
\tau=-\frac{t}{\ln(V_C(t)/V_0)}
\]

Using the 30-second observation:

\[
\tau=-\frac{30}{\ln(0.1115/2.355)}
\]

\[
\boxed{\tau_{\text{experimental}}\approx9.83\text{ s}}
\]

### Comparison

| Model | Time constant |
|---|---:|
| Ideal theoretical | 9.920 s |
| Nominal DMM-loaded prediction | 9.823 s |
| Experimental estimate using 30-second reading | Approximately 9.83 s |

The experimental data supported a discharge time constant near 10 seconds.

Individual observations produced somewhat different estimates due to measurement uncertainty and circuit nonidealities.

## Troubleshooting

Two significant diagnostic investigations occurred.

### Capacitor Discharge Following USB Disconnection

The initial configuration allowed the capacitor voltage to fall after Arduino USB power was disconnected.

An unintended discharge path through the Arduino's unpowered circuitry was considered a possible explanation.

The exact internal path was not independently verified.

A normally-open pushbutton was added to interrupt the positive supply connection.

The revised circuit retained most of its charge after the switch was released.

### Incorrect Video Timing Reference

Initial video measurements appeared to indicate a discharge time constant of approximately 1,085 seconds.

Further inspection revealed that the measurements were taken before the discharge jumper was installed.

The recording began at 0:00, but the discharge event occurred at 1:14.

The video was reanalyzed using the jumper connection as time zero.

Corrected measurements produced a response consistent with the predicted approximately 10-second time constant.

This demonstrated the importance of synchronizing recorded measurements with the physical event being investigated.

## Measurement Uncertainty

Potential sources of uncertainty included:

- Electrolytic capacitor tolerance.
- Capacitor leakage.
- DMM accuracy and input resistance.
- DMM autoranging and display response.
- Manual stopwatch timing.
- Video timestamp resolution.
- Resistor and jumper contact resistance.
- Arduino supply variation.

The experiment distinguished between theoretical models, measured observations, and diagnostic hypotheses.

## Safety

The experiment used a low-voltage Arduino supply and current-limiting resistors.

Before power was applied:

- Resistor power ratings were verified.
- Capacitor capacitance and voltage rating were identified.
- Capacitor polarity was verified.
- The circuit was visually inspected.
- Unintended shorts were checked.
- The capacitor's initial voltage was measured.
- A controlled discharge procedure was established.

The capacitor was not intentionally shorted directly.

At the conclusion of the experiment:

- Arduino USB was disconnected.
- The capacitor voltage was verified below 0.05 V.
- The discharge jumper remained installed.
- No outstanding hardware concerns were reported.

See [safety.md](safety.md) for the full safety record.

## Documentation

| File | Description |
|---|---|
| [predictions.md](predictions.md) | Theoretical calculations and predictions |
| [measurements.md](measurements.md) | Experimental measurements and analysis |
| [troubleshooting.md](troubleshooting.md) | Diagnostic investigations and resolutions |
| [safety.md](safety.md) | Electrical safety procedures and verification |

Additional supporting evidence will be organized in the `photos/`, `schematics/`, and `demo/` directories.

## Key Findings

1. The capacitor exhibited the expected qualitative charging behavior.
2. The measured steady-state voltage was consistent with the supply-adjusted, meter-loaded model.
3. The revised pushbutton circuit improved capacitor isolation.
4. The recorded discharge followed an approximately exponential curve.
5. The discharge time constant was approximately 10 seconds.
6. Video review corrected an experimental timing-reference error.
7. Proper circuit isolation and event-based timing were essential to reliable measurements.

## Conclusion

The experiment successfully demonstrated RC charging and discharging using physical components and a digital multimeter.

The measured discharge response was consistent with the theoretical first-order model, with an estimated time constant near 10 seconds.

The laboratory also demonstrated the importance of controlled switching, instrument loading, stored-energy precautions, and systematic troubleshooting.

A key result was the identification and correction of a timing-reference error that initially produced a misleading discharge estimate.

The exercise strengthened both theoretical circuit understanding and practical diagnostic skills relevant to mechatronics and industrial electrical systems.