#include <iostream>
using namespace std;
const int n = 4, m = 3;
struct node
{
    node *next;
    int v;
};
struct queue
{
    int v;
    queue *next;
};
void put_queue (queue *&Q, int v)
{
    queue *nowy = new queue;
    nowy->v = v;
    nowy->next = Q;
    Q = nowy;
}
int pop_queue (queue *&Q)
{
    if (Q == nullptr)
        return -1;
    if(Q->next == nullptr)
    {
        int res = Q->v;
        Q = nullptr;
        return res;
    }
    queue *ptr = Q;
    while (ptr->next->next != nullptr)
        ptr=ptr->next;
    int res = ptr->next->v;
    delete ptr->next;
    ptr->next = nullptr;
    return res;
}
void insertEdge (node **tab, int v1, int v2)
{
    node *p = new node;
    p->v = v2;
    p->next = tab[v1];
    tab[v1] = p;
}
bool *initVisited ()
{
    bool *visited = new bool [n];
    for (int i=0; i<n; i++)
        visited[i] = false;
    return visited;
}
node ** initTab ()
{
    node **tab = new node *[n];
    for (int i=0; i<n; i++)
        tab[i] = nullptr;
    int v1, v2;
    for(int i = 0; i<m; i++)
    {
        cin >>v1>>v2;
        insertEdge(tab, v1, v2);
    }
    return tab;
}
void printGraph (node **tab)
{
    for (int i=0; i<n; i++)
     {
         node *ptr = tab[i];
         while (ptr != nullptr)
         {
             cout<<i<<" - "<<ptr->v<<endl;
             ptr=ptr->next;
         }
     }
}
void BFS (node **tab, int v)
{
    queue *Q = nullptr;
    bool *visited = initVisited();
    visited[v] = true;
    put_queue(Q, v);
    while (Q != nullptr)
    {
        int x = pop_queue(Q);
        cout<<x<<" ";
        for(node *ptr = tab[x]; ptr != nullptr; ptr = ptr->next)
        {
            if(visited[ptr->v] == false)
            {
                visited[ptr->v] = true;
                put_queue(Q, ptr->v);
            }
        }
    }
}
int main()
{
    node **tab = initTab();
    printGraph(tab);
    BFS(tab, 0);
}
