//gy-61 accelerometer

const int xPin = A2;
const int yPin = A1;
const int zPin = A0;
const int ResetButton = 9;

boolean current = false;
int x,y,z;
int minVal = 270;
int maxVal = 420;

const int numReadings = 30;
int xReadings[numReadings],yReadings[numReadings],zReadings[numReadings];
int readIndex = 0;
int xTotal = 0;
int yTotal = 0;
int zTotal = 0;
int xAverage = 0;
int yAverage = 0;
int zAverage = 0;

void setup() {
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(zPin, INPUT);
  pinMode(ResetButton, INPUT_PULLUP);

  Serial.begin(9600);

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    xReadings[thisReading] = 0;
    yReadings[thisReading] = 0;
    zReadings[thisReading] = 0;
  }

}

void loop() {  
  if(digitalRead(ResetButton) == LOW){
    if(current == false){
      current = true;
    }
  }
  if(current == true){

    xTotal = xTotal - xReadings[readIndex];
    yTotal = yTotal - yReadings[readIndex];
    zTotal = zTotal - zReadings[readIndex];
    
    x = analogRead(xPin);
    y = analogRead(yPin);
    z = analogRead(zPin);
  
    int xAng = map(x,minVal,maxVal,-90,90);
    int yAng = map(y,minVal,maxVal,-90,90);
    int zAng = map(z,minVal,maxVal,-90,90);  
    
    x = RAD_TO_DEG * (atan2(-yAng,-zAng) + PI);
    y = RAD_TO_DEG * (atan2(-xAng,-zAng) + PI);
    z = RAD_TO_DEG * (atan2(-yAng,-xAng) + PI);
    
    xReadings[readIndex] = x;
    yReadings[readIndex] = y;
    zReadings[readIndex] = z;

    xTotal += xReadings[readIndex];
    yTotal += yReadings[readIndex];
    zTotal += zReadings[readIndex];

    readIndex += 1;

    if(readIndex >= numReadings){
      readIndex = 0;
    }

    xAverage = xTotal / numReadings;
    yAverage = yTotal / numReadings;
    zAverage = zTotal / numReadings;
    
    
    Serial.print(xAverage);
    Serial.print(",");
    Serial.print(yAverage);
    Serial.print(",");
    Serial.println(zAverage);
  }
  delay(10);
}
