#include <iostream>
using namespace std;
struct Cyclist
{
    int id;
    int n_id;
};
struct listEl
{
    listEl *next;
    int id;
    int n_id;
};
int hashfunc (int id){
    return id%2137;
}
listEl *make (int id, int n_id)
{
    listEl *nowy = new listEl;
    nowy->id = id;
    nowy->n_id = n_id;
    nowy->next = nullptr;
    return nowy;
}
int SmallestGroup (Cyclist cyc[], int n)
{
    listEl **tab = new listEl *[2*n];
    for(int i=0; i<2*n ; i++)
        tab[i] = nullptr;

    for(int i=0; i<n; i++)
    {
        int hashh = hashfunc(cyc[i].id)%(2*n);
        while (tab[hashh] != nullptr)
            hashh = (hashh + 1) %(2*n);
        tab[hashh] = make(cyc[i].id, cyc[i].n_id);
    }

    for(int i=0; i< 2*n; i++)
    {
        if(tab[i] && tab[i]->n_id != -1)
        {
            int hashh = hashfunc(tab[i]->n_id)%(2*n);
            while (tab[hashh]->id != tab[i]->n_id)
                hashh = (hashh + 1) %(2*n);
            tab[i]->next= tab[hashh]->next;
            tab[hashh]->next = tab[i];
        }
    }

    int mincount = INT_MAX;
    for(int i=0; i< 2*n; i++)
    {
        if(tab[i] && tab[i]->n_id == -1)
        {
            int licz =0;
            listEl *ptr = tab[i];
            while (ptr)
            {
                licz++;
                ptr=ptr->next;
                if(licz > mincount)
                    break;
            }
            if(licz>0 && licz< mincount)
                mincount = licz;
        }
    }
    return mincount;
}
int main()
{
    Cyclist cyc[4];
    cyc[0].id = 0;
    cyc[0].n_id = -1;
    cyc[1].id = 2;
    cyc[1].n_id = 0;
    cyc[2].id = 3;
    cyc[2].n_id = 2;
    cyc[3].id = 1;
    cyc[3].n_id = -1;
    cout<<endl<<SmallestGroup(cyc, 4);
}
