#include<stdio.h>
int max(int a,int b){
	if(a>b){
		return a;
	}
	else return b;
}
int main() {
   int a, b, i, uoc,boi;
   scanf("%d",&a);
   scanf("%d",&b);
   for(i = 1; i <= a || i <= b; i++) {
   if( a%i == 0 && b%i == 0 )
      uoc = i;
   }

   printf("USCLN = %d", uoc);
   
   
    int maxV = a*b;
    for(int i = max(a, b); i <= maxV; i++){
        if(i % a == 0 && i % b == 0){
            boi = i;
            break;
        }
    }
    printf("BCNN= %d",boi);   
   
   return 0;
}
