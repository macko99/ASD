#include <iostream>
using namespace std;
int heap_size=9;
int parent (int i){
    return i/2;
}
int right (int i){
    return i*2+1;
}
int left (int i){
    return i*2;
}
void heapify_min (int *heap, int i)
{
    int l = left(i), r = right(i), min_ind = i;
    if(l <= heap_size && heap[l] < heap[min_ind]) min_ind = l;
    if(r <= heap_size && heap[r] < heap[min_ind]) min_ind = r;
    if(min_ind != i)
    {
        swap(heap[min_ind], heap[i]);
        heapify_min(heap, min_ind);
    }
}
void heapify_max (int *heap, int i)
{
    int l = left(i), r = right(i), max_ind = i;
    if(l <= heap_size && heap[l] > heap[max_ind]) max_ind = l;
    if(r <= heap_size && heap[r] > heap[max_ind]) max_ind = r;
    if(max_ind != i)
    {
        swap(heap[max_ind], heap[i]);
        heapify_max(heap, max_ind);
    }
}
void insertMax (int *heap, int val)
{
    heap_size++;
    heap[heap_size] = val;
    int i= heap_size;
    while(i > 1 && heap[i] > heap[parent(i)])
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}
void insertMin (int *heap, int val)
{
    heap_size++;
    heap[heap_size] = val;
    int i= heap_size;
    while(i > 1 && heap[i] < heap[parent(i)])
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}
void wypisz (int *heap)
{
    int licznik=1, tmp = licznik;
    for(int i=1; i<=heap_size; i++)
    {
        cout<<heap[i]<<" ";
        tmp--;
        if(tmp == 0)
        {
            cout<<endl;
            licznik*=2;
            tmp=licznik;
        }
    }
}
void budujMax (int *heap)
{
    for(int i=heap_size/2; i>0; i--)
        heapify_max(heap, i);
}
void budujMin (int *heap)
{
    for(int i=heap_size/2; i>0; i--)
        heapify_min(heap, i);
}
void HeapSort(int *heap)
{
    int tmp_size=heap_size;
    budujMax(heap);
    for(int i=heap_size; i>1; i--)
    {
        swap(heap[1],heap[i]);
        heap_size--;
        heapify_max(heap,1);
    }
    heap_size=tmp_size;
}
int main()
{
    int heap[]={10,1,5,8,4,5,2,7,3,9};
    HeapSort(heap);
    wypisz(heap);
    return 0;
}
