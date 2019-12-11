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
        cin>>x>>y;
        node *p = new node;
        p->w=0;
        p->v = y;
        p->next = graph[x];
        graph[x] = p;
    }
    return graph;
}
bool DFScycle (node **graph, int *visited, int i)
{
    visited[i] = 0;
    for(node *p = graph[i]; p; p=p->next)
    {
        if(visited[p->v] == 0) return true;
        if(visited[p->v] == -1 && DFScycle(graph, visited, p->v))
            return true;
    }
    visited[i] = 1;
    return false;
}
bool isCycle (node **graph, int n)
{
    int *visited = new int [n];
    for (int i=0; i<n; i++)
    visited[i] = -1;
    for (int i=0; i<n; i++)
    {
        if(visited[i] == -1 && DFScycle(graph, visited, i))
            return true;
    }
    return false;
}
int main ()
{
    int n, m;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    cout<<isCycle(graph, n);
    return 0;
}
