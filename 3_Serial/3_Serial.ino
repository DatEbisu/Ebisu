unsigned char dem;
void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("test");
}

void loop() {
  // put your main code here, to run repeatedly:
    dem++;
    Serial.println(dem);
    delay(10);
}
