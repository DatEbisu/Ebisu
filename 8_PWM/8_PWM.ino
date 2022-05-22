#include <TrT_S.h>
TrT_S Giaotiep;
unsigned char dosang;
unsigned char nhanMaytinh,kqADC6,kqADC7;
void setup() {
    pinMode(5,OUTPUT);
    Giaotiep.begin(9600);

}

void loop() {
    kqADC6=analogRead(A6);  //Moi lan doc ton 1/16microgiay
    analogWrite(5,nhanMaytinh); 
    nhanMaytinh=Giaotiep.WR(kqADC6,kqADC7);     
    delay(20); 
}
