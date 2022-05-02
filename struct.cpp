#include<stdio.h>
typedef struct{
	char ten[30];
	unsigned char tuoi;
	unsigned int namsinh;
} QLSV; 

int main(){	
	QLSV SV1,SV2;
   	printf("Nhap ten SV1: ");
   	gets(SV1.ten);
	SV1.tuoi=22;
	SV1.namsinh=2000;	
	printf("\n%s",SV1.ten);
	printf("\n%d",SV1.tuoi);
	printf("\n%d",SV1.namsinh);

		
	return 0;
}
