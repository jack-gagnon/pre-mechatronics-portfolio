# Lab 4 — RC Charging and Discharging: Safety Record

**Course:** Mechatronics Preparatory Course  
**Week:** 2  
**Lab:** 4  
**Date:** November 19, 2026  
**Experiment:** RC Charging, Discharging, and Time-Constant Verification

## 1. Purpose

This document records the electrical safety precautions, component verification, pre-power inspections, controlled discharge procedures, and final safety status for Lab 4.

The experiment involved a polarized electrolytic capacitor connected to a low-voltage Arduino supply.

Special attention was given to stored electrical energy, capacitor polarity, current limiting, and safe measurement practices.

## 2. Equipment and Component Ratings

| Component | Specification |
|---|---|
| Power source | Arduino Uno nominal 5 V |
| Charging/discharge resistor R1 | 99.2 kΩ |
| Auxiliary discharge resistor R2 | 9.95 kΩ |
| Resistor power ratings | 0.25 W |
| Capacitor C1 | 100 µF |
| Capacitor voltage rating | 50 V |
| Capacitor type | Polarized electrolytic |
| Digital multimeter | Commercial Electric DMM-8301S |
| Switching component | Normally-open pushbutton |

The electrolytic capacitor's negative polarity stripe was identified before installation.

The capacitor had not previously been used in a powered circuit.

## 3. Capacitor Polarity

The capacitor was installed with:

- Positive terminal: F54
- Negative terminal: F56
- Negative polarity stripe: F56

The positive terminal was connected to the charging resistor.

The negative terminal was connected to the circuit ground node.

### Safety Requirement

A polarized electrolytic capacitor must not be connected with reversed polarity.

Incorrect polarity can cause excessive leakage current, heating, pressure buildup, venting, or component failure.

Polarity was verified before each powered configuration.

## 4. Capacitor Voltage Rating

The capacitor was rated for 50 V.

The intended supply voltage was approximately 5 V.

An independent Arduino supply measurement indicated 4.45–4.46 V.

The capacitor's rated voltage therefore exceeded the intended operating voltage.

The experiment did not involve intentionally exceeding the capacitor's voltage rating.

## 5. Initial Charging Current

The charging resistor limited the initial capacitor current.

Using the nominal 5 V supply:

\[
I_0=\frac{V_S}{R}
\]

\[
I_0=\frac{5}{99,200}
\]

\[
\boxed{I_0\approx50.4\text{ µA}}
\]

The initial current was substantially below the current normally associated with the resistor's power limit.

## 6. Maximum Charging Resistor Power

At the beginning of charging, the resistor experiences approximately the full supply voltage.

\[
P_{\max}=\frac{V_S^2}{R}
\]

\[
P_{\max}=\frac{25}{99,200}
\]

\[
\boxed{P_{\max}\approx0.252\text{ mW}}
\]

Resistor rating:

\[
P_{\text{rated}}=250\text{ mW}
\]

Percentage of rated power:

\[
\frac{0.252}{250}\times100\approx0.10\%
\]

The predicted dissipation was comfortably below the verified resistor rating.

## 7. Auxiliary Discharge Resistor Safety

An auxiliary 9.95 kΩ resistor was used to discharge the capacitor safely.

Assuming a maximum capacitor voltage of 5 V:

\[
I_0=\frac{5}{9,950}
\]

\[
\boxed{I_0\approx0.503\text{ mA}}
\]

Maximum initial resistor power:

\[
P_{\max}=\frac{25}{9,950}
\]

\[
\boxed{P_{\max}\approx2.51\text{ mW}}
\]

This was approximately 1.01% of its 250 mW power rating.

The auxiliary resistor provided a controlled current path without directly shorting the capacitor.

## 8. Stored Capacitor Energy

The maximum stored energy at the nominal 5 V operating voltage was:

\[
E=\frac12CV^2
\]

\[
E=\frac12(100\times10^{-6})(5^2)
\]

\[
\boxed{E=1.25\text{ mJ}}
\]

Although this energy is relatively small, the capacitor was treated as potentially charged after power disconnection.

The same precautions become increasingly important with larger capacitors and higher-voltage systems.

## 9. Pre-Power Inspection

The following conditions were verified before the initial powered experiment:

- [x] Resistor value identified.
- [x] Resistor power rating confirmed.
- [x] Capacitor capacitance identified.
- [x] Capacitor voltage rating identified.
- [x] Capacitor polarity verified.
- [x] No unintended shorts observed.
- [x] Breadboard connections inspected.
- [x] DMM configured for DC voltage.
- [x] DMM probes connected across the capacitor.
- [x] Arduino USB disconnected during assembly.
- [x] Initial capacitor voltage measured near zero.
- [x] Discharge resistor and procedure prepared.

Power was applied only after completion of the pre-power inspection.

## 10. Initial Capacitor Voltage Verification

Before the initial charging experiment:

\[
V_C\approx0.0\text{ mV}
\]

After a later controlled discharge and removal of the discharge resistor:

\[
V_C\approx0.3\text{ mV}
\]

These readings were consistent with a discharged initial condition.

Measurements were performed in DC voltage mode.

## 11. Safe Multimeter Configuration

The DMM was configured as follows:

