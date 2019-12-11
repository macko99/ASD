#include <iostream>
using namespace std;
struct stos{
    stos *next;
    int v;
};
stos *S = nullptr;
void push_stos (stos *&S, int v)
{
    stos *p = new stos;
    p->v = v;
    p->next = S;
    S = p;
}
int get_stos (stos *&S)
{
    if(S == nullptr)
        return -1;
    int res = S->v;
    S = S->next;
    return res;
}
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
bool DFS_top (node **graph, int *visited, int v)
{
    if (visited[v] == 0)
        return false;
    if(visited[v] == -1)
    {
        visited[v] = 0;
        for(node *p = graph[v]; p; p=p->next)
        {
            if(!DFS_top(graph, visited, p->v))
                return false;
        }
        visited[v] = 1;
        push_stos(S, v);
    }
    return true;
}
void topologiczne (node **graph, int n)
{
    int *visited = new int [n];
    for(int i=0; i<n; i++)
        visited[i] = -1;
    for(int i=0; i<n; i++)
        if(visited[i] == -1)
            if(!DFS_top(graph, visited, i))
                break;
    while(S)
        cout<<get_stos(S)<<" ";
}
int main ()
{
    int n, m;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    topologiczne(graph, n);
    return 0;
}
