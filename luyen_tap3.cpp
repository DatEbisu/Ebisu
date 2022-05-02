#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n>50){
		printf("nhap lai n= ");
		scanf("%d",&n);
	}
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int tong=0,dem=0;
	for(int i=0;i<n;i++){
		if(a[i]%3==0){
			dem++;	
			tong+=a[i];
		}
	}
	float tb;
	tb=float(tong/dem);
	printf("trung binh = %5.2f",tb);
	
	int x;
	printf("so chen = ");
 	scanf("%d",&x);
 	int v;
	printf("vi tri chen = ");
 	scanf("%d",&v);
	for(int i=n-1;i>=v;i--){
		a[i+1]=a[i];
	}
	a[v]=x; 
	for(int i=0;i<n+1;i++){
		printf("%d",a[i]);		
	}	
	return 0;
}
