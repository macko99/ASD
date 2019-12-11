#include <iostream>
using namespace std;
int inversions (int t[], int n)
{
    int res=0;
    for (int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(t[i]>t[j])
                res++;
    return res;
}
void InserionSort(int *arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int key=arr[i], j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int n=5;
    int t[n]={1,20,6,4,5};
    //cout<<inversions(t, n);
    InserionSort(t, n);
    for(int i=0; i<n; i++)
        cout<<t[i]<<" ";
    return 0;
}
