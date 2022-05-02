#include<iostream>
using namespace std;
int main(void){
	int *pc,c;
	c=5;
	pc=&c;
	cout<<c<<endl;
	cout<<*pc<<endl;
	
	*pc=1;
	cout<<c<<endl;
	cout<<*pc<<endl;	
	return 0;
}
