#include<stdio.h>
int tinhtong(int *p);
int main(){

//	int *ptr;
//	ptr=nhapmang();
//	xuatmang(ptr);
	int arr[5];
	int *pa;
	pa=arr;
	for(int i=0;i<5;i++){
		scanf("%d",(pa+i));
	}
	int tong=0;
	for(int i=0;i<5;i++){
		printf("%d",*(pa+i));
	}
	tong=tinhtong(pa);			
	printf("tong= %d",tong);
	return 0;
}	
int tinhtong(int *p){
	int tong=0;
	for(int i=0;i<5;i++){
		tong+=*(p+i);
	}
	return tong;
}
//int *nhapmang(){
//	printf("NHAP MANG:\n");	
//	static int a[5];
//	for(int i=0;i<5;i++){
//		scanf("%d",&a[i]);
//	}
//	return a;
//}
//void xuatmang(int* a){
//	printf("mang da nhap:\n");
//	for(int i=0;i<5;i++){
//		printf("%d",a[i]);
//	}	
//}

