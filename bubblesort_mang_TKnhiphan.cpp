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
int binarySearch(int arr[],int x){
	int left=0;
	int right;
	int mid;
	right=length-1;
	while(left<=right){
		mid=(left+right)/2;
		if(arr[mid]==x){return 1;}
		else if(x>arr[mid]){left=mid+1;}//neu phan tu giua nho hon x, thi tim ben trai	
		else {right=mid-1;}  //neu phan tu giua lon hon x, thi tim ben phai
	}
	return 0;	
}
void sapxep(int mang[]){
	for(int i=0;i<length;i++){
		for(int j=length-1;j>i;j--){
			if(mang[i]>mang[j]){
				int t=mang[i];
				mang[i]=mang[j];
				mang[j]=t;
			}
		}
	}
}
int main(void){
	int *b;
	int kiemtra,so,kiemtra2;
	b=nhap_contro();
	sapxep(b);
	xuatmang(b);
	kiemtra=linearSearch(b,1);
	if(kiemtra==1){printf("tim thay 1\n");}
	else {printf("KHONG tim thay 1\n");}
	while(1){
		printf("Nhap x can tim x=");
		scanf("%d",&so);
		if(so==-1){break;}
		kiemtra2=binarySearch(b,so);
		if(kiemtra2==1){printf("OK\n");}
		else{printf("KHONG THAY\n");}
	}
}
