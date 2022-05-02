#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int length=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<length;i++){
		scanf("%d",&a[i]);
	}
	int x;
	printf("so them: ");	
	scanf("%d",&x);	
	int v;
	printf("vi tri them: ");	
	scanf("%d",&v);	


	for(int i=n-1;i>=v;i--){
		a[i+1]=a[i];
	}
	a[v]=x;	
	n++;	

	
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}		
	return 0;
}
