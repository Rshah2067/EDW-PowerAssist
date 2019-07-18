const int FLEX_PIN1= A1; 
const int FLEX_PIN = A0; // Pin connected to voltage divider output

// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 46900.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 43000.0; // resistance when straight
const float BEND_RESISTANCE = 21000.0; // resistance at 90 deg

const float STRAIGHT_RESISTANCE2 = 4200.0; // resistance when straight
const float BEND_RESISTANCE2 = 72000.0;
void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
  pinMode(FLEX_PIN1,INPUT);
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(FLEX_PIN);
  int flexADC2 = analogRead(FLEX_PIN1);
  float flexV = flexADC * VCC / 1023.0;
  float flexV2 = flexADC2 * VCC/1023.0;
  float flexR = R_DIV * (VCC / flexV - 1.0);
  float flexR2 = R_DIV * (VCC / flexV2 - 1.0);
  Serial.println("Resistance: " + String(flexR) + " ohms");
  Serial.println("Resistance2: " + String(flexR2) + " ohms");
  
  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  
  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 90.0);
  float angle2 = map(flexR2,STRAIGHT_RESISTANCE2, BEND_RESISTANCE2,
                   0, 90.0);                 
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println("Bend2:  "+String(angle2) + " degrees");
  Serial.println();

  delay(500);
}
