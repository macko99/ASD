#include <iostream>
using namespace std;
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[], int n, int exp)
{
    int out[n];
    int c[10];
    for (int i=0; i<10; i++) c[i]=0;
    for (int i=0; i<n; i++) c[(arr[i]/exp)%10]++;
    for (int i=1; i<10; i++) c[i]+=c[i-1];
    for (int i=n-1; i>=0; i--) out[--c[(arr[i]/exp)%10]]=arr[i];
    for (int i=0; i<n; i++) arr[i]=out[i];
}
void radixsort(int arr[], int n)
{
    int maxi = getMax(arr, n);
    for (int exp=1; maxi/exp>0; exp*=10)
        countSort(arr, n, exp);
}
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
