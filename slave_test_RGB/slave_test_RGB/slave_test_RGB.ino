int R = 7;
int G = 6;
int B = 5;

int start_state = 0;
int RGB_state = 0;
int blink_state = 0;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  Serial.begin(9600);
}

void RGB_off(){
  analogWrite(R,255);
  analogWrite(G,255);
  analogWrite(B,255);
}

void RGB(int r, int g, int b){
  analogWrite(R, r);
  analogWrite(G, g);
  analogWrite(B, b);
}

void loop() {
  if (Serial.available()){
    String In = Serial.readStringUntil('\n');

    if(In.indexOf('C') > 24){
      if(start_state == 0){
        start_state = 1;
      }else{
        start_state = 0;
      }
    }
    
    if(start_state == 1){
      int LX = map(In.substring(4,5).toInt(), 1,7, 255,0);
      int LY = map(In.substring(10,11).toInt(), 1,7, 255,0);
      int RX = map(In.substring(16,17).toInt(), 1,7, 255,0);
      int RY = map(In.substring(22,23).toInt(), 1,7, 255,0);
      
      if(In.indexOf('S')> 24){
        if(RGB_state == 0){
          RGB_state = 1;
        }else{
          RGB_state = 0;
        }
      }
      if(In.indexOf('P')> 24){
        if(blink_state == 0){
          blink_state = 1;
        }
        else{
          blink_state = 0;
        }
      }
      
      if(RGB_state == 0){
        if(blink_state == 1){
          RGB(RY,RY,RY);
          delay(200);
          RGB_off();
        }else{
          RGB(RY,RY,RY);
        }
      }else{
        if(blink_state == 1){
          RGB(LY,RY,RX);
          delay(200);
          RGB_off();
        }else{
          RGB(LY,RY,RX);
        }
      }
    }else{
      RGB_off();
    }
  }
}
