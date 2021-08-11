const int xPin = 1;
const int yPin = 2;
const int zPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(EXTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(xPin);
  int y = analogRead(yPin);
  int z = analogRead(zPin);

  
  Serial.print("x: ");
  Serial.print(x);
  Serial.print(" | y: ");
  Serial.print(y);
  Serial.print(" | z: ");
  Serial.println(z);

  delay(200);
}
