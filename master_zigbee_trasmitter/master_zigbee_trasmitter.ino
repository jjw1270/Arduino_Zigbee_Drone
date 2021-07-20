/*arduino Pro Micro(Based on Leonardo)
*/
int C_ = 14;   //button pin C, S, P
int S_ = 10;
int P_ = 3;

int RX;       //set state
int RY;
int LX;
int LY;
int C;
int S;
int P;
  
void setup() {
  Serial1.begin(9600);
  pinMode(C_, INPUT_PULLUP);
  pinMode(P_, INPUT_PULLUP);

}

void loop() {
  RY = analogRead(A0);
  RX = analogRead(A1);
  LY = analogRead(A2);
  LX = analogRead(A3);
  C = digitalRead(C_);
  S = analogRead(S_);
  P = digitalRead(P_);

  analoginput("LX",LX);
  analoginput("LY",LY);
  analoginput("RX",RX);
  analoginput("RY",RY);

//S누르면 S=0, P=0
//P누르면 S=123, P=0
//C누르면 C=0
  if (C == 0){
    Serial1.print("<C>");
  }
  if (P == 0){
    if (S == 0){
      Serial1.print("<S>");
    }
    else {
    Serial1.print("<P>");
    }
  }
  Serial1.println();
  delay(800);
}

void analoginput(char* var, int in){
  if(in >= 600){
    Serial1.print("<");
    Serial1.print(var);
    Serial1.print(":7>");
  }else if(in < 600 and in >= 500){
    Serial1.print("<");
    Serial1.print(var);    
    Serial1.print(":6>");
  }else if(in < 500 and in >= 400){
    Serial1.print("<");
    Serial1.print(var);    
    Serial1.print(":5>");
  }else if(in < 400 and in >= 300){      //center
    Serial1.print("<");
    Serial1.print(var);    
    Serial1.print(":4>");                
  }else if(in < 300 and in >= 200){
    Serial1.print("<");
    Serial1.print(var);    
    Serial1.print(":3>");
  }else if(in < 200 and in >= 100){
    Serial1.print("<");
    Serial1.print(var);    
    Serial1.print(":2>");
  }else if(in < 100){
    Serial1.print("<");
    Serial1.print(var);
    Serial1.print(":1>");
  }
}
