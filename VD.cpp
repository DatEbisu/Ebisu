#include <stdio.h>
void sapxeptang(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int main() {
   int arr[5],temp;

   printf("Nhap mang arr\n");
   for(int i =0;i<5;i++){
   	printf("Nhap phan tu thu arr[%d]=",i+1,"\n");
   	scanf("%d",&arr[i]);
   	while(arr[i]>=10){
   		printf("Nhap LAI phan tu thu arr[%d]=",i+1,"\n");
   		scanf("%d",&arr[i]);
	   }
   }

   for(int i =0;i<5;i++){
   	for(int j=i+1;j<5;j++){
   			if(arr[i]>arr[j]){
			sapxeptang(&arr[i],&arr[j]);}
		   }
	   }
   
   printf("Xuat mang arr da xep= ");
   for(int i =0;i<5;i++){
   	printf("%d",arr[i]);
   }

   return 0;
}
