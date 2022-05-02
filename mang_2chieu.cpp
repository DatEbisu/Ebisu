#include<stdio.h>
#define N 100
void nhapmang2chieu(int mang[N][N],int hang,int cot){
	puts("Nhap cac phan tu cua mang");
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			scanf("	%d",&mang[i][j]);
		}
		printf("\n");	
	}
}
void xuatmang2chieu(int mang[N][N],int hang,int cot){
	puts("Mang tra ve:\n");
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			printf(" %d",mang[i][j]);
		}
		printf("\n");	
	}
}
int timkiem2chieu(int mang[N][N],int hang,int cot,int x){
	for(int i=0;i<hang;i++){
		for(int j=0;j<cot;j++){
			if(mang[i][j]==x){return 1;}
		}	
	}
	return 0;
}
int tinhtoan(int x){
	int ketqua;
	ketqua=x*100;
	return ketqua;
}
int main(){
	int arr[3][4]={	//[dong,cot]			
		{1,2,3,4},
		{5,0,5,4},
		{0,2,9,4}
	};
//	int m = sizeof(arr)/sizeof(int); //tim so phan tu
//	int n = sizeof(arr[0])/sizeof(int);//so cot
//	m/=n; //so hang
//	puts("Mang 2 chieu arr:\n");
//	xuatmang2chieu(arr,m,n);
	
	int brr[N][N],hangb,cotb,so,ketqua;
	puts("Nhap hang, cot:\n");
	scanf("%d%d",&hangb, &cotb);
	nhapmang2chieu(brr,hangb,cotb);
	xuatmang2chieu(brr,hangb,cotb);
	while(1){
	puts("Nhap so can tim:\n");
	scanf("%d",&so);
		if(so==-1){break;}
		else{
			if(timkiem2chieu(brr,hangb,cotb,so)==1){ketqua=tinhtoan(so);printf("tim thay %d\n",ketqua);}
			else {puts("khong ton tai\n");}
		}
	}
	return 0;
} 
