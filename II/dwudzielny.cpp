#include <iostream>
using namespace std;
const int n = 5, m = 5;
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
int *initVisited ()
{
    int *visited = new int [n];
    for (int i=0; i<n; i++)
        visited[i] = 0;
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
bool dwudzielny (node **tab)
{
    queue *Q = nullptr;
    int *color = initVisited();
    for(int i=0; i<n; i++)
    {
        if(color[i] == 0)
        {
            color[i] = 1;
            put_queue(Q, i);
            while (Q != nullptr)
            {
                int x = pop_queue(Q);
                for(node *ptr = tab[x]; ptr != nullptr; ptr=ptr->next)
                {
                    if(color[ptr->v] == color[x])
                        return false;
                    if(color[ptr->v] == 0)
                    {
                        color[ptr->v] = -color[x];
                        put_queue(Q, ptr->v);
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    node **tab = initTab();
    printGraph(tab);
    if (dwudzielny(tab)) cout<<"TAK";
    else cout<<"NIE";
}