| Connection | Configuration |
|---|---|
| Black lead | COM |
| Red lead | Voltage/resistance input |
| Measurement mode during powered tests | DC voltage |
| Capacitor positive measurement | I54 |
| Capacitor negative measurement | I56 |

Resistance and continuity measurements were performed only with USB disconnected and the relevant circuit unpowered.

The capacitor was discharged before resistance or continuity tests involving its circuit.

The DMM was returned to DC voltage mode before powered measurements.

## 12. Controlled Capacitor Discharge

Capacitors can retain electrical energy after a power source is disconnected.

Therefore, disconnecting USB was not treated as proof that the capacitor was discharged.

The controlled discharge procedure used an appropriately rated resistor.

### Procedure

1. Disconnect Arduino USB power.
2. Isolate the circuit from the Arduino supply where required.
3. Keep the DMM connected across the capacitor in DC voltage mode.
4. Connect the designated discharge resistor across the capacitor.
5. Observe the capacitor voltage decreasing.
6. Verify that the measured voltage is below 0.05 V.
7. Keep the discharge path connected until the circuit is safe to reconfigure.

The capacitor terminals were not intentionally shorted directly together.

### Discharge Acceptance Criterion

\[
\boxed{|V_C|<0.05\text{ V}}
\]

The criterion was verified before circuit reconfiguration and at the conclusion of the experiment.

## 13. Pushbutton-Controlled Charging Circuit

A normally-open pushbutton was introduced to isolate the charging path.

The pushbutton was installed at:

- E43
- F43
- E45
- F45

The supply was connected to D43.

A jumper connected D45 to J50.

The button controlled current flow through R1.

### Verified Electrical Behavior

| Test | Result |
|---|---|
| Button released | Charging path open |
| Button pressed | Charging path closed |
| Series resistance when pressed | 99.2 kΩ |
| Series path when released | Open |

These behaviors were verified with the DMM while USB was disconnected.

### Switching Safety Rules

- The pushbutton was released before disconnecting USB following the controlled charging test.
- The temporary discharge jumper was not installed while charging.
- The pushbutton was not pressed during the discharge experiment.
- The charging path and discharge path were not intentionally enabled simultaneously.

These precautions prevented an unintended alternate current path during the measurements.

## 14. Temporary Discharge Jumper

The final discharge experiment used R1 as the discharge resistor.

The temporary jumper connected:

**I50–H56**

With the pushbutton released, this connected the 99.2 kΩ resistor across the capacitor.

The jumper was installed only after the positive supply path had been opened.

The Arduino USB connection remained disconnected during the recorded discharge.

The jumper was kept connected after the experiment.

## 15. Unexpected Voltage Loss After USB Disconnection

During an early experiment, the capacitor lost most of its charge after USB was disconnected.

This occurred while the circuit remained connected to the Arduino.

The observation indicated that disconnecting USB alone did not reliably isolate the capacitor.

A possible discharge path through the Arduino's unpowered circuitry was considered.

The exact path was not independently confirmed.

The circuit was subsequently revised to use a normally-open pushbutton in series with the positive supply.

The revised circuit retained most of the capacitor's voltage after the button was released.

## 16. Operational Stop Conditions

Power was to be disconnected immediately if any of the following occurred:

- Unexpected heating.
- Unusual odor.
- Capacitor swelling or venting.
- Incorrect capacitor polarity.
- Unexpected short circuit.
- Loose or exposed conductive connections.
- Unexpectedly high voltage.
- Uncontrolled current path.
- Abnormal circuit behavior.

No such hazardous conditions were reported during the experiment.

## 17. Final Bench Condition

At the conclusion of laboratory measurements:

| Safety condition | Final status |
|---|---|
| Arduino USB | Disconnected |
| Capacitor voltage | Verified below 0.05 V |
| Temporary discharge jumper | Connected between rows 50 and 56 |
| Discharge video | Recorded and saved locally |
| DMM readings visible in video | Confirmed |
| Jumper connection visible in video | Confirmed |
| Outstanding hardware concerns | None |

The capacitor was verified discharged before the documentation phase began.

## 18. Safety Lessons Learned

### 18.1 Stored Energy Remains After Power Removal

A capacitor can retain charge after external power is disconnected.

Voltage must be measured directly to establish its condition.

### 18.2 Disconnecting Power Is Not the Same as Isolation

Removing a supply does not necessarily remove every conductive path through connected equipment.

Circuit isolation must be evaluated electrically.

### 18.3 Use Current-Limiting Resistors

The charging and discharge resistors limited current and power dissipation to values below their verified ratings.

### 18.4 Verify Polarized Components Before Energizing

Capacitor polarity and voltage rating were checked before applying power.

### 18.5 Confirm Meter Configuration

The correct DMM function and input sockets must be selected before measuring voltage, resistance, or continuity.

### 18.6 Establish a Safe Final State

The experiment concluded with USB disconnected and the capacitor voltage verified below 0.05 V.

## 19. Final Safety Assessment

**Status: Laboratory testing completed without reported hazardous behavior.**

The circuit was operated using a low-voltage supply, verified component ratings, resistor-limited current, and controlled discharge procedures.

The capacitor was confirmed discharged at the end of the experiment.

No further power application was required.