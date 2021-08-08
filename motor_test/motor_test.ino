int motorB1 = 6;
int motorB2 = 5;
int motorA1 = 9;
int motorA2 = 10;

int spd = 100;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

}

void analog(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, spd);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, spd);
}

void astop(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
  delay(2000);
}

void mA(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, spd);
  delay(100);
}

void mB(){
  analogWrite(motorB1, 0);
  analogWrite(motorB2, spd);
  delay(100);
}

void loop() {
  analog();
  delay(4000);
  astop();
}
