#include <stdio.h>

int min(int a,int b);
int main(void) {
	// your code goes here
	int a,b,c,uoc=1;
	scanf("%d",&a);
    scanf("%d",&b);
	scanf("%d",&c);
	for(int i=min(a,b);i>1;i--){
	    if(a%i==0 && b%i==0&& c%i==0){
	        uoc=i;
	        break;
	    }
	}
	printf("UCLN = %d",uoc);
	return 0;
}
int min(int a,int b){
    if(a>b){
        return b;
    }
    else if(a<b){
        return a;
    }
}
