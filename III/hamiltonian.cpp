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
int *S;
int Sptr=0;
bool *visited;
bool hamiltonian (node **graph, int v, int n)
{
    S[Sptr++] = v;
    if(Sptr < n)
    {
        visited[v] = true;
        for (node *ptr = graph[v]; ptr; ptr=ptr->next)
            if(!visited[ptr->v] && hamiltonian(graph, v, n))
               return true;
        visited[v] = false;
    }
    else
    {
        return true;
    }
    Sptr--;
}
int main ()
{
    int n, m;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    S = new int [n];
    visited = new bool [n];
    cout<<hamiltonian(graph, 0, n);
    return 0;
}
