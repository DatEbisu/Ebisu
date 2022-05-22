//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void setup() {
  pinMode(6,OUTPUT);
}
void loop() {
  digitalWrite(6,HIGH);
  delay(1000); //khac delay_ms in C,
  digitalWrite(6,LOW);
  delay(1000); //ham delay() Arduino dung timer0 nen chinh xac hon
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
