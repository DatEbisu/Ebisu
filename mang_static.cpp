#include <stdio.h>
#define length 5
void nhapmang(int mang[]){
	for(int i=0;i<length;i++){
		scanf("%d",&mang[i]);	
	}
}
int* nhap_contro(){
	static int mang[length]; //static xem bien nhu bien toan cuc, cong don` khi nap gia tri	
	for(int i=0;i<length;i++){
		scanf("%d",&mang[i]);	
	}
	return mang;
}
void xulymang(int mang[]){
	for(int i=0;i<length;i++){
		mang[i]=mang[i]*10;
	}
}
void xuatmang(int mang[]){
	for(int i=0;i<length;i++){
		printf("%d ",mang[i]);	
	}
}
int main(void){
	int arr[length];
	int *b;
	//nhapmang(arr);
	//xulymang(arr);
	//xuatmang(arr);
	b=nhap_contro();
	xulymang(b);
	xuatmang(b);
	xulymang(b);
	xuatmang(b);
}
