int motorB1 = 6;
int motorB2 = 5;
int motorA1 = 9;
int motorA2 = 10;

int spd = 255;
bool check = true;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  delay(100);
}

void loop() {
  
  analogWrite(motorA1, 0);
  delay(20);
  analogWrite(motorA2, 250);
  delay(20);
  analogWrite(motorB2, 250);
  delay(20);
  analogWrite(motorB1, 0);
  delay(7000);
  /*


  /*analogWrite(motorA1, 0);
  analogWrite(motorA2, 100);
  delay(3000);
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  delay(1000);
  
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 100);
  delay(3000);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
  delay(1000);*/
    
}
