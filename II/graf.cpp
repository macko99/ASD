#include <iostream>
using namespace std;
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
void printGraph (node **tab, int n)
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
node ** initTab (int n)
{
    node **tab = new node *[n];
    for (int i=0; i<n; i++)
        tab[i] = nullptr;
    return tab;
}
bool **initMacierz (int n)
{
    bool **macierz = new bool *[n];
    for (int i=0; i<n; i++)
        macierz[i] = new bool [n];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            macierz[i][j] = 0;
    return macierz;
}
void printMacierz (bool **macierz, int n)
{
     for (int i=0; i<n; i++)
     {
        for (int j=0; j<n; j++)
            cout<<macierz[i][j]<<" ";
        cout<<endl;
     }
}
int main()
{
    int n = 5, m = 4, v1, v2;

    node **tab = initTab(n);
    bool **macierz = initMacierz(n);

    for(int i = 0; i<m; i++)
    {
        cin >>v1>>v2;
        insertEdge(tab, v1, v2);
        macierz[v1][v2] = 1;
    }

     printGraph(tab, n);
     printMacierz(macierz, n);
}
