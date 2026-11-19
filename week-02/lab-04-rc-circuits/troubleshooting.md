
# Lab 4 — RC Charging and Discharging: Troubleshooting

**Course:** Mechatronics Preparatory Course  
**Week:** 2  
**Lab:** 4  
**Date:** November 19, 2026  
**Experiment:** RC Charging, Discharging, and Time-Constant Verification

## 1. Purpose

This record documents unexpected measurements, diagnostic procedures, experimental modifications, and conclusions from the RC charging and discharging laboratory.

Three issues were investigated:

1. The charging response was not initially observed.
2. The capacitor lost its charge after Arduino USB power was disconnected.
3. The initial discharge analysis suggested an unexpectedly long time constant.

Each issue was evaluated using circuit theory, direct measurements, and controlled changes to the experimental configuration.

## 2. Relevant Circuit Parameters

| Parameter | Value |
|---|---|
| Charging/discharge resistor R1 | 99.2 kΩ |
| Capacitor C1 | 100 µF |
| Capacitor voltage rating | 50 V |
| Resistor power rating | 0.25 W |
| Independent Arduino supply measurement | 4.45–4.46 V |
| Nominal DMM input resistance | 10 MΩ |
| Ideal RC time constant | 9.920 s |
| Predicted DMM-loaded time constant | Approximately 9.823 s |

The nominal DMM-loaded time constant was calculated using:

\[
R_{\text{effective}}=R_1\parallel R_M
\]

\[
\tau_{\text{loaded}}=R_{\text{effective}}C
\]

The calculations assume the capacitor's actual capacitance equals its nominal value and the DMM input resistance is 10 MΩ.

---

## 3. Issue A — Charging Response Not Initially Visible

### 3.1 Observed Symptom

During the initial powered charging test, the capacitor reached approximately 4.41 V.

The voltage stabilized after approximately 60 seconds.

However, a gradual increase was not clearly observed.

### 3.2 Expected Behavior

The charging equation is:

\[
V_C(t)=V_S(1-e^{-t/RC})
\]

The theoretical time constant is:

\[
\tau=RC=9.920\text{ s}
\]

With nominal DMM loading:

\[
\tau_{\text{loaded}}\approx9.823\text{ s}
\]

A capacitor initially at 0 V should reach approximately 63.2% of its final voltage after one time constant.

Therefore, the circuit should exhibit a visible voltage rise over several seconds.

### 3.3 Initial Hypotheses

Possible explanations included:

- The DMM was not observed immediately after the charging event began.
- The capacitor retained some charge.
- DMM autoranging or display updates affected observation.
- The actual capacitor capacitance differed from its nominal rating.

These were hypotheses, not confirmed causes.

### 3.4 Diagnostic Procedure

The capacitor was discharged through a verified 9.95 kΩ resistor.

The voltage was measured after discharge and again after removing the discharge resistor.

The capacitor voltage was approximately 0.3 mV before the next charging run.

A stopwatch was then used to record the capacitor voltage at 10-second intervals.

### 3.5 Timed Charging Results

| Time (s) | Measured capacitor voltage (V) |
|---:|---:|
| 0 | 0.000 |
| 10 | 2.800 |
| 20 | 3.600 |
| 30 | 4.000 |
| 40 | 4.160 |
| 50 | 4.240 |
| 60 | 4.290 |

The DMM was observed changing ranges during charging.

### 3.6 Assessment

The second experiment clearly showed a gradual voltage rise with decreasing increments.

This was consistent with the expected qualitative behavior of an RC charging circuit.

The 10-second measurement closely agreed with the theoretical model.

Later measurements were systematically below the nominal meter-loaded prediction.

DMM autoranging may have contributed to observation or timing uncertainty, but it was not established as the sole cause.

### 3.7 Disposition

**Status: Transient charging behavior verified.**

The lack of an initially visible voltage rise was not reproduced during the timed charging experiment.

The exact reason for the initial observation remains unconfirmed.

---

## 4. Issue B — Capacitor Discharged After USB Removal

### 4.1 Observed Symptom

The capacitor was charged to approximately 4.41 V.

After Arduino USB power was disconnected, the measured capacitor voltage began falling toward zero.

The Arduino supply jumpers initially remained connected to the circuit.

