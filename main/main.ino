int maxSpeed = 255;

//int s1 = 2; 
//int s2 = 3;
//int s3 = 5;
//int s4 = 6;
//int s5 = 7;
//int a, b, c, d, e;

int E1 = 10;
//int M1 = 12;
int E2 =11;
//int M2 = 13;

void setup() {
  Serial.begin(9600);
//  pinMode(M1, OUTPUT);
//  pinMode(M2, OUTPUT);
//  pinMode(s1, INPUT);
//  pinMode(s2, INPUT);
//  pinMode(s3, INPUT);
//  pinMode(s4, INPUT);
//  pinMode(s5, INPUT);
  DDRD = B00000000;
  DDRB = B00110000;
}

void loop() {
//  a = digitalRead(s1);
//  b = digitalRead(s2);
//  c = digitalRead(s3);
//  d = digitalRead(s4);
//  e = digitalRead(s5);
  byte getted = ((PIND&B11100000) >> 3) | ((PIND&B00001100) >> 2);
  Serial.print(getted,BIN);Serial.print(" ");
  if(getted == B00010001 || getted == B00011011){
//    digitalWrite(M1,LOW);
//    digitalWrite(M2, LOW);
    PORTB = B00000000;
    analogWrite(E1, maxSpeed);
    analogWrite(E2, maxSpeed);
    Serial.print(" thang");
  }
  else if(getted == B00000000){
//    digitalWrite(M1,HIGH);
//    digitalWrite(M2, HIGH);
    PORTB = B00110000;
    analogWrite(E1, maxSpeed);
    analogWrite(E2, maxSpeed);
    Serial.print(" lui");
  }
  else if( getted == B00000011 || getted == B00000111 || getted == B00001111 || getted == B00010111 || getted == B00010011 ){
//    digitalWrite(M1,HIGH);
//    digitalWrite(M2, LOW);
    PORTB = B00100000;
    analogWrite(E1, maxSpeed);
    analogWrite(E2, maxSpeed);
    Serial.print(" trai");
  }
  else if( getted == B00011000 || getted == B00011100 || getted == B00011110 || getted == B00011101 || getted == B00011001 ){
//    digitalWrite(M1,LOW);
//    digitalWrite(M2, HIGH);
    PORTB = B00010000;
    analogWrite(E1, maxSpeed);
    analogWrite(E2, maxSpeed);
    Serial.print(" phai");
  }
  delay(20);
  Serial.println();
}
