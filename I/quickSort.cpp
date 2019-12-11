#include <iostream>
using namespace std;
int part (int t[], int p, int v)
{
    int x=t[v];
    int i = p-1;
    for(int j=p; j<v; j++)
    {
        if(t[j] < x)
        {
            i++;
            swap(t[i],t[j]);
        }
    }
    swap(t[v],t[i+1]);
    return i+1;
}
void quickSort (int t[], int p, int v)
{
    if(p < v)
    {
        int q = part(t,p,v);
        quickSort(t,p,q-1);
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
