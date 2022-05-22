#define PWM1 5  //6 kenhB L298
#define IN1 11  //8
#define IN2 10  //9
#include <TrT_S.h>
TrT_S Giaotiep;
unsigned char nhanMaytinh;
unsigned int demXung;
unsigned long int tdTruoc,tdHientai,chuky,tanso;
signed int tocdo;
void ngatngoai1(){ //do tre toi da ngat ngoai 3/16 us
    demXung++;
    tdTruoc=tdHientai;
    tdHientai=micros();
    chuky=tdHientai-tdTruoc;     
}
void dkMotorDC(signed int x){
  x=constrain(x,-255,255);
  if(x>10)      {digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);analogWrite(PWM1,x);}
  else if(x<-10){digitalWrite(IN1,LOW);digitalWrite(IN2,HIGH);analogWrite(PWM1,-x);}
  else          {analogWrite(PWM1,0);}
}
void setup() {
    Giaotiep.begin(9600);
    pinMode(PWM1,OUTPUT);
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(3,INPUT_PULLUP); //chan ngat 1 (PS1 on board)
    attachInterrupt(1,ngatngoai1,FALLING);
}

void loop() {
    //neu co xung trong vong 1s thi tinh tan so
    if(micros()<=(tdHientai+1000000)){tanso=1000000/chuky;}
    else {tanso=0;} //1s ko co xung thi tan so =0;
    
    nhanMaytinh=Giaotiep.WR(tanso,demXung);
       if(nhanMaytinh<=126 && nhanMaytinh>=0){
       tocdo=map(nhanMaytinh,0,126,-255,-10);
   }
   else if(nhanMaytinh>=129 && nhanMaytinh<=255){
       tocdo=map(nhanMaytinh,129,255,10,255);
   }
   else {tocdo=0;}
   
   dkMotorDC(tocdo);
   delay(20); 
}
