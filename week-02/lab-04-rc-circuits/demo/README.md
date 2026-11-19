# RC Charging and Discharging — Video Demonstration

**Course:** Mechatronics Preparatory Course  
**Week:** 2  
**Lab:** 4  
**Date:** November 19, 2026  
**Student:** Jack Gagnon

## Demonstration

[Watch the RC Discharge Demonstration](rc-discharge-demo.mp4)

**Video filename:** `rc-discharge-demo.mp4`  
**Duration:** 3 minutes, 8 seconds  
**Format:** MP4 (H.264)  
**File size:** 17,138,279 bytes

## Purpose

This video documents a controlled RC discharge experiment using:

- Arduino Uno
- Breadboard
- 99.2 kΩ resistor
- 100 µF electrolytic capacitor
- Normally-open pushbutton
- Digital multimeter
- Temporary discharge jumper

The objective was to observe capacitor voltage decay and compare the measured response with the theoretical exponential discharge equation.

## Theoretical Model

The capacitor discharge equation is:

\[
V_C(t)=V_0e^{-t/RC}
\]

Using the measured resistor and nominal capacitance:

\[
\tau_{\text{ideal}}=(99,200)(100\times10^{-6})
\]

\[
\boxed{\tau_{\text{ideal}}=9.920\text{ s}}
\]

Accounting for the nominal 10 MΩ DMM input resistance:

\[
R_{\text{effective}}=R_1\parallel R_M
\]

\[
\boxed{\tau_{\text{loaded}}\approx9.823\text{ s}}
\]

## Experimental Timing

The video recording began before the discharge connection was established.

The temporary jumper connecting I50 to H56 was installed at:

**Video timestamp: 1:14**

This connection placed the 99.2 kΩ resistor across the capacitor.

The instant of electrical contact was used as the experimental time origin:

\[
\boxed{t=0\text{ at video timestamp 1:14}}
\]

The video timestamp must not be confused with elapsed discharge time.

## Video Measurement Reference

| Video timestamp | Elapsed discharge time | Measured voltage |
|---|---:|---:|
| 1:14 | 0 s | 2.355 V |
| 1:24 | 10 s | 0.787 V |
| 1:34 | 20 s | 0.2844 V |
| 1:44 | 30 s | 0.1115 V |
| 1:54 | 40 s | 0.0433 V |
| 2:04 | 50 s | 0.0202 V |
| 2:14 | 60 s | 0.0103 V |

The video shows the capacitor voltage decreasing after the discharge path was established.

## Experimental Time Constant

Rearranging the exponential discharge equation:

\[
\tau=-\frac{t}{\ln(V_C(t)/V_0)}
\]

Using the measured voltage at 30 seconds:

\[
\tau=-\frac{30}{\ln(0.1115/2.355)}
\]

\[
\boxed{\tau_{\text{experimental}}\approx9.83\text{ s}}
\]

The experimental estimate agrees closely with the nominal meter-loaded prediction.

Individual observations vary because of measurement uncertainty and nonideal circuit behavior.

## Troubleshooting Significance

An initial interpretation of the video suggested a much longer discharge time constant.

That analysis incorrectly treated video timestamp 0:00 as the beginning of the discharge.

The actual discharge jumper was installed at 1:14.

Reexamining the recording and correcting the time reference resolved the discrepancy.

This demonstrates the importance of synchronizing measured data with the physical event that initiates a transient response.

## Safety

The experiment used a low-voltage Arduino supply and current-limiting resistors.

The capacitor was rated for 50 V.

The circuit was inspected before power was applied.

The pushbutton isolated the positive charging path.

The discharge experiment was conducted with Arduino USB disconnected.

At the conclusion of testing:

- USB was disconnected.
- Capacitor voltage was verified below 0.05 V.
- The temporary discharge jumper remained installed.
- No outstanding hardware concerns were reported.

## Video Verification

The compressed MP4 was tested after conversion.

- [x] Video plays successfully.
- [x] DMM readings remain legible.
- [x] Jumper connection at 1:14 is visible.
- [x] Recorded discharge measurements can be reviewed.
- [x] Compressed MP4 prepared for portfolio publication.

## Related Documentation

- [Lab Overview](../README.md)
- [Predictions](../predictions.md)
- [Measurements](../measurements.md)
- [Troubleshooting](../troubleshooting.md)
- [Safety Record](../safety.md)

## Conclusion

The video provides supporting experimental evidence for the RC discharge measurements.

The corrected data demonstrate an approximately exponential voltage decay with a time constant near 10 seconds.

The recording also documents the resolution of an experimental timing-reference error.