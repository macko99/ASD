#include <iostream>
using namespace std;
struct node{
    int v, w;
    node *next;
};
node **init_graph (int n, int m)
{
    int x,y,w;
    node **graph = new node *[n];
    for(int i=0; i<n; i++)
        graph[i] = nullptr;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        node *p = new node;
        p->w=w;
        p->v = y;
        p->next = graph[x];
        graph[x] = p;
    }
    return graph;
}
int *stos;
int stos_size = 0;
bool DFS (node **graph, int v, int n, int stop, int last_w)
{
    stos[stos_size++] = v;
    if(v == stop) return true;
    bool *visited = new bool [n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    visited[v] = true;
    for(node *ptr = graph[v]; ptr; ptr = ptr->next)
        if(visited[ptr->v] == false && ptr->w < last_w)
            return DFS(graph, ptr->v, n, stop, ptr->w);
    stos_size--;
    return false;
}
int main ()
{
    int n, m;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    stos = new int[n];
    cout<<DFS(graph, 0, n, 4, INT_MAX)<<endl;
    while(stos_size)
        cout<<stos[--stos_size]<<" ";
    return 0;
}
