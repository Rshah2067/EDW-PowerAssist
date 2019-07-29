
#include "FlexLibrary.h"
int deg;
int deg3;
int flex_Min = 51; 
int flex_Max = 126;
Flex flex(A0, flex_Min, flex_Max, 10, RUN_AVG, 0);

int deg2;
int deg4;
int flex_Min2 = 4; 
int flex_Max2 = 30;
Flex flex2(A1, flex_Min2, flex_Max2, 10, RUN_AVG, 0);

String debug = "";
String debug2 = "";

void setup() {
  Serial.begin(9600);

  delay(5000);
  for (int i = 0; i < 1000; i++) {
    flex.Calibrate();
    flex2.Calibrate();
  }


}

void loop() {
  flex.updateVal();
  flex2.updateVal();
  deg = flex.getSensorValue();
  deg2 = flex2.getSensorValue();
  debug = ((String)"Flex 1: " + flex.getSensorValue());
  debug2 = ((String)"Flex 2: " + flex2.getSensorValue());
  deg = map(deg, flex_Min, flex_Max, 0, 90);
  deg2 = map(deg2, flex_Min2, flex_Max2, 0, 90);
  delay(200);

  Serial.println(debug);
  Serial.println(debug2);
  Serial.print("Flex 1 Degrees: ");
  Serial.println(deg);
  Serial.print("Flex 2 Degrees: ");
  Serial.println(deg2);
  Serial.println("");

  flex.updateVal();
  flex2.updateVal();
  deg3 = flex.getSensorValue();
  deg4 = flex2.getSensorValue();
  debug = ((String)"Flex 1: " + flex.getSensorValue());
  debug2 = ((String)"Flex 2: " + flex2.getSensorValue());
  deg3 = map(deg3, flex_Min, flex_Max, 0, 90);
  deg4 = map(deg4, flex_Min2, flex_Max2, 0, 90);
  
  Serial.println(debug);
  Serial.println(debug2);
  Serial.print("Flex 1 Degrees: ");
  Serial.println(deg3);
  Serial.print("Flex 2 Degrees: ");
  Serial.println(deg4);

  int difference1 = deg - deg3;
  int difference2 = deg - deg4;

  Serial.print(difference1);
  Serial.println(difference2);
  Serial.println("");
  
  delay(200);



}
