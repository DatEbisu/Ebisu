#define b 8 //1B ULN2003
#define c 9 //2B
#define a 6 //3B
#define g 5 //4B
#include <TrT_S.h>
TrT_S Giaotiep;
unsigned char nhanMaytinh,thoigian1,thoigian2,phantram1,phantram2;
unsigned int kqADC6;
void dk_cungchieukim(unsigned char t){
  //clockwise b->c->a->g
  t=constrain(t,50,200); //khong che thoi gian delay
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
  t=constrain(t,50,200);
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
  t=constrain(t,50,200);
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
  kqADC6=analogRead(A6);
  thoigian1=map(kqADC6,0,450,50,200);
  thoigian2=map(kqADC6,573,1023,200,50);
  if(kqADC6>=450&&kqADC6<=573){
    dk_dung(200);
    Serial.print("stop - toc do: ");
    Serial.print(0);
    Serial.println(" %");
  }
  if(kqADC6<450){
     dk_nguocchieukim(thoigian1);
     Serial.print("quay nguoc - toc do: ");
     phantram1=map(thoigian1,50,200,100,0);
     Serial.print("-");
     Serial.print(phantram1);
     Serial.println(" %");
  }
   if(kqADC6>573){
     dk_cungchieukim(thoigian2);
     Serial.print("quay thuan - toc do: ");
     phantram2=map(thoigian2,200,50,0,100);
     Serial.print(phantram2);
     Serial.println(" %");
  }
  //dk_nguocchieukim(thoigian);
  //dk_dung();
  //nhanMaytinh=Giaotiep.WR(0,0);
}
