# Pre-Mechatronics | Engineering Portfolio

**Electrical Systems · Embedded Programming · Motor Control · Industrial Automation**

A collection of hands-on engineering projects documenting my transition into mechatronics, with an emphasis on electrical systems, embedded programming, electromechanical control, and industrial automation.

## About This Portfolio

My academic background is in Economics and Business Administration, with a concentration in Finance, from Northeastern University. After gaining experience in business process improvement, systems analysis, and software development, I decided to pursue a more hands-on engineering discipline.

I'm preparing to study **Mechatronics and Electrical Systems Technology at Gwinnett Technical College**, with the goal of developing the practical and technical skills required to design, troubleshoot, and maintain automated systems.

This repository documents that preparation through structured laboratory exercises, circuit construction, Arduino programming, electrical measurements, and experimental analysis.

My objective is to build a foundation in both the electrical and software components of modern automation systems.

## Technical Focus

| Discipline | Areas of Study |
|---|---|
| Electrical Fundamentals | Ohm's Law, Kirchhoff's Laws, circuit analysis, voltage, current, resistance, and power |
| Digital Electronics | Digital I/O, pull-up and pull-down resistors, switching, and logic |
| Embedded Systems | Arduino, C/C++, GPIO, and PWM |
| Motor Control | DC motors, transistors, H-bridges, direction control, and speed regulation |
| Instrumentation | Multimeter measurements, circuit diagnostics, and experimental validation |
| Industrial Automation | Relays, sensors, motor drives, control circuits, and introductory PLC concepts |

## Projects

### Lab 04 — DC Motor Control Using Arduino and L293D

**Status:** Core experiments completed; refactored controller validation pending.

[View Project](./Lab4_DC_Motor_Control/)

**Objective:** Design and test an Arduino-controlled DC motor circuit capable of bidirectional rotation and variable-speed operation using pulse-width modulation (PWM).

**Hardware:** Arduino Uno, L293D H-bridge, brushed DC motor, ELEGOO breadboard power module, digital multimeter.

**Key accomplishments:**
- Constructed and tested an L293D motor-driver circuit.
- Implemented electronic motor-direction reversal.
- Controlled motor speed using Arduino PWM.
- Measured motor-terminal voltages at four PWM duty cycles.
- Evaluated power-supply stability during motor operation.
- Documented experimental results and practical limitations.

**Experimental results:**

| PWM Duty Cycle | Measured Motor Voltage |
|---|---:|
| 25% | 0.364 V |
| 50% | 1.74 V |
| 75% | 2.50 V |
| 100% | 3.39 V |

The experiment demonstrated increasing motor speed and measured terminal voltage with increasing PWM duty cycle. Supply voltage decreased from 5.00 V at standby to 4.94 V during a 75% PWM motor test.

These results also provided practical experience with motor-driver voltage losses and the limitations of DC multimeter measurements on PWM-driven loads.

## Tools & Technologies

**Hardware**
- Arduino Uno
- Breadboards and discrete electronic components
- L293D motor driver
- DC motors, transistors, diodes, and relays
- Digital multimeters and regulated DC power supplies

**Software**
- Arduino IDE
- C/C++
- Python
- Git and GitHub

## Engineering Approach

Each project follows a consistent process:

1. **Understand** — Establish the electrical and physical principles governing the system.
2. **Design** — Develop a circuit or control strategy using the available components.
3. **Build** — Assemble the system and implement its control logic.
4. **Measure** — Collect experimental data using appropriate instruments.
5. **Analyze** — Compare observed behavior with theoretical expectations and investigate discrepancies.
6. **Document** — Record schematics, source code, measurements, limitations, and lessons learned.

The emphasis is on understanding not only *whether a system works*, but *why it behaves as observed*.

## Professional Direction

I'm working toward opportunities in mechatronics, industrial automation, electrical systems, and controls technology.

Areas of particular interest include:

- Industrial controls and PLC programming
- Electromechanical troubleshooting
- Sensors, actuators, and motor-drive systems
- Automated equipment maintenance
- Embedded control and hardware/software integration

My longer-term goal is to combine analytical problem-solving, programming experience, and hands-on engineering skills to contribute to the design, operation, and improvement of automated systems.

---

**Portfolio maintained by Jack Gagnon**

*Projects are documented as learning progresses. Experimental results reflect actual laboratory observations unless otherwise noted.*