Following removal of those jumpers, the DMM displayed approximately −0.5 mV.

The elapsed time before this reading was not precisely established.

### 4.2 Initial Assumption

It was initially assumed that disconnecting USB power would allow the capacitor to retain most of its charge.

However, removing a power source does not necessarily create an open circuit.

Connected equipment may still provide paths for current.

### 4.3 Hypothesis

The capacitor may have discharged through a path involving the Arduino's unpowered circuitry.

A possible path was:

Capacitor positive → R1 → Arduino 5 V rail → internal circuitry → ground.

The exact internal path was not independently measured or proven.

### 4.4 Corrective Action

A normally-open pushbutton was introduced in series with the positive supply connection.

The pushbutton was installed at:

- E43
- F43
- E45
- F45

The supply connection was moved to D43.

A jumper connected D45 to J50, allowing the pushbutton to control the supply path leading to R1.

### 4.5 Switch Verification

The installed pushbutton was tested with USB disconnected.

| Measurement | Result |
|---|---|
| E43–F43, released | Continuity |
| E43–F43, pressed | Continuity |
| E43–E45, released | Open |
| E43–E45, pressed | Continuity |
| D43–J50, released | Open |
| D43–J50, pressed | Continuity |
| D43–I54, pressed | 99.2 kΩ |
| D43–I54, released | Open |

These tests established that the pushbutton interrupted the positive charging path when released.

### 4.6 Controlled Retest

With USB connected, the capacitor was charged by holding the pushbutton for approximately 90 seconds.

The button was then released while USB remained connected.

| Measurement | Voltage |
|---|---:|
| Initial voltage, button released | −7.4 mV |
| After approximately 90 s of charging | 4.36 V |
| Immediately after button release | 4.31 V |
| 10 s after release | 4.23 V |

The capacitor retained most of its voltage following release of the pushbutton.

### 4.7 Assessment

The revised circuit retained charge substantially better during the observation period.

This supports the hypothesis that the initial configuration provided an additional discharge path when USB power was removed.

However, the exact path through the Arduino was not directly characterized.

The measured 80 mV decline during the 10 seconds after release was greater than the reduction predicted from nominal DMM loading alone.

Additional effects may include:

- Capacitor leakage.
- DMM accuracy and display response.
- Other unintended loading.
- Timing uncertainty.

### 4.8 Disposition

**Status: Improved isolation verified.**

Opening the positive charging path with a normally-open pushbutton enabled the capacitor to retain most of its charge for the subsequent discharge experiment.

The exact source of the original rapid voltage loss remains a supported hypothesis rather than a confirmed internal circuit diagnosis.

---

## 5. Issue C — Apparent Discharge Time Constant of Approximately 1,085 Seconds

### 5.1 Observed Symptom

An initial analysis of video readings suggested that the capacitor was discharging far more slowly than expected.

The first extracted measurements were:

| Video time (s) | Measured voltage (V) |
|---:|---:|
| 0 | 2.621 |
| 10 | 2.597 |
| 20 | 2.572 |
| 30 | 2.550 |
| 40 | 2.526 |
| 50 | 2.502 |
| 60 | 2.480 |

Using the first and last readings:

\[
\tau=-\frac{t}{\ln(V_C(t)/V_0)}
\]

\[
\tau=-\frac{60}{\ln(2.480/2.621)}
\]

This produced an estimated time constant of approximately 1,085 seconds.

The value was much closer to the nominal DMM-only discharge time constant:

\[
\tau_{DMM}=R_MC
\]

\[
\tau_{DMM}=(10,000,000)(100\times10^{-6})
\]

\[
\tau_{DMM}=1000\text{ s}
\]

than to the predicted discharge through R1:

\[
\tau_{\text{loaded}}\approx9.823\text{ s}
\]

### 5.2 Initial Hypotheses

Possible explanations included:

- The temporary discharge jumper was missing.
- The jumper did not make reliable contact.
- R1 was not electrically connected across the capacitor.
- The measurements were taken before the discharge connection was established.

### 5.3 Diagnostic Investigation

The discharge video was reviewed.

The temporary jumper had been installed between:

**I50 and H56**

The jumper was inserted at video timestamp:

**1:14 (74 seconds)**

The originally analyzed measurements covered video timestamps:

