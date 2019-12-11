#include <iostream>
using namespace std;
struct stos{
    stos *next;
    int v;
};
void put_stos (stos *&S, int v)
{
    stos *p = new stos;
    p->v = v;
    p->next = S;
    S = p;
}
int top_stos (stos *&S)
{
    if(S == nullptr)
        return -1;
    return S->v;
}
int get_stos (stos *&S)
{
    if (S == nullptr)
        return -1;
    int res = S->v;
    S = S->next;
    return res;
}
stos *S = nullptr;
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
bool DFScycle (node **graph, bool *visited, int i, int w)
{
    visited[i] = true;
    for(node *p = graph[i]; p; p=p->next)
    {
        if(p->v != top_stos(S))
        {
            put_stos(S, p->v);
            if(p->v == w) return true;
            if(!visited[p->v] && DFScycle(graph, visited, p->v, w))
                return true;
            get_stos(S);
        }
    }
    return false;
}

void printCycle (node **graph, int n)
{
    bool *visited = new bool [n];
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n; i++)
            visited[i] = false;
        if(DFScycle(graph, visited, j, j)){
            while(S)
                cout<<get_stos(S)<<" ";
            cout<<j<<endl;
        }
    }
}
int main ()
{
    int n, m;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    printCycle(graph, n);
    return 0;
}
