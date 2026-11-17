
/*
  MECHATRONICS PREPARATORY COURSE
  Week 2 - Tuesday Lab 3

  Project:
  Precision DC Measurement and Instrument Loading

  --------------------------------------------------
  HARDWARE PIN MAP
  --------------------------------------------------

  Arduino 5V  -> Breadboard J50
  Arduino GND -> Breadboard J58

  No Arduino digital I/O pins are used.
  No Arduino analog inputs are used.

  CIRCUIT A:
  R1: H50 to H54 (217.9 ohms measured)
  R2: F54 to F58 (328.3 ohms measured)

  Output A: I54
  Ground:   I58

  CIRCUIT B:
  R3: H50 to H54 (99,200 ohms measured)
  R4: F54 to F58 (9,950 ohms measured)

  Output B: I54
  Ground:   I58

  Only one circuit is installed at a time.

  --------------------------------------------------
  INSTRUMENT
  --------------------------------------------------

  Commercial Electric DMM-8301S

  Published DC voltage input resistance:
  10,000,000 ohms

  IMPORTANT:

  This sketch performs mathematical calculations only.

  It does not measure the actual circuit voltage.

  All experimental voltages were measured using
  the external digital multimeter.

  --------------------------------------------------
  SAFETY
  --------------------------------------------------

  Disconnect USB power before changing wiring.

  Never measure resistance on a powered circuit.

  Never connect a meter in current mode directly
  across the Arduino 5V and GND connections.
*/

// --------------------------------------------------
// Component values measured before powering
// --------------------------------------------------

const float R1 = 217.9;
const float R2 = 328.3;

const float R3 = 99200.0;
const float R4 = 9950.0;

// Published voltmeter input resistance
const float R_METER = 10000000.0;

// Nominal supply used for initial predictions.
// This is NOT a live voltage measurement.
const float V_NOMINAL = 5.0;

// --------------------------------------------------
// Calculation functions
// --------------------------------------------------

float seriesResistance(float r1, float r2) {
  return r1 + r2;
}

float parallelResistance(float r1, float r2) {
  return (r1 * r2) / (r1 + r2);
}

float voltageDivider(float supply, float upper, float lower) {
  return supply * lower / (upper + lower);
}

float loadingErrorPercent(float theveninResistance,
                          float meterResistance) {
  return 100.0 * theveninResistance /
         (theveninResistance + meterResistance);
}

// --------------------------------------------------
// Setup
// --------------------------------------------------

void setup() {
  Serial.begin(9600);

  Serial.println(F("===================================="));
  Serial.println(F("MECHATRONICS PREPARATORY COURSE"));
  Serial.println(F("Week 2 - Tuesday Lab 3"));
  Serial.println(F("Instrument Loading"));
  Serial.println(F("===================================="));

  Serial.println();

  // Circuit A calculations

  float totalA = seriesResistance(R1, R2);
  float outputA = voltageDivider(V_NOMINAL, R1, R2);
  float theveninA = parallelResistance(R1, R2);

  float loadingA = loadingErrorPercent(
    theveninA,
    R_METER
  );

  Serial.println(F("CIRCUIT A - LOW RESISTANCE"));

  Serial.print(F("Total resistance: "));
  Serial.print(totalA, 2);
  Serial.println(F(" ohms"));

  Serial.print(F("Nominal output: "));
  Serial.print(outputA, 4);
  Serial.println(F(" V"));

  Serial.print(F("Thevenin resistance: "));
  Serial.print(theveninA, 2);
  Serial.println(F(" ohms"));

  Serial.print(F("Predicted loading error: "));
  Serial.print(loadingA, 6);
  Serial.println(F(" %"));

  Serial.println();

  // Circuit B calculations

  float totalB = seriesResistance(R3, R4);
  float outputB = voltageDivider(V_NOMINAL, R3, R4);
  float theveninB = parallelResistance(R3, R4);

  float loadingB = loadingErrorPercent(
    theveninB,
    R_METER
  );

  Serial.println(F("CIRCUIT B - HIGHER RESISTANCE"));

  Serial.print(F("Total resistance: "));
  Serial.print(totalB, 2);
  Serial.println(F(" ohms"));

  Serial.print(F("Nominal output: "));
  Serial.print(outputB, 4);
  Serial.println(F(" V"));

  Serial.print(F("Thevenin resistance: "));
  Serial.print(theveninB, 2);
  Serial.println(F(" ohms"));

  Serial.print(F("Predicted loading error: "));
  Serial.print(loadingB, 6);
  Serial.println(F(" %"));

  Serial.println();

  Serial.println(F("NOTE: Calculations only."));
  Serial.println(F("No live voltage measurements are made."));
  Serial.println(F("Use the DMM for experimental readings."));
}

// --------------------------------------------------
// Main loop
// --------------------------------------------------

void loop() {
  // No automated control or measurements.
}
