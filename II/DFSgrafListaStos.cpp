#include <iostream>
using namespace std;
const int n = 5, m = 4;
struct node
{
    node *next;
    int v;
};
struct stos
{
    stos *next;
    int v;
};
void push_stos (stos *&S, int v)
{
    stos *nowy = new stos;
    nowy->next = S;
    nowy->v = v;
    S=nowy;
}
int get_stos (stos *&S)
{
    if(S == nullptr)
        return -1;
    int res = S->v;
    S = S->next;
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
void DFS (node **tab, int v)
{
    stos *S = nullptr;
    bool *visited = initVisited();
    visited[v] = true;
    push_stos(S, v);
    while (S != nullptr)
    {
        int x = get_stos(S);
        cout<<x<<" ";
        for(node *ptr = tab[x]; ptr != nullptr; ptr = ptr->next)
        {
            if(visited[ptr->v] == false)
            {
                visited[ptr->v] = true;
                push_stos(S, ptr->v);
            }
        }
    }
}
int main()
{
    node **tab = initTab();
    printGraph(tab);
    DFS(tab, 0);
}
