# Friday Capstone — Video Demonstration

## Project
Week 1 Friday Capstone: Voltage Divider Design and Fault Diagnosis

## Demonstration File
- Filename: voltage-divider-demo.mp4
- Location: demo/voltage-divider-demo.mp4
- Format: H.264 MP4
- Playback verified: Yes

## Objective

Demonstrate how adding or removing a parallel resistance
changes the equivalent resistance, current distribution,
and output voltage of a DC resistor network.

## Circuit Components

| Component | Measured Resistance |
|---|---:|
| R1 | 217.8 Ω |
| R2 | 328.2 Ω |
| R3 | 992 Ω |

Power source: Arduino Uno 5V output.

## Circuit Configurations

### Configuration A — Unloaded Voltage Divider

R1 and R2 connected in series.

Measured output voltage: 2.669 V.

### Configuration B — Loaded Voltage Divider

R1 connected in series with the parallel combination
of R2 and R3.

Measured output voltage: 2.357 V.

### Controlled Fault — Open R3

The upper lead of R3 was intentionally disconnected
while circuit power was removed.

Measured output voltage: 2.668 V.

Measured equivalent resistance: 547 Ω.

### Fault Correction

R3 was reconnected to restore the original circuit.

Measured equivalent resistance: 465 Ω.

Measured restored output voltage: 2.357 V.

## Demonstration Results

| Circuit Condition | Measured Output Voltage |
|---|---:|
| Unloaded divider | 2.669 V |
| Loaded divider | 2.357 V |
| Open-R3 fault | 2.668 V |
| Restored divider | 2.357 V |

The output voltage increased by 0.311 V when R3
was disconnected.

After reconnecting R3, the output returned to its
original loaded value.

## Engineering Explanation

Adding R3 in parallel with R2 decreases the equivalent
resistance of the lower divider network.

This increases the total current through R1, increasing
the voltage drop across R1.

According to Kirchhoff's Voltage Law, the voltage
remaining across the lower network consequently decreases.

Disconnecting R3 reverses these effects.

## Safety

- Circuit operated using the Arduino's low-voltage DC supply.
- Resistors were identified as 0.25 W components.
- Power was disconnected before modifying circuit wiring.
- Resistance measurements were performed only while unpowered.
- The separate motor circuit remained isolated.
- USB power was disconnected after measurements.

## Conclusion

The experiment demonstrated voltage-divider loading,
Kirchhoff's laws, and systematic fault diagnosis.

The successful restoration of the original output
voltage confirmed that the controlled fault had
been correctly identified and corrected.