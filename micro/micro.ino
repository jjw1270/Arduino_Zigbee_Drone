
void setup() {




  Serial.begin(9600);
  Serial1.begin(9600);

}

void loop() {
  int readV = analogRead(A0);
  int readS = analogRead(A1);
  Serial.print(readV);
  Serial.print("     ");
  Serial.println(readS);
  delay(1000);
}
