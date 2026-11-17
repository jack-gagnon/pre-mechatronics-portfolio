
# DC Motor Control — Video Demonstration

## Mechatronics Preparatory Course

- Project: DC Motor Control
- Laboratory: Lab 4
- Topic: PWM Motor Speed Control
- Motor driver: L293D
- Controller: Arduino Uno

## 1. Demonstration File

**Filename:** `dc-motor-control-demo.mp4`

**Location:** `demo/dc-motor-control-demo.mp4`

**Format:** H.264 MP4

**Playback verified:** Yes

## 2. Demonstration Objective

Demonstrate the effect of pulse-width modulation (PWM)
on the operation of a DC fan motor controlled through
an L293D motor-driver integrated circuit.

The demonstration shows the fan rotating under
different PWM duty-cycle conditions.

## 3. Hardware

The experiment uses:

- Arduino Uno
- L293D motor-driver IC
- DC fan motor
- Breadboard and jumper connections
- Appropriate motor power connections

The L293D provides a driver interface between
the Arduino's control signals and the motor.

Exact component connections and electrical measurements
are documented in the main laboratory project.

## 4. PWM Operating Principle

Pulse-width modulation controls the proportion of
time a switching signal remains HIGH during each cycle.

Duty cycle is defined as:

Duty Cycle = (ON Time / Total Period) × 100%

For example:

| Duty Cycle | Idealized ON-Time Fraction |
|---|---:|
| 25% | 0.25 |
| 50% | 0.50 |
| 75% | 0.75 |
| 100% | 1.00 |

These percentages illustrate PWM operation; they are
not a claim that these exact settings all appear
in the recording.

For a fixed PWM frequency, increasing duty cycle
increases the proportion of time the motor receives
the switched drive voltage.

Motor behavior also depends on mechanical load,
driver voltage drop, motor characteristics,
and the power supply.

## 5. Demonstrated Behavior

The video shows the fan rotating through multiple
PWM duty-cycle settings.

The demonstration provides visual evidence of the
motor's response to changes in the PWM control signal.

The video does not, by itself, establish an exact
relationship between duty cycle and rotational speed.

Quantitative speed verification would require an
appropriate measurement method, such as a tachometer
or suitable speed sensor.

## 6. Role of the L293D

The L293D is a motor-driver integrated circuit.

It allows low-power control signals from a
microcontroller to control a motor through
dedicated driver outputs.

The driver is necessary because a motor may require
more current than an Arduino digital I/O pin
can safely supply directly.

The driver also introduces voltage losses that
must be considered when analyzing motor behavior.

## 7. Engineering Significance

This experiment introduces principles relevant to
industrial motor control:

1. Digital control of electrical loads.
2. Pulse-width modulation.
3. Separation of control and load circuits.
4. Motor-driver interfaces.
5. Changes in motor behavior as PWM duty cycle varies.

These concepts provide a foundation for later
studies of motor drives, automation, and
mechatronic control systems.

## 8. Safety Considerations

- Motor current must not be supplied directly
  through an Arduino digital I/O pin.
- Driver and supply connections must follow
  the L293D circuit design.
- Motor supply voltage and current must remain
  within applicable component ratings.
- Power must be disconnected before changing wiring.
- The motor and fan blades must remain clear
  of fingers, loose wiring, and other obstructions.
- The driver may become warm during operation.
- Motor power and logic power connections must
  be verified before energizing the circuit.

## 9. Demonstration Limitations

The recording provides qualitative visual evidence
of fan operation at different PWM duty cycles.

It does not independently establish:

- Exact motor rotational speed.
- Motor torque.
- Motor current.
- Mechanical output power.
- Driver efficiency.

Those quantities require additional measurements.

## 10. Conclusion

The video demonstrates control of a DC fan motor
using PWM and an L293D motor-driver circuit.

The observed motor operation provides practical
evidence of the relationship between PWM duty-cycle
settings and motor behavior.

The experiment supports further study of motor
drivers, switching circuits, and automated
control systems.
