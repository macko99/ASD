#include <iostream>
using namespace std;
struct stos{
    stos *next;
    int v;
};
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
int DFS_skl (node **graph, int n)
{
    int skladowe = 0;
    stos *S = nullptr;
    int *visited = new int [n];
    for(int i=0; i<n; i++)
        visited[i] = 0;
    for(int i=0; i<n; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = ++skladowe;
            push_stos(S, i);
            while (S)
            {
                int x = get_stos(S);
                for(node *ptr = graph[x]; ptr; ptr=ptr->next){
                    if(visited[ptr->v] == 0){
                        visited[ptr->v] = skladowe;
                        push_stos(S, ptr->v);
                    }
                }
            }
        }
    }
    return skladowe;
}

int main ()
{
    int n, m;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    cout<<DFS_skl(graph, n);
    return 0;
}
