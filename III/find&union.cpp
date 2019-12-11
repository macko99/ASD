#include <iostream>
using namespace std;
struct zbiory{
    zbiory *next;
    zbiory *head;
    int val;
};
struct node{
    int v, w;
    node *next;
};
void makeSet (zbiory *x, int val)
{
    x->next = nullptr;
    x->head = x;
    x->val = val;
}
zbiory *findSet (zbiory *x)
{
    return x->head;
}
void unionSets (zbiory *x, zbiory *y)
{
    zbiory *zx = findSet(x);
    zbiory *zy = findSet(y);
    if (zx != zy)
    {
        zbiory *ending = x;
        while (ending->next != nullptr)
            ending = ending->next;
        ending->next = zy;
        while (ending != nullptr)
        {
            ending->head = zx;
            ending = ending->next;
        }
    }
    y = nullptr;
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
int spojneSkladowe (node **graph, int **macierz, int n)
{
    zbiory skladoweGraph [n];
    zbiory skladoweMacierz[n];

    for(int i=0; i<n; i++){
        makeSet(&skladoweMacierz[i], i);
        makeSet(&skladoweGraph[i], i);
    }

    for(int i=0; i<n; i++)
    {
        node *p = graph[i];
        while(p != nullptr)
        {
            unionSets(&skladoweGraph[i], &skladoweGraph[p->v]);
            p = p->next;
        }
        for(int j=0; j<n; j++)
        {
            if(macierz[i][j] != -1)
                 unionSets(&skladoweMacierz[i], &skladoweMacierz[j]);
        }
    }

    for(int i=0; i<n; i++)
    {
        zbiory *p = findSet(&skladoweGraph[i]);
        if(p->val == i)
        {
            cout<<"Set "<<i <<": ";
            while (p)
            {
                cout<<p->val<<" ";
                p = p->next;
            }
            cout<<endl;
        }
    }

    int res1 = 0, res2 = 0;
    for(int i=0; i<n; i++)
    {
        if(skladoweGraph[i].head->val == i)
            res1++;
        if(skladoweMacierz[i].head->val == i)
            res2++;
    }
    if(res1 == res2)
        return res1;
    else
        return -1;
}
int main ()
{
    int n, m;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    int **macierz = init_macierz (n, m);
    //print_graph(graph, n);
    //print_macierz(macierz, n);
    cout<<spojneSkladowe(graph, macierz, n);
    return 0;
}
