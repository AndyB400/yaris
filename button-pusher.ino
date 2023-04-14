// Libraries
#include <avr/sleep.h>

// Constants
const int P1_IMT_OUTPUT = 0; // iMT
const int P2_DRIVE_OUTPUT = 1; // Drive Mode
const int P3_SS_OUTPUT = 2; // Start Stop
const int BUTTON_PRESS_DELAY = 300;
const int NEXT_OPERATION_DELAY = 200;

void setup() {
  // Setup
  pinMode(P1_IMT_OUTPUT, OUTPUT);
  pinMode(P2_DRIVE_OUTPUT, OUTPUT);
  pinMode(P3_SS_OUTPUT, OUTPUT);
  delay(5000);

  // iMT
  pressButton(P1_IMT_OUTPUT);

  // Drive Mode - Sport / Track
  pressButton(P2_DRIVE_OUTPUT);

  // Start Stop
  pressButton(P3_SS_OUTPUT);

  // Go to sleep
  sleep();
}

void loop() {
  // Nothing to do here as now sleeping
}

/**
 * Simulates a button press for 300 milli seconds and then pauses for 200 miliseconds
 */
void pressButton(int outputPin) {
  digitalWrite(outputPin, HIGH);
  delay(BUTTON_PRESS_DELAY);
  digitalWrite(outputPin, LOW);
  delay(NEXT_OPERATION_DELAY);
}

/**
 *  Puts the device to sleep
 */
void sleep() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
}
