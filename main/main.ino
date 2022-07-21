int maxSpeed = 120;

int s1 = 3; 
int s2 = 2;
int s3 = 5;
int s4 = 6;
int s5 = 7;

int a, b, c, d, e;

int E1 = 10;
int M1 = 12;
int E2 =11;
int M2 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
}

void loop() {
  a = digitalRead(s1);
  b = digitalRead(s2);
  c = digitalRead(s3);
  d = digitalRead(s4);
  e = digitalRead(s5);
  Serial.print(a);Serial.print(" ");
  Serial.print(b);Serial.print(" ");
  Serial.print(c);Serial.print(" ");
  Serial.print(d);Serial.print(" ");
  Serial.print(e);Serial.print(" ");
  if(a == 1 && b == 0 && c == 0 && d == 0 && e == 1 || 
     a == 1 && b == 1 && c == 0 && d == 1 && e == 1
    ){
    digitalWrite(M1,LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, maxSpeed);
    analogWrite(E2, maxSpeed);
    Serial.println(" thang");
  }
  else if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0){
    digitalWrite(M1,HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(E1, maxSpeed);
    analogWrite(E2, maxSpeed);
    Serial.println(" lui");
  }
  else if(a == 0 && b == 0 && c == 0 && d == 1 && e == 1 ||
          a == 0 && b == 0 && c == 1 && d == 1 && e == 1 || 
          a == 0 && b == 1 && c == 1 && d == 1 && e == 1 ||
          a == 1 && b == 0 && c == 1 && d == 1 && e == 1 ||
          a == 1 && b == 0 && c == 0 && d == 1 && e == 1 
         ){
    digitalWrite(M1,HIGH);
    digitalWrite(M2, LOW);
    analogWrite(E1, maxSpeed);
    analogWrite(E2, maxSpeed);
    Serial.println(" trai");
  }
  else if(a == 1 && b == 1 && c == 0 && d == 0 && e == 0 ||
          a == 1 && b == 1 && c == 1 && d == 0 && e == 0 || 
          a == 1 && b == 1 && c == 1 && d == 1 && e == 0 ||
          a == 1 && b == 1 && c == 1 && d == 0 && e == 1 || 
          a == 1 && b == 1 && c == 0 && d == 0 && e == 1 
         ){
    digitalWrite(M1,LOW);
    digitalWrite(M2, HIGH);
    analogWrite(E1, maxSpeed);
    analogWrite(E2, maxSpeed);
    Serial.println(" phai");
  }
  delay(20);
}
