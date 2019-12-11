#include <iostream>
using namespace std;
int N = 6, m =3;
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
        if( i == find_Set(&tab[i])->val )
            res++;
    cout<<"Sets : "<<res<<endl;
}
int main()
{
    distEL tab[N];
    int v1, v2;

    for(int i=0; i<N; i++)
        make_Set(&tab[i], i);

    for(int i=0; i<m; i++)
    {
        cin >>v1 >>v2;
        union_Sets(&tab[v1], &tab[v2]);
    }
    print_Sets(tab);
    Count_Sets(tab);
}
