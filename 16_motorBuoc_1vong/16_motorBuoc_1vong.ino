#define b 8 //1B ULN2003
#define c 9 //2B
#define a 6 //3B
#define g 5 //4B
#include <TrT_S.h>
TrT_S Giaotiep;
unsigned int kqADC6,sobuoc;
void dk_cungchieukim(unsigned char t){
  //clockwise b->c->a->g
  //t=constrain(t,50,200); //khong che thoi gian delay
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
  //t=constrain(t,50,200);
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
  //t=constrain(t,50,200);
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
   Serial.begin(9600);
   //Giaotiep.begin(9600);
}
void loop() {
//  sobuoc=512;
//  if(sobuoc>0){
//    sobuoc--;
//    dk_nguocchieukim(5);
//  }
//  else {dk_dung(5);}

    for(int i=0;i<512;i++){dk_nguocchieukim(5);}
    dk_dung(5); delay(2000);
}
