#include <iostream>
using namespace std;
struct kolejka{
    kolejka *next;
    int v;
};
struct node{
    int v, w;
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
int **init_macierz (int n, int m)
{
    int x,y,w;
    int **macierz = new int* [n];
    for(int i=0; i<n; i++){
        macierz[i] = new int[n];
        for(int j=0; j<n; j++)
            macierz[i][j] = -1;
    }
    for(int i=0; i<m; i++){
        cin>>x>>y>>w;
        macierz[x][y] = w;
    }
    return macierz;
}
void print_graph (node **graph, int n)
{
    for(int i=0; i<n; i++){
        cout<<i <<": ";
        for(node *ptr = graph[i]; ptr; ptr=ptr->next)
            cout<<ptr->v<<" ";
        cout<<endl;
    }
}
void print_macierz (int **macierz, int n)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<macierz[i][j]<<" ";
        cout<<endl;
    }
}
void BFS_graph (node **graph, int v, int n)
{
    kolejka *Q = nullptr;
    bool *visited;
    for(int i=0; i<n; i++)
        visited[i] = false;
    visited[v] = true;
    put_queue(Q, v);
    while (Q != nullptr)
    {
        int x = pop_queue(Q);
        cout<<x<<" ";
        for(node *ptr = graph[x]; ptr != nullptr; ptr = ptr->next)
        {
            if(visited[ptr->v] == false)
            {
                visited[ptr->v] = true;
                put_queue(Q, ptr->v);
            }
        }
    }
}
void BFS_macierz (int **macierz, int v, int n)
{
    kolejka *Q = nullptr;
    bool *visited;
    for(int i=0; i<n; i++)
        visited[i] = false;
    visited[v] = true;
    put_queue(Q, v);
    while (Q != nullptr)
    {
        int x = pop_queue(Q);
        cout<<x<<" ";
        for(int i=0; i<n; i++)
        {
            if(macierz[x][i] != -1 && visited[i] == false)
            {
                visited[i] = true;
                put_queue(Q, i);
            }
        }
    }
}
int main ()
{
    int n, m;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    //int **macierz = init_macierz (n, m);
    //print_graph(graph, n);
    //print_macierz(macierz, n);
    BFS_graph(graph, 0, n);
    //BFS_macierz(macierz, 0, n);
    return 0;
}
