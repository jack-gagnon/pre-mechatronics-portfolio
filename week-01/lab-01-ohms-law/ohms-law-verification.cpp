
/*
 * Project: Lab 01 - Ohm's Law Verification
 * Course: Mechatronics Preparatory Course
 * Date: November 10, 2026
 *
 * Objective:
 * Verify Ohm's law using a resistor connected
 * across the Arduino Uno's 5V and GND pins.
 *
 * Circuit:
 * Arduino 5V ---- R1 (328.6 ohms) ---- GND
 *
 * Pin Map:
 * -----------------------------------------
 * Arduino 5V  -> R1, terminal A
 * Arduino GND -> R1, terminal B
 *
 * Digital pins: Not used
 * Analog pins:  Not used
 *
 * Equipment:
 * - Arduino Uno
 * - 330-ohm nominal resistor
 * - Breadboard and jumper wires
 * - Digital multimeter
 *
 * Experimental Results:
 * -----------------------------------------
 * Measured resistance:      328.6 ohms
 * Measured voltage:         4.42 V
 * Measured current:         13.13 mA
 * Calculated current:       13.45 mA
 *
 * Note:
 * Voltage and current were measured in
 * separate circuit configurations.
 *
 * Safety:
 * - Disconnect power before rewiring.
 * - Never measure current across supply rails.
 * - Verify resistor power rating.
 *
 * No software control is required.
 */

void setup() {
  // No GPIO configuration is required.
  // The resistor is powered by the 5V rail.
}

void loop() {
  // No repeated software operations are needed.
}
