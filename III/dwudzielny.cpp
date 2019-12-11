#include <iostream>
using namespace std;
struct node{
    int v, w;
    node *next;
};
struct queue{
    queue *next;
    int v;
};
void put_queue (queue *&Q, int v)
{
    queue *nowy = new queue;
    nowy->next = Q;
    nowy->v = v;
    Q = nowy;
}
int pop_queue (queue *&Q)
{
    if(Q == nullptr)
        return -1;
    int res = Q->v;
    Q = Q->next;
    return res;
}
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
bool dwudzielny (node **graph, int n)
{
    int *visited = new int [n];
    for (int i=0; i<n; i++)
        visited[i] = 0;
    queue *Q = nullptr;
    for (int i=0; i<n; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            put_queue(Q, i);
            while (Q)
            {
                int x = pop_queue(Q);
                for(node *ptr = graph[x]; ptr; ptr=ptr->next)
                {
                    if(visited[ptr->v] == visited[x])
                        return false;
                    if(visited[ptr->v] == 0)
                    {
                        visited[ptr->v] = -visited[x];
                        put_queue(Q, ptr->v);
                    }
                }
            }
        }
    }
    return true;
}
int main ()
{
    int n, m;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    cout<<dwudzielny(graph, n);
    return 0;
}
