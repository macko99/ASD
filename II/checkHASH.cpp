#include <iostream>
using namespace std;
struct ht
{
    int *tab;
    int size;
};
ht *init_ht (int size)
{
    ht *hashtable = new ht;
    hashtable->tab = new int[size];
    for(int i=0; i<size; i++)
        hashtable->tab[i] =-1;
    hashtable->size = size;
    return hashtable;
}
int hashfunc (int x)
{
    return x%2137;
}
void add_tohash (ht *hashtable, int value)
{
    int hashh = hashfunc(value) %hashtable->size;
    while (hashtable->tab[hashh] >= 0 )
        hashh = (hashh +1) % hashtable->size;
    hashtable->tab[hashh] = value;
}
void delete_fromhash (ht *hashtable, int value)
{
    int hashh = hashfunc(value) %hashtable->size;
    while (hashtable->tab[hashh] != value )
        hashh = (hashh + 5) % hashtable->size;
    hashtable->tab[hashh] = -1;
}
bool find_inhash (ht *hashtable, int value)
{
    int hashh = hashfunc(value) %hashtable->size;
    int hashh_init = hashh;
    while (hashtable->tab[hashh] != value )
    {
        hashh = (hashh + 5) % hashtable->size;
        if(hashh == hashh_init)
            return false;
    }
    return true;
}
bool check_hash (ht *hashtable)
{
    for(int i=0; i<hashtable->size; i++)
    {
        if(hashtable->tab[i] >= 0)
        {
            int hashh = hashfunc(hashtable->tab[i]) %hashtable->size;
            int hashh_init = hashh;
            while (hashtable->tab[hashh] != hashtable->tab[i] )
            {
                hashh = (hashh +5) % hashtable->size;
                if(hashh == hashh_init)
                return false;
            }
        }
    }
    return true;
}
void print_hash (ht *hashtable)
{
    for(int i=0; i<hashtable->size; i++)
    {
        if(hashtable->tab[i] >= 0)
        {
            cout<<i<<" : "<<hashtable->tab[i]<<endl;
        }
    }
}
int main ()
{
    ht *hashtable = init_ht(33);
    add_tohash(hashtable, 450);
    add_tohash(hashtable, 20);
    add_tohash(hashtable, 45);
    hashtable->tab[1] = 5;
    print_hash(hashtable);
    cout<<endl<<check_hash(hashtable);
    return 0;
}