**0:00–1:00**

Therefore, every reading used in the 1,085-second calculation occurred before the discharge jumper was installed.

### 5.4 Root Cause

**Confirmed cause: Incorrect experimental time reference.**

The video recording began before the electrical discharge event.

The first analysis incorrectly treated video timestamp 0:00 as discharge time zero.

The actual discharge began when the jumper connected rows 50 and 56 at video timestamp 1:14.

The initial 1,085-second estimate therefore described pre-discharge voltage decay, not discharge through the intended 99.2 kΩ resistor.

### 5.5 Corrected Discharge Measurements

The video was reviewed using the jumper connection at 1:14 as the experimental time origin.

| Video timestamp | Discharge time (s) | Measured voltage |
|---|---:|---:|
| 1:14 | 0 | 2.355 V |
| 1:24 | 10 | 0.787 V |
| 1:34 | 20 | 0.2844 V |
| 1:44 | 30 | 0.1115 V |
| 1:54 | 40 | 0.0433 V |
| 2:04 | 50 | 0.0202 V |
| 2:14 | 60 | 0.0103 V |

### 5.6 Corrected Time-Constant Calculation

The discharge equation is:

\[
V_C(t)=V_0e^{-t/\tau}
\]

Rearranging:

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

### 5.7 Comparison

| Parameter | Value |
|---|---:|
| Ideal theoretical time constant | 9.920 s |
| Nominal DMM-loaded time constant | 9.823 s |
| Experimental estimate from 30-second reading | Approximately 9.83 s |

The corrected measurements were consistent with a first-order RC discharge having a time constant near 10 seconds.

The close agreement of the 30-second estimate does not imply that every data point agrees to the same precision.

Individual measurements differed due to timing and voltage-measurement limitations.

### 5.8 Disposition

**Status: Root cause identified and analytical error corrected.**

No failed resistor, faulty capacitor, or defective discharge jumper was established.

The apparent extreme discharge time constant resulted from using timestamps that preceded the electrical discharge event.

---

## 6. Lessons Learned

### 6.1 Distinguish Power Removal From Circuit Isolation

Disconnecting a power source does not necessarily remove every discharge path.

Connected equipment may remain electrically coupled to stored-energy components.

### 6.2 Verify Switch Contacts Electrically

Four-terminal pushbuttons contain internal connections that may not be obvious from their physical layout.

The installed switch was verified with continuity and resistance measurements before power was applied.

### 6.3 Establish a Clear Experimental Time Origin

For transient measurements, the time origin must correspond to the physical event initiating the transient.

In this experiment:

\[
t=0
\]

was the instant the discharge jumper made electrical contact.

It was not the beginning of the video recording.

### 6.4 Preserve Original Measurement Evidence

Retaining the full video allowed the original timing interpretation to be corrected without repeating the powered experiment.

### 6.5 Separate Observations From Explanations

A measured voltage decrease is an observation.

A proposed discharge path is a hypothesis.

A confirmed video timestamp establishing the actual discharge event is direct evidence.

Engineering documentation should distinguish among these categories.

### 6.6 Consider Measurement-System Limitations

The DMM can influence the circuit through its finite input resistance.

Autoranging, display response, resolution, accuracy, and manual timing also affect recorded results.

---

## 7. Final Status

| Item | Status |
|---|---|
| Charging behavior observed | Verified |
| Steady-state voltage | Approximately 4.41 V |
| Pushbutton charging control | Verified |
| Controlled discharge behavior | Verified |
| Experimental discharge time constant | Approximately 10 s |
| Video timing discrepancy | Identified and corrected |
| Arduino USB | Disconnected |
| Final capacitor voltage | Below 0.05 V |
| Discharge jumper | Connected |
| Outstanding hardware concerns | None |

## 8. Conclusion

The experiment demonstrated the importance of systematic fault diagnosis.

The initial charging and discharge observations suggested potential circuit problems. Subsequent measurements and video review clarified the behavior.

The pushbutton improved capacitor isolation, while the corrected discharge timestamps produced measurements consistent with the predicted first-order RC response.

The principal confirmed analytical error was an incorrect time reference.

The experiment reinforced an essential engineering principle:

**Reliable conclusions require both accurate electrical measurements and accurate knowledge of when the circuit's state changed.**
