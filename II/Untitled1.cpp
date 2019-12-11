#include <iostream>
using namespace std;
const int n=5, m =4;
struct node
{
    node *next;
    int v;
};
void inserdEdge (node **tab, int v1, int v2)
{
    node *p = new node;
    p->v = v2;
    p->next = tab[v1];
    tab[v1] = p;
}
void printGraph (node **tab)
{
    for (int i=0; i<n; i++)
    {
        node *ptr = tab[i];
        while (ptr)
        {
            cout<<i<<" - "<<ptr->v<<" ";
            ptr = ptr->next;
        }
    }
    cout<<endl;
}
void printMacierz(bool **macierz)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(macierz[i][j] == 1)
                cout<<i <<" - "<<j<<" ";
        }
    }
    cout<<endl;
}
node **initTAB ()
{
    node **tab = new node*[n];
    for (int i=0; i<n; i++)
        tab[i] = nullptr;
    int v1, v2;
    for(int i=0; i<m; i++)
    {
        cin>>v1>>v2;
        inserdEdge(tab, v1, v2);
    }
    return tab;
}
bool **initMacierz()
{
    bool **macierz = new bool*[n];
    for(int i=0; i<n; i++)
        macierz[i] = new bool [n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        macierz[i][j] = 0;
    int v1, v2;
    for(int i=0; i<m; i++)
    {
        cin>>v1>>v2;
        macierz[v1][v2] = 1;
    }
    return macierz;
}
bool *initVisited ()
{
    bool *visited = new bool [n];
    for(int i=0; i<n; i++)
        visited[i] = 0;
    return visited;
}
void DFSMacierz (bool **macierz, int v)
{
    bool *visited = initVisited();
    visited[v] = 1;
    cout<<v<<" ";
    for(int i=0; i<n; i++)
    {
        if(macierz[v][i] == 1 && visited[i]== 0)
            DFSMacierz(macierz, i);
    }
}
void DFSLista (node **tab, int v)
{
    bool *visited = initVisited();
    visited[v] =1;
    cout<<v<<" ";
    node *ptr = tab[v];
    while (ptr)
    {
        if(visited[ptr->v] == 0)
            DFSLista(tab, ptr->v);
        ptr=ptr->next;
    }
}
struct queue
{
    int v;
    queue *next;
};
void put_queue (queue *&Q, int v)
{
    queue *nowy = new queue;
    nowy->v= v;
    nowy->next = Q;
    Q= nowy;
}
int get_queue (queue *&Q)
{
    if(Q == nullptr)
        return -1;
    if(Q->next == nullptr)
    {
        int res = Q->v;
        Q = nullptr;
        return res;
    }
    queue *ptr = Q;
    while (ptr->next->next != nullptr)
        ptr = ptr->next;
    int res = ptr->next->v;
    delete ptr->next;
    ptr->next = nullptr;
    return res;
}
void BFSLista (node **tab, int v)
{
    bool *visited = initVisited();
    queue *Q = nullptr;
    visited[v] == 1;
    put_queue(Q, v);
    while (Q)
    {
        int x = get_queue(Q);
        cout<<x<<" ";
        node *ptr = tab[x];
        while (ptr)
        {
            if(visited[ptr->v] == 0)
            {
                visited[ptr->v] =1;
                put_queue(Q, ptr->v);
            }
            ptr = ptr->next;
        }
    }
}
void BFSMacierz (bool **macierz, int v)
{
    bool *visited = initVisited();
    queue *Q = nullptr;
    visited[v] = 1;
    put_queue(Q, v);
    while (Q)
    {
        int x = get_queue(Q);
        cout<<x<<" ";
        for(int i=0; i<n; i++)
        {
            if(macierz[v][i] == 1 && visited[i] == 0)
                DFSMacierz(macierz, i);
        }
    }
}
int main()
{
    node **tab = initTAB();
    bool **macierz = initMacierz();
    printGraph(tab);
    printMacierz(macierz);
    DFSLista(tab, 0);
    cout<<endl;
    DFSMacierz(macierz, 0);
    cout<<endl;
    BFSLista(tab, 0);
    cout<<endl;
    BFSMacierz(macierz, 0);
}
