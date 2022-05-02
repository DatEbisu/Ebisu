#include<stdio.h>
int main(){
	int n;
	int giaiThua=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		giaiThua*=(n-i);	
	}
	int tong=giaiThua;
	printf("%d",giaiThua);
	return 0;
}
