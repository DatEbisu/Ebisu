#include<stdio.h>
int main(){
	int arr[3];
	int n=3;
	int *p=arr;
	for (int i=0;i<n;i++){
		printf("a[%d]",i);
		scanf("%d",&p[i]);
	}

	for (int i=0;i<n;i++){
		printf("%d",p[i]);
	}	
}
