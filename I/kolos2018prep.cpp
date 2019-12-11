#include <iostream>
using namespace std;
int partition (int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void QuickSort(int arr[], int low, int high)
{
    if(low <high)
    {
        int m=partition(arr,low, high);
        QuickSort(arr,low, m-1);
        QuickSort(arr,m+1, high);
    }
}
int QuickSelect(int arr[], int low, int high, int i)
{
    if(low == high) return arr[low];
    int q=partition(arr, low, high);
    int ile=q-low+1;
    if(i == q) return arr[q];
    if(ile < i) return QuickSelect(arr, q+1, high, i-ile);
    return QuickSelect(arr, low, q-1, i);
}
int main()
{
    int arr[]={2,6,9,2,4,1,6,3};
    int n=sizeof(arr)/sizeof(int);
    cout<<QuickSelect(arr,0, n-1, 3)<<endl;
    QuickSort(arr,0, n-1);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
