#include <iostream>
using namespace std;
struct node{
    node *next;
    int v, w;
};
struct wierz{
    int dist, v, parent;
};

wierz **heap;
int heap_size;
void heapify (int i)
{
    int l = i*2, r = i*2+1, max_ind = i;
    if(l <= heap_size && heap[l]->dist > heap[max_ind]->dist) max_ind = l;
    if(r <= heap_size && heap[r]-if(>dist > heap[max_ind]->dist) max_ind = r;
    if(max_ind != i){
        swap(heap[max_ind], heap[i]);
        heapify(max_ind);
    }
}
void HeapSort()
{
    int tmp_size=heap_size;
    for(int i=heap_size/2; i>0; i--)
        heapify(i);
    for(int i=heap_size; i>1; i--){
        swap(heap[1],heap[i]);
        heap_size--;
        heapify(1);
    }
    heap_size=tmp_size;
}
void insert (wierz *w)
{
    heap_size++;
    heap[heap_size] = w;
}
wierz *front ()
{
    return heap[1];
}
void pop ()
{
    heap[1] = heap[heap_size--];
}
node ** initGraf (int n, int m)
{
    node **graf = new node *[n];
    for (int i=0; i<n; i++)
        graf[i] = nullptr;
    int v1, v2, w;
    for(int i = 0; i<m; i++){
        cin >>v1>>v2>>w;
        node *p = new node;
        p->v = v2;
        p->w = w;
        p->next = graf[v1];
        graf[v1] = p;
    }
    return graf;
}
void dijkstra (node **graf, int n, int start)
{
    heap = new wierz*[n+1];
    heap_size = 0;
    bool *zbiorS = new bool [n];
    wierz *wierzcholki = new wierz[n];
    for(int i=0; i<n; i++){
        zbiorS[i] = false;
        wierzcholki[i].dist = INT_MAX;
        wierzcholki[i].v = i;
        wierzcholki[i].parent = -1;
        insert (&wierzcholki[i]);
    }
    wierzcholki[start].dist = 0;

    for(int i=0; i<n; i++)
    {
        HeapSort();
        wierz *u = front();
        pop();
        zbiorS[u->v] = true;
        for(node *ptr = graf[u->v]; ptr; ptr = ptr->next){
            if(!zbiorS[ptr->v] && (wierzcholki[ptr->v].dist > wierzcholki[u->v].dist + ptr->w)){
                wierzcholki[ptr->v].dist = wierzcholki[u->v].dist + ptr->w;
                wierzcholki[ptr->v].parent = u->v;
            }
        }
    }
    int *Stack = new int [n];
    int stack_size = 0;
    for(int i=0; i<n; i++)
    {
        cout<<i <<": ";
        for(int j = i; j > -1; j = wierzcholki[j].parent)
            Stack[stack_size++] = j;
        while (stack_size)
            cout<<Stack[--stack_size] <<" ";
        cout <<" ,dist: " <<wierzcholki[i].dist<<endl;
    }
}
int main()
{
    int n, m, start;
    cin >>start>>n >>m;
    node **graf = initGraf(n, m);

    dijkstra(graf, n, start);
    return 0;
}
