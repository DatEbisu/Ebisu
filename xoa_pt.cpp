#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int length=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<length;i++){
		scanf("%d",&a[i]);
	}

	int v;
	printf("vi tri xoa: ");	
	scanf("%d",&v);	
	for(int i=v;i<n-1;i++){
			a[i]=a[i+1];
	}
	n--;
	
		
	for(int i=0;i<length-1;i++){
		printf("%d",a[i]);
	}		
	return 0;
}
