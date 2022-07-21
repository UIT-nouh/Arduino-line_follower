void setup() {
  DDRB |= (1 << PB5);
  PORTB = B00000000;
}

void loop() {
  PORTB |= ( 1 << PB5);
  delay(200);
  PORTB = (~PORTB);
  delay(200);
}
