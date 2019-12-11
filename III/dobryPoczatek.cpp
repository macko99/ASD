#include <iostream>
using namespace std;
struct kolejka{
    kolejka *next;
    int v;
};
struct node{
    int v;
    node *next;
};
void put_queue (kolejka *&Q, int v)
{
    kolejka *nowy = new kolejka;
    nowy->v = v;
    nowy->next = Q;
    Q = nowy;
}
int pop_queue (kolejka *&Q)
{
    if (Q == nullptr)
        return -1;
    if(Q->next == nullptr)
    {
        int res = Q->v;
        Q = nullptr;
        return res;
    }
    kolejka *ptr = Q;
    while (ptr->next->next != nullptr)
        ptr=ptr->next;
    int res = ptr->next->v;
    delete ptr->next;
    ptr->next = nullptr;
    return res;
}
node **init_graph (int n, int m)
{
    int x,y;
    node **graph = new node *[n];
    for(int i=0; i<n; i++)
        graph[i] = nullptr;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        node *p = new node;
        p->v = y;
        p->next = graph[x];
        graph[x] = p;
    }
    return graph;
}
bool BFS (node **graph, int v, int n)
{
    int counter = 1;
    kolejka *Q = nullptr;
    bool *visited = new bool[n];
    for(int i =0; i<n; i++)
        visited[i] = false;
    visited[v] = true;
    put_queue(Q, v);
    while (Q != nullptr)
    {
        int x = pop_queue(Q);
        for(node *ptr = graph[x]; ptr != nullptr; ptr = ptr->next)
        {
            if(visited[ptr->v] == false)
            {
                visited[ptr->v] = true;
                counter ++;
                put_queue(Q, ptr->v);
            }
        }
    }
    if(counter == n) return true;
    return false;
}
int main ()
{
    int n, m, wynik =0;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    for(int i=0; i<n; i++)
        wynik +=BFS(graph, i, n);
    cout<<wynik;
    return 0;
}
