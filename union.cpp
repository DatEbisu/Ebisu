#include<stdio.h>
union danhsach{
	char ten[30];
	int tuoi;
};


int main(){
	union danhsach sv1;
	printf("nhap ten: ",sv1.ten);
	gets(sv1.ten);
	printf("ten %s",sv1.ten);	
	sv1.tuoi=22;
	printf("tuoi %d",sv1.tuoi);	
	return 0;
}
