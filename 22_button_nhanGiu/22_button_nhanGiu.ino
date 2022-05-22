int button=7;
int led=8;
unsigned long int tgHientai,tg,tgTruoc;
void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT); 
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(tgHientai); 
  if(digitalRead(button)==0){ 
    tgHientai=micros();    
    tg = tgHientai - tgTruoc;   
    if(tg>5000000){
      digitalWrite(led,HIGH);
      tgTruoc=tgHientai; 
    }
  }
  else  digitalWrite(led,LOW); 
}
