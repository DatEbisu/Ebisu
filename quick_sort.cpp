#include<stdio.h>
 
 
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
 
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
/* Hàm th?c hi?n gi?i thu?t quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là ch? s? noi ph?n t? này dã d?ng dúng v? trí
         và là ph?n t? chia m?ng làm 2 m?ng con trái & ph?i */
        int pi = partition(arr, low, high);
 
        // G?i d? quy s?p x?p 2 m?ng con trái và ph?i
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Hàm xu?t m?ng */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
 
int main()
{
    int arr[] = {10, 80, 90, 30, 40, 50, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("n= %d\n",n);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
