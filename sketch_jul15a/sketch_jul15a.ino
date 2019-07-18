
#include "FlexLibrary.h"
int deg;
int flex_Min = 291;
int flex_Max = 200;
Flex flex(A3, flex_Min, flex_Max, 10, RUN_AVG, 0);

String debug = "";

void setup() {
  Serial.begin(9600);

  delay(5000);
  for (int i = 0; i < 1000; i++) {
    flex.Calibrate();
  }
  Serial.print("Min Value: ");
  Serial.println(flex.getMinInput());
  Serial.print("Max Value: ");
  Serial.println(flex.getMaxInput());






}

void loop() {
  flex.updateVal();
  deg = flex.getSensorValue();
  debug = ((String)"flex: " + flex.getSensorValue());
  deg = map(deg, 400, 240, 0, 180);
  Serial.println(debug);
  //Serial.print("Degrees: ");
  //Serial.println(deg);



}
