#include <TrT_S.h>
TrT_S Giaotiep;
unsigned char nhanMaytinh;
unsigned int demXung;
unsigned long int tdTruoc,tdHientai,chuky,tanso;
void ngatngoai1(){ //do tre toi da ngat ngoai 3/16 us
    demXung++;
    tdTruoc=tdHientai;
    tdHientai=micros();
    chuky=tdHientai-tdTruoc;     
}
void setup() {
    Giaotiep.begin(9600);
    //Serial.begin(9600);
    pinMode(3,INPUT_PULLUP); //chan ngat 1 (PS1 on board)
    attachInterrupt(1,ngatngoai1,FALLING);
}

void loop() {
    if(micros()<=(tdHientai+1000000)){ //neu co xung trong vong 1s thi tinh tan so
      tanso=1000000/chuky;
    }
    else {tanso=0;} //1s ko co xung thi tan so =0;
    nhanMaytinh=Giaotiep.WR(tanso,demXung);
    delay(20); 
}
