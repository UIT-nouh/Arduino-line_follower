#include <TimerOne.h>

int maxSpeed = 255;
//int online = 0, maxOnline = 255, bottom = 80, above = 255;
//boolean leftCatch, rightCatch;
int ME1 = 10;
//int M1 = 12;
int ME2 =11;
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
  Timer1.initialize(20000);
  Timer1.attachInterrupt(PID);
}

void loop() {
  
}
void PID()
{
  byte getted = ((PIND&B11100000) >> 3) | ((PIND&B00001100) >> 2); 
  if(getted == B00010001 || getted == B00011011){
    PORTB = B00000000;
    analogWrite(ME1, maxSpeed);
    analogWrite(ME2, maxSpeed);
  }
  else if(getted == B00000000){
    //PORTB = B00110000;
    PORTB = B00000000;
    analogWrite(ME1, maxSpeed);
    analogWrite(ME2, maxSpeed);
  }
  else if( getted == B00000011 || getted == B00000111 || getted == B00001111 || getted == B00010111 || getted == B00010011 ){  
    int speeds = 0;
    if(getted == B00001111){
      PORTB = B00100000;
      speeds = 255;
    }
    else if( getted == B00000111){
      PORTB = B00100000;
      speeds = 0;
    }
    else if( getted == B00010111){
      PORTB = B00000000;
      speeds = 120;
    }
    else if( getted == B00010011){
      PORTB = B00000000;
      speeds = 180;
    }
    analogWrite(ME1, maxSpeed);
    analogWrite(ME2, speeds);
  }
  else if(getted == B00011000 || getted == B00011100 || getted == B00011110 || getted == B00011101 || getted == B00011001){
    int speeds = 0;
    if(getted == B00011110){
      PORTB = B00010000;
      speeds = 255;
    }
    else if( getted == B00011100){
      PORTB = B00010000;
      speeds = 0;
    }
    else if( getted == B00011101){
      PORTB = B00000000;
      speeds = 120;
    }
    else if( getted == B00011001){
      PORTB = B00000000;
      speeds = 180;
    }
    //PORTB = B00010000;
    analogWrite(ME1, speeds);
    analogWrite(ME2, maxSpeed);
  }
}
