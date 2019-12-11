#include <iostream>
using namespace std;
int maksymalny (int arr[], int n)
{
    int maxi=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]>maxi)
            maxi=arr[i];
    }
    return maxi;
}
void CountSort(int A[], int n, int k)
{
    int B[n], C[k];
    for(int i=0; i<k; i++) C[i]=0;
    for(int i=0; i<n; i++) C[A[i]]++;
    for(int i=1; i<k; i++) C[i]+=C[i-1];
    for(int i=n-1; i>=0; i--) B[--C[A[i]]]=A[i];
    for(int i=0; i<n; i++) A[i]=B[i];
}
void CountingSort(int A[], int n, int exp)
{
    int B[n], C[10];
    for(int i=0; i<10; i++) C[i]=0;
    for(int i=0; i<n; i++) C[(A[i]/exp)%10]++;
    for(int i=1; i<10; i++) C[i]+=C[i-1];
    for(int i=n-1; i>=0; i--) B[--C[(A[i]/exp)%10]]=A[i];
    for(int i=0; i<n; i++) A[i]=B[i];
}
void RadixSort(int arr[], int n)
{
    int maxi=maksymalny(arr, n);
    for(int exp=1; maxi/exp>0; exp*=10)
        CountingSort(arr, n,exp);
}
int main()
{
    int arr[]={5,2,3,7,1,2,8,1,2,3};
    RadixSort(arr, 10);
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    return 0;
}
