#include <TrT_S.h>
TrT_S Giaotiep;
unsigned char nhanMaytinh;
unsigned int demXung;
void ngatngoai1(){ //do tre toi da ngat ngoai 3/16 us
    demXung++;  
}
void setup() {
    //Giaotiep.begin(9600);
    Serial.begin(9600);
    pinMode(3,INPUT_PULLUP); //chan ngat 1 (PS1 on board)
    attachInterrupt(1,ngatngoai1,FALLING);
}

void loop() {
  
    //nhanMaytinh=Giaotiep.WR(demXung,0);
    Serial.println(demXung);     
    delay(20); 
}
