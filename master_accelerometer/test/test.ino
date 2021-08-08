const int xPin = A2;
const int yPin = A1;
const int zPin = A0;
const int ResetButton = 9;

int sampleDelay = 500;
void setup(){
  Serial.begin(9600);

  analogReference();

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(zPin, INPUT);
}
void loop(){
  int x = analogRead(xPin);
  delay(1);
  int y = analogRead(yPin);
  delay(1);
  int z = analogRead(zPin);
  float zero_G = 512.0;

  float scale = 102.3;

  Serial.print(((float)x - zero_G)/scale);
  Serial.print("\t");
  Serial.print(((float)y - zero_G)/scale);
  Serial.print("\t");
  Serial.print(((float)z - zero_G)/scale);
  Serial.print("\n");

  delay(sampleDelay);
}
