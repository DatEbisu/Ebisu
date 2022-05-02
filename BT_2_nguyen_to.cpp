#include<stdio.h>
#include<conio.h>
int kiemTraNguyenTo(int n){
	if(n==2){
		return true;
	}
	else{
		if(n%2==0){
			return false;
		}
		else{
			for(int i=2;i<n;i++){
				if(n%i==0){return false;}
			}
		}
	}
	return true;
}
main()
{
    int n,i,j,dem;
    bool check;
    printf("Nhap n="); 
    scanf("%d",&n);

	for(int i=2;i<=n;i++){
		check=kiemTraNguyenTo(i);
		if(check){printf("%d",i);}		
	}

}
