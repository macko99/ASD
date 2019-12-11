#include <iostream>
using namespace std;
const int n = 5, m = 4;
struct node
{
    node *next;
    int v;
};
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
    bool *visited = initVisited();
    visited[v] = true;
    cout<<v<<" ";
    node *ptr = tab[v];
    while (ptr != nullptr)
    {
        if(visited[ptr->v] == false)
            DFS(tab, ptr->v);
        ptr=ptr->next;
    }
}
int main()
{
    node **tab = initTab();
    printGraph(tab);
    DFS(tab, 0);
}
