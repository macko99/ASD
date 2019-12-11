#include<iostream>
using namespace std;
int partition (int t[], int l, int p)
{
    int x=t[p];
    int i=l-1;
    for(int j=l; j<p; j++)
    {
        if(t[j]<x)
        {
            i++;
            swap(t[i],t[j]);
        }
    }
    swap(t[p],t[i+1]);
    return i+1;
}
void QuickSort(int t[], int l, int p)
{
    if(l<p)
    {
        int q=partition(t, l, p);
        QuickSort(t, l, q-1);
        QuickSort(t, q+1, p);
    }
}
int SumBetween (int T[], int from, int to, int n)
{
    int res=0;
    QuickSort(T, 0, n-1);
    for(int i=from; i<=to; i++)
        res+=T[i];
    return res;
}
int main()
{
    int T[7]={2,6,1,5,9,2,0};
    cout<<SumBetween(T, 2, 5, 7) <<endl;
    for(int i=0; i<7; i++)
        cout<<T[i]<<" ";
    return 0;
}
