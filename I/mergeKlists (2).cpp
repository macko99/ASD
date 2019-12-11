#include <iostream>
using namespace std;
#define n 20
#define heap_size 4
struct heapNode
{
    int val;
    int arr;
    int nextind;
};
int left(int i)     {return i*2;}
int right(int i)    {return i*2+1;}
void heapify_min(heapNode *heap, int i)
{
    int l=left(i), r=right(i), minind = i;
    if(l <= heap_size && heap[l].val < heap[minind].val) minind=l;
    if(r <= heap_size && heap[r].val < heap[minind].val) minind=r;
    if(minind != i){
        swap(heap[i],heap[minind]);
        heapify_min(heap, minind);
    }
}
int getroot(heapNode *heap, int arr[][n/heap_size])
{
    int res=heap[1].val;
    if(heap[1].nextind < (n/heap_size))
       {
           heap[1].val=arr[heap[1].arr][heap[1].nextind];
           heap[1].nextind++;
       }
    else
            heap[1].val=INT_MAX;
    heapify_min(heap, 1);
    return res;
}
int *mergeArrays (int arr[][n/heap_size])
{
    int *out=new int[n];
    heapNode *heap=new heapNode[heap_size+1];
    for(int i=0; i<heap_size; i++)
    {
        heap[i+1].val=arr[i][0];
        heap[i+1].arr=i;
        heap[i+1].nextind=1;
    }
    for(int i=heap_size/2; i>0; i--)
        heapify_min(heap, i);
    for(int i=0; i<n; i++)
        out[i]=getroot(heap, arr);
    delete heap;
    return out;
}
int main()
{
    int arr[heap_size][n/heap_size] =  {{1,3,5,6,8},
                                {1,2,3,4,5},
                                {2,4,4,8,9},
                                {2,3,5,7,10}};
    for(int i=0; i<n; i++)
        cout<<mergeArrays(arr)[i]<<" ";
    return 0;
}
