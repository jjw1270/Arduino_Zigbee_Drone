const int xPin = 1;
const int yPin = 2;
const int zPin = 3;
const int ResetButton = 9;
boolean current = true;

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
  delay(5000);

}

void loop() {
  if(digitalRead(ResetButton) == LOW){
    if(current == false){
      current = true;
    }
  }
  if(current == true){
    int xRead = analogRead(xPin);
    int yRead = analogRead(yPin);
    int zRead = analogRead(zPin);
  
    //convert read values to degrees -90 to 90 - Needed for atan2
    int x = map(xRead, x_minVal, x_maxVal, -90, 90);
    int y = map(yRead, y_minVal, y_maxVal, -90, 90);
    int z = map(zRead, z_minVal, z_maxVal, -90, 90);
  
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    Serial.println(z);
  
    delay(100);
  }
}
