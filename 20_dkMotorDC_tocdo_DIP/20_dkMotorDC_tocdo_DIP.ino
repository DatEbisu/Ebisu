//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#include <TrT_S.h> 
TrT_S Giaotiep;

unsigned char nhanMaytinh=125;

#define PWM 5
#define IN1 11
#define IN2 10

//#define PWM 6
//#define IN1 9
//#define IN2 8

unsigned char chieuquay;
signed long int demngat,demxung;

unsigned long int thoidiemTRUOC, thoidiemHIENTAI, chuky;
signed long int tanso;


signed long int tocdoSet, tocdo, tocdoTruoc;
signed long int err, errTruoc, Perr, Ierr, Derr, Udieukhien;
signed long int KP=1000, KI=50, KD=200;

void ngatngoai1(void)
{
  if (digitalRead(2)==LOW) {demxung++; chieuquay=1;} 
  else {demxung--; chieuquay=0;}
  thoidiemTRUOC=thoidiemHIENTAI;
  thoidiemHIENTAI=micros();
  chuky=thoidiemHIENTAI-thoidiemTRUOC;
}
signed int giatridk;

signed int dkMotorDC(signed long int x)
{
  x=constrain(x,-255,255); if(abs(x)<50) x=0; 
  if (x>0) {digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW); analogWrite(PWM,x);}
  else if (x<0) {digitalWrite(IN1,LOW); digitalWrite(IN2,HIGH); analogWrite(PWM,-x);}
  else {x=0; analogWrite(PWM,0);}
  return x;
}

void setup() {
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  attachInterrupt(1, ngatngoai1, FALLING);
  Giaotiep.begin(9600);
  //Serial.begin(9600);
}

void loop() {

  if (micros()<=(thoidiemHIENTAI+1000000)) { 
    chuky=constrain(chuky, 10, 1000000);
    tanso = 1000000/chuky; //1-1000 Hz
  } else {tanso=0;}
  if (chieuquay==0) {tanso=-tanso;}
  
  tocdoTruoc=tocdo;
  tocdo=tanso;
  tocdoSet=nhanMaytinh; tocdoSet*=5;
  
  KP=1500; KI=50; KD=500;
  
  errTruoc = err;
  err = tocdoSet-tocdo;
  Perr = KP*err;
  Ierr += KI*err; //Ierr = Ierr + KI*err;
  Derr = KD*(err-errTruoc);
  
  Udieukhien = (Perr + Ierr + Derr)/1000; //he so duoc nang len 1000
  //Udieukhien = (Perr + Derr)/1000; //he so duoc nang len 1000
  //Udieukhien = (Perr)/1000;

  if(tocdoSet<10) {Udieukhien=0;} //them
  
  dkMotorDC(Udieukhien);
  
  nhanMaytinh=Giaotiep.WR(tocdoSet,tocdo);
  delay(20);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
