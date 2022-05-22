#define PWM1 5  //6 kenhB L298
#define IN1 11  //8
#define IN2 10  //9
unsigned int kqADC6;
signed int tocdo;
void dkMotorDC(signed int x){
  x=constrain(x,-255,255);
  if(x>10)      {digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);analogWrite(PWM1,x);}
  else if(x<-10){digitalWrite(IN1,LOW);digitalWrite(IN2,HIGH);analogWrite(PWM1,-x);}
  else          {analogWrite(PWM1,0);}
}
void setup() {
  pinMode(PWM1,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  Serial.begin(9600);
}
void loop() {
   kqADC6=analogRead(A6);
   if(kqADC6<=500 && kqADC6>=0){
       tocdo=map(kqADC6,0,500,-255,-10);
       Serial.print(kqADC6);Serial.print(" ");Serial.println(tocdo);
   }
   else if(kqADC6>=523 && kqADC6<=1023){
       tocdo=map(kqADC6,523,1023,10,255);
       Serial.print(kqADC6);Serial.print(" ");Serial.println(tocdo);
   }
   else {tocdo=0;Serial.print(kqADC6);Serial.print(" ");Serial.println(tocdo);}
   dkMotorDC(tocdo);
   delay(100);

}
