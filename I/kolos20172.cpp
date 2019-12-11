#include <iostream>
using namespace std;
struct fragment
{
    double srednia;
    int lewy;
    int prawy;
};
int partition(fragment *arr, int low, int high)
{
    fragment pivot = arr[high];
    int i=low-1;
    for(int j=low; j<high; j++){
        if(arr[j].srednia>pivot.srednia){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}
void QuickSort(fragment *arr, int low, int high)
{
    if(low < high){
        int m=partition(arr, low, high);
        QuickSort(arr, low, m-1);
        QuickSort(arr, m+1, high);
    }
}
void sortNN (int A[], int n)
{
    fragment *arr=new fragment[n];
    int j=0;
    for(int i=0; i<n; i++)
    {
        arr[i].lewy=j;
        arr[i].prawy=j+n-1;
        double sum=0;
        for(int k=j; k<j+n; k++)
            sum+=A[k];
        arr[i].srednia=(sum/n);
        j+=n;
    }
    QuickSort(arr, 0, n-1);
    int k=0;
    int out[n*n];
    for(int i=0; i<n; i++)
    {
        for(int j=arr[i].prawy; j>=arr[i].lewy; j--)
            out[k++]=A[j];
    }
    for(int i=0; i<n*n; i++)
        A[i]=out[i];
}
int main()
{
    int n=4;
    int A[n*n]={2,3,4,8,1,1,1,2,9,10,12,13,13,13,15,16};
    for(int i=0; i<n*n; i++)
        cout<<A[i]<<" ";
    cout <<endl;
    sortNN(A, n);
    for(int i=0; i<n*n; i++)
        cout<<A[i]<<" ";
    cout <<endl;
    return 0;
}
