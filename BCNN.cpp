#include<stdio.h>

int max(int a,int b);
int main(){
	int a,b,m=0,n=0;
	scanf("%d",&a);
	scanf("%d",&b);	
	int maxa_b;
	maxa_b=max(a,b);
	int arr[maxa_b],brr[maxa_b];
	int c[m];

	for(int i=0;i<max(a,b);i++){
		arr[i]=a*(i+1);
		brr[i]=b*(i+1);		
	}	
	printf("mang a\n");	
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		printf("%d ",arr[i]);
	}
	printf("\nmang b\n");
	for(int i=0;i<sizeof(brr)/sizeof(brr[0]);i++){
		printf("%d ",brr[i]);
	}
	printf("\nmang chung\n");			
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		for(int j=0;j<sizeof(brr)/sizeof(brr[0]);j++){
			if(arr[i]==brr[j]){
				c[m]=arr[i];
				m++;
			}
		}
	}
	for(int i=0;i<m;i++){
		printf("%d ",c[i]);
	}
	int bcnn=10000000;
	for(int i=0;i<m;i++){
		if(c[i]<bcnn){
			bcnn=c[i];
		}
	}
	printf("\nBCNN = %d ",bcnn);		
	return 0;
}
int max(int a,int b){
	if(a>b){
		return a;
	}
	else if(b>a){
		return b;
	}
}
