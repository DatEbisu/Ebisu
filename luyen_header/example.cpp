#include"example.h"
int main(){
	int a=6,b=5;
	int *ptr;
	ptr=nhapmang();
	swap(&a,&b);
	xuatmang(ptr);
	printf("\nsau khi doi cho a=%d b=%d\n",a,b);
	return 0;
}
void swap(int *a,int *b){
	*a=5;
	*b=6;
}
int* nhapmang(){
	static int arr[5];
	for(int i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}
	return arr;
}
void xuatmang(int* ptr){
	for(int i=0;i<5;i++){
		printf("%d ",ptr[i]);
	}	
}
