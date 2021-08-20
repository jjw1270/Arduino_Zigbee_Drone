//가속도센서 핀
const int xPin = 0;
const int yPin = 1;
const int zPin = 2;
//flex 센서 핀'
const int fPin_1 = 3;
const int fPin_2 = 4;
const int fPin_3 = 5;
const int fPin_4 = 6;
const int fPin_5 = 7;

const int ResetButton = 12;
boolean current = true;

//가속도센서 최소,최대값
int x_minVal = 267;
int x_maxVal = 404;
int y_minVal = 270;
int y_maxVal = 408;
int z_minVal = 275;
int z_maxVal = 413;
double x,y,z;


void setup() {
  Serial.begin(9600); 
  analogReference(EXTERNAL);
  pinMode(ResetButton, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(ResetButton) == LOW){
    if(current == false){
      current = true;
    }
    else{
      current = false;
    }
  }
  if(current == true){
    int xRead = analogRead(xPin);
    int yRead = analogRead(yPin);
    int zRead = analogRead(zPin);
    
    int fRead_1 = analogRead(fPin_1);
    int fRead_2 = analogRead(fPin_2);
    int fRead_3 = analogRead(fPin_3);
    int fRead_4 = analogRead(fPin_4);
    int fRead_5 = analogRead(fPin_5);
  
    //convert read values to degrees -90 to 90 - Needed for atan2
    int x = map(xRead, x_minVal, x_maxVal, -90, 90);
    int y = map(yRead, y_minVal, y_maxVal, -90, 90);
    int z = map(zRead, z_minVal, z_maxVal, -90, 90);
  
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    Serial.print(z);
    Serial.print(",");
    Serial.print(fRead_1);
    Serial.print(",");
    Serial.print(fRead_2);
    Serial.print(",");
    Serial.print(fRead_3);
    Serial.print(",");
    Serial.print(fRead_4);
    Serial.print(",");
    Serial.println(fRead_5);
  
    delay(100);
  }
}
