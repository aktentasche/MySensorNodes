#define MY_DEBUG

#define MY_RADIO_NRF24
#include <MySensors.h>
#include <Arduino.h>
#include <NewPing.h>

#define NODEID 151
#define PIN_ULTRASOUND_TRIG PIN4
#define PIN_ULTRASOUND_ECHO PIN5

void setup();
void loop();
void presentation();
//void ISR_PIRFired();
void PrintDebug(String message);
void PrintDebugWithValue(String message, float value);
