#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main(){
	string s;
	int tongVong,kiemTra1,kiemTra2,i,j;
	cout<<"nhap ten: ";
	fflush(stdin);   
	getline(cin,s);
	//chu o giua co cach chu dau x-97, cach chu cuoi 122-x
	for(i=0;i<s.length();i++){
		
		for(j=i+1;j<s.length();j++){	//za = 25 bi loi
			kiemTra1=int(s[j])-97;
			kiemTra2=122-int(s[j]);
			if(kiemTra1<kiemTra2){
				tongVong+=abs(int(s[j])-int(s[i])); //gan chu a
				kiemTra1=0;
				kiemTra2=0;
				break;
			}
			if (kiemTra1>kiemTra2){ //gan chu z
				tongVong+=abs(122-int(s[j])+int(s[i])-97+1);
				kiemTra1=0;
				kiemTra2=0;
				break;
			}
		}
	}
	cout<<tongVong;
	return 0;
}
