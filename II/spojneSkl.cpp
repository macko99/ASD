#include <iostream>
using namespace std;
int N = 6, m =3;
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
void printGraph (node **tab)
{
    for (int i=0; i<N; i++)
     {
         node *ptr = tab[i];
         while (ptr != nullptr)
         {
             cout<<i<<" - "<<ptr->v<<endl;
             ptr=ptr->next;
         }
     }
}
node ** initTab ()
{
    node **tab = new node *[N];
    for (int i=0; i<N; i++)
        tab[i] = nullptr;
    return tab;
}
bool **initMacierz ()
{
    bool **macierz = new bool *[N];
    for (int i=0; i<N; i++)
        macierz[i] = new bool [N];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            macierz[i][j] = 0;
    return macierz;
}
void printMacierz (bool **macierz)
{
     for (int i=0; i<N; i++)
     {
        for (int j=0; j<N; j++)
            cout<<macierz[i][j]<<" ";
        cout<<endl;
     }
}
struct distEL
{
    distEL *head;
    distEL *next;
    int val;
};
void make_Set (distEL *x, int val)
{
    x->head = x;
    x->next = nullptr;
    x->val = val;
}
distEL* find_Set (distEL *x)
{
    return x->head;
}
void union_Sets (distEL *x, distEL *y)
{
    distEL *zx = find_Set(x);
    distEL *zy = find_Set(y);
    if (zx != zy)
    {
        distEL *ending = x;
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
void print_Sets (distEL tab[])
{
    distEL *p;
    for(int i=0; i<N; i++)
    {
        p = find_Set(&tab[i]);
        if( i == p->val )
        {
            cout << "Set " <<i <<" : ";
            while(p)
            {
                cout <<p->val << " ";
                p = p->next;
            }
            cout<<endl;
        }
    }
    cout<<endl;
}
void Count_Sets (distEL tab[])
{
    int res =0;
    for(int i=0; i<N; i++)
        if( i == tab[i].head->val )
            res++;
    cout<<"Sets : "<<res<<endl;
}
int main()
{
    int v1, v2;

    node **tab = initTab();
    bool **macierz = initMacierz();

    for(int i = 0; i<m; i++)
    {
        cin >>v1>>v2;
        insertEdge(tab, v1, v2);
        macierz[v1][v2] = 1;
    }

    printGraph(tab);
    printMacierz(macierz);

    distEL zbiory[N];
    distEL zbiory2[N];

    for(int i=0; i<N; i++)
    {
        make_Set(&zbiory[i], i);
        make_Set(&zbiory2[i], i);
    }

    for(int i=0; i<N; i++)
    {
        node *p = tab[i];
        while (p)
        {
            union_Sets(&zbiory[i], &zbiory[p->v]);
            p=p->next;
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(macierz[i][j] == 1)
                 union_Sets(&zbiory2[i], &zbiory2[j]);
        }
    }
    print_Sets(zbiory);
    Count_Sets(zbiory);
    cout<<endl;
    print_Sets(zbiory2);
    Count_Sets(zbiory2);
}
