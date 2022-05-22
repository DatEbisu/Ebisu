#include <TrT_S.h>
TrT_S Giaotiep;
unsigned int kqADC6,kqADC7;
unsigned char nhanMaytinh;
void setup() {
    Giaotiep.begin(9600);
    //Serial.begin(9600);
    //Serial.println("test");
}

void loop() {
    kqADC6=analogRead(A6);  //Moi lan doc ton 1/16microgiay
    kqADC7=analogRead(A7);
    nhanMaytinh=Giaotiep.WR(kqADC6,kqADC7);     
    //Serial.print(kqADC6); Serial.print(" "); Serial.println(kqADC7);
    delay(20); 
}
