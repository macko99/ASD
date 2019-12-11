#include <iostream>
using namespace std;
int heap_size=7;
int parent(int i) {return i/2;}
int left (int i) {return i*2;}
int right (int i) {return i*2+1;}

void heapify_max(int heap[], int i)
{
    int l=left(i), r=right(i), min_ind=i;
    if(l<=heap_size && heap[l]>heap[min_ind]) min_ind=l;
    if(r<=heap_size && heap[r]>heap[min_ind]) min_ind=r;
    if(min_ind != i)
    {
        swap(heap[i], heap[min_ind]);
        heapify_max(heap, min_ind);
    }
}
void build_max(int heap[])
{
    for(int i=heap_size/2; i>0; i--)
        heapify_max(heap, i);
}
void insert_max (int heap[], int val)
{
    heap_size++;
    heap[heap_size]=val;
    int i=heap_size;
    while(i>1 && heap[i]>heap[parent(i)])
    {
        swap(heap[i], heap[parent(i)]);
        i=parent(i);
    }
}
int get_max(int heap[])
{
    int res=heap[1];
    heap[1]=heap[heap_size];
    heap_size--;
    heapify_max(heap, 1);
    return res;
}
void HeapSort(int heap[])
{
    build_max(heap);
    int tmp_size=heap_size;
    for(int i=heap_size; i>1; i--)
    {
        swap(heap[1], heap[i]);
        heap_size--;
        heapify_max(heap, 1);
    }
    heap_size=tmp_size;
}
int main()
{
    int heap[]={-1,4,5,2,7,8,1,0};
    HeapSort(heap);
    for(int i=1; i<=heap_size; i++)
        cout<<heap[i]<<" ";
    return 0;
}
