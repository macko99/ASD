#include <iostream>
using namespace std;
int part (int t[], int p, int v)
{
    int x=t[p];
    int i = p, j=v;
    while(1)
    {
        while(t[j]>x)
            j--;
        while(t[i]<x)
            i++;
        if(i<j)
        {
            swap(t[i],t[j]);
            i++; j--;
        }
        else
            return j;
    }
}
void quickSort (int t[], int p, int v)
{
    if(p < v)
    {
        int q = part(t,p,v);
        quickSort(t,p,q);
        quickSort(t,q+1,v);
    }
}
int main()
{
    int t[] = {10,80,30,90,40,50,70};
    quickSort(t,0,6);
    for(int i=0; i<7; i++)
        cout<<t[i]<<" ";
    return 0;
}
