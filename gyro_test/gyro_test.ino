const int xPin = 1;
const int yPin = 2;
const int zPin = 3;

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly: 
int xValue = analogRead(xPin);
int yValue = analogRead(yPin);
int zValue = analogRead(xPin);

Serial.print("X="); Serial.print(xValue); Serial.print("\t");
Serial.print("Y="); Serial.print(yValue); Serial.print("\t");
Serial.print("Z="); Serial.print(zValue); Serial.print("\n");
delay(1000);
}
