
void setup(){
 
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
pinMode(6,OUTPUT);
}


void loop(){
digitalWrite(8,HIGH);
digitalWrite(7,LOW);
analogWrite(9,250);
digitalWrite(5,HIGH);
digitalWrite(4,LOW);
analogWrite(6,250);
 

}
