void setup() {
  Serial.begin(9600); //Baud rate must be the same as is on xBee module
}
void loop() {  
  if (Serial.available()){
    //Read the incoming String
    String In = Serial.readStringUntil('\n');
    //Serial.println(In);
    int LX = In.substring(4,5).toInt();
    int LY = In.substring(10,11).toInt();
    int RX = In.substring(16,17).toInt();
    int RY = In.substring(22,23).toInt();

    Serial.print(LX);
    Serial.print(", ");
    Serial.print(LY);
    Serial.print(", ");
    Serial.print(RX);
    Serial.print(", ");
    Serial.print(RY);

    if(In.indexOf('C')> 24){
      String CB = In.substring(In.indexOf('C'),In.indexOf('C')+1);
      Serial.print(", ");
      Serial.print(CB);
    }
    if(In.indexOf('P')> 24){
      String PB = In.substring(In.indexOf('P'),In.indexOf('P')+1); 
      Serial.print(", ");
      Serial.print(PB);
    }
    if(In.indexOf('S')> 24){
      String SB = In.substring(In.indexOf('S'),In.indexOf('S')+1); 
      Serial.print(", ");
      Serial.print(SB);
    }

    Serial.println();
  }
}
