#include <TrT_S.h>
TrT_S Giaotiep;
unsigned int kqADC3;
unsigned char nhanMaytinh,dienap;
void setup() {
    Giaotiep.begin(9600);
    //Serial.begin(9600);
}

void loop() {
    kqADC3=analogRead(A3);  //Moi lan doc ton 1/16microgiay
    //dienap=(unsigned long int)kqADC*212/1023;
    dienap=map(kqADC3,0,1023,0,212);
    //Serial.print(dienap);Serial.print(" *0.1V");Serial.print(" ");Serial.println(kqADC3);
    nhanMaytinh=Giaotiep.WR(dienap,kqADC3);     
    delay(200); 
}
