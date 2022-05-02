#include<iostream>
using namespace std;
void combinationUtil(int arr[], int data[],
                    int start, int end,
                    int index, int r);
 
// The main function that prints
// all combinations of size r
// in arr[] of size n. This function
// mainly uses combinationUtil()
void printCombination(int arr[], int n, int r)
{
    // A temporary array to store
    // all combination one by one
    int data[r];
    // Print all combination using
    // temporary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r);
}
void combinationUtil(int arr[], int data[],
                    int start, int end,
                    int index, int r)
{
    // Current combination is ready
    // to be printed, print it
    if (index == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }
 
    // replace index with all possible
    // elements. The condition "end-i+1 >= r-index"
    // makes sure that including one element
    // at index will make a combination with
    // remaining elements at remaining positions
    for (int i = start; i <= end &&
        end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1,
                        end, index+1, r);
    }
}
int main(){

	int na,nb,k,m,count;
	cin>>na;
	cin>>nb;
	cin>>k;
	cin>>m;
	int A[na],B[nb];
	for(int i=0;i<na;i++){
		cin>>A[i];
	}
	for(int i=0;i<nb;i++){
		cin>>B[i];
	}
	printCombination(A, na, k);
	printCombination(B, nb, m);

	return 0;
}
