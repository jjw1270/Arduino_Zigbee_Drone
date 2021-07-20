/*   ~ Simple Arduino - xBee Receiver sketch ~
  Read an PWM value from Arduino Transmitter to fade an LED
  The receiving message starts with '<' and closes with '>' symbol.
    Dev: Michalis Vasilakis // Date:2/3/2016 // Info: www.ardumotive.com // Licence: CC BY-NC-SA                    */
//Constants
const int ledPin = 13;
//Variables

void setup() {  //Start the serial communication
  Serial.begin(9600); //Baud rate must be the same as is on xBee module
  pinMode(ledPin, OUTPUT);
}
void loop() {
  
  if (Serial.available()){
    //Read the incoming byte
    char IN = Serial.read();
    Serial.print(IN);
  }
}
