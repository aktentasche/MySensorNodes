
#include "main.h"
MyMessage ultrasoundMsg(NODEID, V_DISTANCE);

// Change the pins if you wish.
//ST_HW_HC_SR04 ultrasonicSensor(PIN_ULTRASOUND_TRIG, PIN_ULTRASOUND_ECHO); // ST_HW_HC_SR04(TRIG, ECHO)
NewPing sonar(PIN_ULTRASOUND_TRIG, PIN_ULTRASOUND_ECHO, 100);
long previousValue;
void setup()
{
  Serial.begin(9600);
  previousValue = 0;
  //pinMode(PIN_PIR, INPUT);

  //attachInterrupt(digitalPinToInterrupt(PIN_PIR), ISR_PIRFired, CHANGE);
}

void presentation()
{
  // Send the Sketch Version Information to the Gateway
  sendSketchInfo("Ultrasound Sensor", "0.1");
  PrintDebug("Presenting node..");
  present(NODEID, S_DISTANCE);
}

void loop()
{
  //int asdf = digitalRead(PIN_PIR);
  //Serial.println(asdf);
  //send(pirMsg.set(1));
  //PrintDebugWithValue("Sleeping for (ms): ", updateIntervalMilliseconds);
  //sleep(updateIntpreviousValueervalMilliseconds);
  //Serial.println()

  long currentValue = sonar.ping_cm();
  if(currentValue != previousValue){
      PrintDebugWithValue("Distance: ", currentValue);
      send(ultrasoundMsg.set(currentValue));
  }
  previousValue = currentValue;

  delay(50);
}

/*void ISR_PIRFired(){
  int pirPinStatus = digitalRead(PIN_PIR);
  if(pirPinStatus == 1){
    PrintDebug("PIR ISR rising edge fired");
    send(pirMsg.set(1));
  }
  else{
    PrintDebug("PIR ISR falling edge fired");
    send(pirMsg.set(0));
  }
}*/

void PrintDebug(String message){
    #ifdef MY_DEBUG
    Serial.println(message);
    #endif
}

void PrintDebugWithValue(String message, float value){
  #ifdef MY_DEBUG
  Serial.print(message);
  Serial.println(value);
  #endif
}
