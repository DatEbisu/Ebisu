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
void xuatmang(int mang[]){
	for(int i=0;i<length;i++){
		printf("%d ",mang[i]);	
	}
}
int linearSearch(int mang[],int x){
	for(int i=0;i<length;i++){
		if(mang[i]==x){
			return 1;
		}	
	}
	return 0;
}
void sapxep(int mang[]){
	for(int i=0;i<length;i++){
		for(int j=length-1;j>i;j--){
			if(mang[i]<mang[j]){
				int t=mang[i];
				mang[i]=mang[j];
				mang[j]=t;
			}
		}
	}
}
int main(void){
	int *b;
	int kiemtra;
	b=nhap_contro();
	sapxep(b);
	xuatmang(b);
	kiemtra=linearSearch(b,1);
	if(kiemtra==1){
		printf("tim thay");
	}
	else {
		printf("KHONG tim thay");
	}
}
