#include <iostream>

using namespace std;
#define offset 97
int main()
{
    string s;
    cin >>s;
    int current =0;
    int left= 0;
    int right =0;
    int total = 0;
    for (int i=0;i<s.length();i++)
        {
            left = (s[i]-offset)-current;
            right = current - (s[i]-offset);
            left = left<0? left+26:left;
            right = right<0? right+26:right;
            total += left<right?left:right;
            current = (s[i]-offset);
        }
    cout<<total;
    
    return 0;
}
