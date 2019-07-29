#define enA 9
#define in1 6
#define in2 7

int rotDirection = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255); // Send PWM signal to L298N Enable pin
}
void loop() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    //rotDirection = 1;
    delay(20);
  
}
