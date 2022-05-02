#include <iostream>
#define length 7
int* nhapMang(){
	static int arr[length];
	for(int i=0;i<length;i++){
		scanf("%d",&arr[i]);	
	}
	return arr;
}
int timMax(int arr[]){
	int max= arr[0];
	for(int i=0;i<length;i++){
		if(arr[i]>max){
			max=arr[i];
		}	
	}
	return max;		
}
void xuatMang(int arr[]){
	for(int i=0;i<length;i++){
		printf("%d ",arr[i]);	
	}
}
int main(void){
	int *arr;
	arr=nhapMang();
	//xuatMang(arr);
	int ketqua = timMax(arr);
	printf("\rmax = %d",ketqua);
}
