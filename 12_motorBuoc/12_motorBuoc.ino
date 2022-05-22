#define b 8 //1B ULN2003
#define c 9 //2B
#define a 6 //3B
#define g 5 //4B
unsigned char nhanMaytinh,thoigian;
unsigned int kqADC6;
void dk_cungchieukim(unsigned char t){
  //clockwise b->c->a->g
  t=constrain(t,5,100); //khong che thoi gian delay
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
  t=constrain(t,5,100);
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
  t=constrain(t,5,100);
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
}
void loop() {
  kqADC6=analogRead(A6);
  thoigian=map(kqADC6,0,1023,100,5);
  dk_cungchieukim(thoigian);
  //dk_nguocchieukim(thoigian);
  //dk_dung();
  //nhanMaytinh=Giaotiep.WR(0,0);
}
