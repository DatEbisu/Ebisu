//=====Nhap mang n phan tu, tim mang con co tong lon nhat=======
#include<iostream>
using namespace std;
long long max(long long a,long long b){
	return a<b? b:a; //neu a be hon b thi tra ve b, nguoc lai thi a
}

int main(){
	int n;
	cout<<"nhap so phan tu n = ";
	cin>>n;
	cout<<"nhap mang: ";
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long sum1 = 0, sum2 = -100000000; 
	for(int i=0;i<n;i++){
		sum1+=arr[i];
		sum2 = max(sum1,sum2);
		if(sum1<0) sum1=0; //neu sum1 am thi reset sum1
	}
	cout<<"tong = "<<sum2;
	return 0;
}
