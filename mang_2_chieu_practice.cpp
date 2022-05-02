#include<stdio.h>
#define MAX_DONG 100
#define MAX_COT 100
void nhapMang2chieu(int a[][MAX_COT],int dong, int cot){
	for(int i=0;i<dong;i++){
		for(int j=0;j<cot;j++){
			scanf("%d ",&a[i][j]);
		}
	}
}
void xuatMang2chieu(int a[][MAX_COT],int dong, int cot){
	for(int i=0;i<dong;i++){
		for(int j=0;j<cot;j++){
			printf("%d ",a[i][j]);
		}
	printf("\n");	
	}
}
int tong_duongcheochinh(int a[][MAX_COT],int dong,int cot){
	int tong=0;
	for(int i=0;i<dong;i++){
		for(int j=0;j<cot;j++){
			if(i==j) tong+=a[i][j];
		}	
	}
	return tong;
}
int tong_duongcheophu(int a[][MAX_COT],int dong,int cot){
	int tong=0;
	for(int i=0;i<dong;i++){	
		for(int j=0;j<cot;j++){
			if((i+j)==(cot-1)) tong+=a[i][j];
		}	
	}
	return tong;
}
int main(){
//===KHAI BAO MAC DINH======================
//	int a[][3]={{1,2,3},{4,5,6},{3,4,5},{6,9,0}};

//======CHO NGUOI DUNG NHAP TU BAN PHIM=====
	int a[MAX_DONG][MAX_COT];
	int dong,cot;
	do{	
		printf("nhap dong");
		scanf("%d",&dong);
		printf("nhap cot");
		scanf("%d",&cot);				
	}while((0>=dong||dong>MAX_DONG||0>=cot||cot>MAX_COT));
	printf("nhap mang");
	nhapMang2chieu(a,dong,cot);		
	xuatMang2chieu(a,dong,cot);
	int tong_cheochinh, tong_cheophu;	
	tong_cheochinh = tong_duongcheochinh(a,dong,cot);
	tong_cheophu = tong_duongcheophu(a,dong,cot); 
	printf("\ntong_chinh = %d\n",tong_cheochinh);	
	printf("\ntong_phu = %d\n",tong_cheophu);	
	
	return 0;
}
