unsigned int kqADC6,kqADC7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("test");
}

void loop() {
    kqADC6=analogRead(A6);  //Moi lan doc ton 1/16microgiay
    kqADC7=analogRead(A7);     
    Serial.print(kqADC6); Serial.print(" "); Serial.println(kqADC7);
    delay(200);
}
