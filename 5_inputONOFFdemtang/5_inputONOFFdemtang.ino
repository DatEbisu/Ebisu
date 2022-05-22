unsigned char dem,nutSW3truoc,nutSW3,demSW3,ttSW3;
void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("test");
}

void loop() {
  // put your main code here, to run repeatedly:
  nutSW3truoc = nutSW3; 
  nutSW3 = digitalRead(7);        
    if(nutSW3==0 && nutSW3truoc==1){  //trang thai vua nhan 1->0
        demSW3++;
        if(demSW3>15){
            demSW3=0;
          }
        if(ttSW3==0){ttSW3=1;Serial.println("ON");} else {ttSW3=0;Serial.println("OFF");}  
        Serial.println(demSW3);
    }
  
    delay(100);
}
