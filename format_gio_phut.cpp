#include<stdio.h>
int main(){
	int n,gio,phut,giay;
	scanf("%d",&n);
	
	gio=n/3600;
	phut=n%3600/60;
	giay=n%3600%60;
	
	printf("gio=%d",gio);
	printf("phut=%d",phut);
	printf("giay=%d",giay);
	return 0;
}
