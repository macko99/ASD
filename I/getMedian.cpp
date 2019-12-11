#include <iostream>
using namespace std;
#define max_size max_heap[0]
#define min_size min_heap[0]
#define heap_size heap[0]
int left(int root){
    return root*2;
}
int right(int root){
    return root*2 + 1;
}
int parent(int v){
    return v/2;
}
void heapify_min(int* heap, int v)
{
    int l = left(v);
    int r = right(v);
    int min_ind = v;

    if(l <= heap_size && heap[l] < heap[min_ind]) min_ind=l;
    if(r <= heap_size && heap[r] < heap[min_ind]) min_ind=r;
    if(min_ind != v){
        swap(heap[min_ind], heap[v]);
        heapify_min(heap, min_ind);
    }
}
void heapify_max(int* heap, int v)
{
    int l = left(v);
    int r = right(v);
    int min_ind = v;

    if(l <= heap_size && heap[l] > heap[min_ind]) min_ind=l;
    if(r <= heap_size && heap[r] > heap[min_ind]) min_ind=r;
    if(min_ind != v){
        swap(heap[min_ind], heap[v]);
        heapify_max(heap, min_ind);
    }
}
void InsertMax(int* heap, int k){
    heap_size++;
    heap[heap_size] = k;
    int i = heap_size;
    while(i>1 && heap[i] < heap[parent(i)])
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}
void InsertMin(int* heap, int k){
    heap_size++;
    heap[heap_size] = k;
    int i = heap_size;
    while(i>1 && heap[i] < heap[parent(i)])
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}
void Balance(int* max_heap, int* min_heap){
    if( (max_size == min_size) || (max_size + 1 == min_size) || (min_size + 1 == max_size) )
        return;
    if( max_size > min_size )
    {
        InsertMin(min_heap, max_heap[1]);
        swap(max_heap[1], max_heap[max_size]);
        max_size--;
        heapify_max(max_heap, 1);
    }
    else
    {
        InsertMax(max_heap, min_heap[1]);
        swap(min_heap[1], min_heap[min_size]);
        min_size--;
        heapify_min(min_heap, 1);
    }
}
int main(){
    int n,k,t;
    cin>>n;
    int min_heap[(n+1)/2 + 2];
    int max_heap[(n+1)/2 + 2];
    min_size = 0;
    max_size = 0;
    for(int i=0; i<n; i++)
    {
        cin>>t;
        if(t==0)
            cout<<GetMedian(max_heap, min_heap)<<endl;
        else
        {
            cin>>k;
            Insert(max_heap, min_heap, k);
        }
    }
    return 0;
}
