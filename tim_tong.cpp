#include<iostream>
using namespace std;
int main(void){
	int n;
	cout<<"nhap so phan tu n = ";
	cin>>n;
	cout<<"nhap mang: ";
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int x;
	cout<<"nhap so can tim x = ";
	cin>>x;
	bool kiemTra=false;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((arr[i]+arr[j])==x){
				kiemTra=true;
				break;	
			}	
		}
	}
	cout<<"ket qua kiem tra: "<<(kiemTra?"true":"false");
	return 0;
}
