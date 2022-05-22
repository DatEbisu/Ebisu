#include <TrT_S.h>
#define soXung 20
#define chuVi 2
TrT_S Giaotiep;
unsigned char nhanMaytinh;
unsigned int demXung,vantoc,quangduong;
unsigned long int tdTruoc,tdHientai,chuky,tanso,thoigian;
void ngatngoai1(){ //do tre toi da ngat ngoai 3/16 us
    demXung++;
    tdTruoc=tdHientai;
    tdHientai=micros();
    chuky=tdHientai-tdTruoc;     
}
void setup() {
    Giaotiep.begin(9600);
    //Serial.begin(9600);
    pinMode(4,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP); //chan ngat 1 (PS1 on board)
    attachInterrupt(1,ngatngoai1,FALLING);
    
}

void loop() {
  //neu co xung trong vong 1s thi tinh tan so; trong 1s ko co xung thi tan so =0;
    if(micros()<=(tdHientai+1000000)){ 
      vantoc=360000/chuky;
    }
    else {vantoc=0;}
    if(digitalRead(4)==0){demXung=0;} //bam nut reset quang duong
    else{
    quangduong=demXung*(soXung/chuVi);}
//    vantoc=quangduong*1000000*3.6/chuky;
    nhanMaytinh=Giaotiep.WR(vantoc,quangduong);
    delay(20); 
}
