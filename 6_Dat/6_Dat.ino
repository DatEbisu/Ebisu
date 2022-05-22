//=============06_Nguyen Khac Thanh Dat_18145332===========
#define b 8 //1B ULN2003
#define c 9 //2B
#define a 6 //3B
#define g 5 //4B
#include <TrT_S.h>
TrT_S Giaotiep;
unsigned char nhanMaytinh,vitriMotor,vitriSet,doSang,kqADC6,tocdoSet,gocquay;
unsigned int tg;
unsigned int demXung,vantoc,quangduong;
unsigned long int tdTruoc,tdHientai,chuky,tanso,thoigian;
unsigned char dem,nutSW3truoc,nutSW3,demSW3;
void dk_cungchieukim(unsigned char t){
  //clockwise b->c->a->g
//  t=constrain(t,5,20); //khong che thoi gian delay
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(g,LOW);
  delay(t);
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(g,LOW);
  delay(t);
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(g,LOW);
  delay(t);
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(g,HIGH);
  delay(t);
}
void dk_nguocchieukim(unsigned char t){
  //counter_clockwise g->a->c->b
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(g,HIGH);
  delay(t);
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(g,LOW);
  delay(t);
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(g,LOW);
  delay(t);
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(g,LOW);
  delay(t);
}
void dk_dung(unsigned char t){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(g,LOW);
  delay(t);delay(t);delay(t);delay(t); 
}
void ngatngoai1(){ //do tre toi da ngat ngoai 3/16 us
    demXung++;
    tdTruoc=tdHientai;
    tdHientai=micros();
    chuky=tdHientai-tdTruoc;     
}
void setup() {
   pinMode(a,OUTPUT);
   pinMode(b,OUTPUT);
   pinMode(c,OUTPUT);
   pinMode(g,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(4,INPUT_PULLUP);
   pinMode(3,INPUT_PULLUP); //chan ngat 1 (PS1 on board)
   attachInterrupt(1,ngatngoai1,FALLING);
   //Giaotiep.begin(9600);
   Serial.begin(9600);
   digitalWrite(11,LOW);
}
void loop() {

//  vitriSet=nhanMaytinh;
//  tg=5;

  if(micros()<=(tdHientai+1000000)){ 
      vantoc=1800000/chuky;
    }
  else {vantoc=0;}
  if(quangduong<199){quangduong=demXung*0.5;}
  else {quangduong=199;}


  kqADC6=analogRead(A6);
  tocdoSet=map(kqADC6,0,1023,0,200);
  if(vantoc>tocdoSet){
    digitalWrite(11,HIGH);
  }
  else {digitalWrite(11,LOW);}

  doSang=map(vantoc,0,450,0,255);
  analogWrite(10,doSang);

  vitriSet=map(vantoc,0,450,0,256);
  gocquay=map(vitriSet,0,256,0,180);

  tg=5;
 
  if(vitriSet>vitriMotor){
    dk_cungchieukim(tg);
    vitriMotor++;
  }
  if(vitriSet<vitriMotor){
    dk_nguocchieukim(tg);
    vitriMotor--;
  }
  if(vitriSet==vitriMotor){
    dk_dung(tg);
  }
  nutSW3truoc = nutSW3; 
  nutSW3 = digitalRead(4);      
    if(nutSW3==0 && nutSW3truoc==1){  //trang thai vua nhan 1->0
        demXung=0;
        if(demSW3%2==0){//Serial.print(vantoc);Serial.print("   ");Serial.println(tocdoSet);
        nhanMaytinh=Giaotiep.WR(vantoc,tocdoSet);}
        if(demSW3%2!=0){//Serial.print(quangduong);Serial.print("   ");Serial.println(gocquay);
        nhanMaytinh=Giaotiep.WR(quangduong,gocquay);} 
        demSW3++;    
    }  
    delay(10);

}
