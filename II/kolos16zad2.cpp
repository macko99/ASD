#include <iostream>
using namespace std;
struct HT
{
    int *tab;
    int size;
};
HT *initTab (int size)
{
    HT *nowy = new HT;
    nowy->size = size;
    nowy->tab = new int[size];
    for(int i=0; i<size; i++)
        nowy->tab[i] = -1;
    return nowy;
}
int hashf (int x)
{
    return x%2137;
}
void add_hashtable(HT *tab, int x)
{
    int hashh = hashf(x)%tab->size;
    while (tab->tab[hashh] >= 0)
        hashh = (hashh + 1) %tab->size;
    tab->tab[hashh] = x;
}
void enlarge (HT *tab)
{
    int newsize = tab->size*2;
    int *T = new int[newsize];
    for(int i=0; i<newsize; i++)
        T[i] = -1;
    for(int i =0; i<tab->size; i++)
    {
        if(tab->tab[i] >=0 )
        {
            int newhashh = hashf(tab->tab[i]);
            if(newhashh < newsize)
            {
                T[newhashh] = tab->tab[i];
                tab->tab[i] = -1;
            }
        }
    }
    for(int i =0; i<tab->size; i++)
    {
        if(tab->tab[i] >= 0 )
        {
            int hashh = hashf(tab->tab[i])%newsize;
            while (T[hashh] >= 0)
                hashh = (hashh + 1) %newsize;
            T[hashh] = tab->tab[i];
        }
    }
    tab->tab = T;
}
int main ()
{
    HT *tab = initTab(20);
    add_hashtable(tab, 4);
    add_hashtable(tab, 30);
    add_hashtable(tab, 1);
    add_hashtable(tab, 54);
    add_hashtable(tab, 15);

    for(int i=0; i<20; i++){
            if(tab->tab[i] >= 0)
                cout<<i<<" : "<<tab->tab[i]<<endl;
    }
    enlarge(tab); cout<<endl;
    for(int i=0; i<40; i++){
            if(tab->tab[i] >= 0)
                cout<<i<<" : "<<tab->tab[i]<<endl;
    }
    return 0;
}
