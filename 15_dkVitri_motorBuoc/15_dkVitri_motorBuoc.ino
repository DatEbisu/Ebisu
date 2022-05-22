#define b 8 //1B ULN2003
#define c 9 //2B
#define a 6 //3B
#define g 5 //4B
#include <TrT_S.h>
TrT_S Giaotiep;
unsigned char nhanMaytinh,vitriMotor,vitriSet;
unsigned int tg;
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
void setup() {
   pinMode(a,OUTPUT);
   pinMode(b,OUTPUT);
   pinMode(c,OUTPUT);
   pinMode(g,OUTPUT);
   //Giaotiep.begin(9600);
   Serial.begin(9600);
}
void loop() {
  nhanMaytinh=Giaotiep.WR(vitriSet,vitriMotor);
  vitriSet=nhanMaytinh;
  tg=5;
//  Serial.print(vitriSet);
//  Serial.print("   ");
//  Serial.println(vitriMotor);
//  vitriSet=analogRead(7);
//  tg=50;
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
}
