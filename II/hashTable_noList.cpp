#include <iostream>
using namespace std;
enum states{
    EMPTY = 0,
    OCCUPIED = 1,
    STH_WAS_HERE = 2,
};
struct Node{
    string name;
    string phone;
    states state;
};
unsigned int hashfunc (string name)
{
    int p = 2137;
    unsigned int h = 0;
    for(int i=0; i<name.length(); i++)
        h = h*p + name[i];
    return h;
}
Node **create_hashtable(int n)
{
    Node **hashtable = new Node*[n];
    for(int i=0; i<n; i++)
    {
        hashtable[i] = new Node;
        hashtable[i]->state = EMPTY;
    }
    return hashtable;
}
void add_hashtable(Node **hashtable, int n, string name, string phone)
{
    unsigned int hashh = hashfunc(name) %n;
    while (hashtable[hashh]->state == OCCUPIED)
        hashh = (hashh + 1) %n;
    hashtable[hashh]->state = OCCUPIED;
    hashtable[hashh]->name = name;
    hashtable[hashh]->phone = phone;
}
string getNumber (Node **hashtable, int n, string name)
{
    if (n == 0) return "";
    unsigned int hashh = hashfunc(name) %n;
    unsigned int temphashh = hashh;
    while (hashtable[hashh]->state == STH_WAS_HERE || (hashtable[hashh]->state == OCCUPIED && hashtable[hashh]->name != name ) )
    {
        hashh = (hashh + 1) %n;
        if(temphashh == hashh) return "";
    }
    if( hashtable[hashh]->state == EMPTY)
        return "";
    return hashtable[hashh]->phone;
}
void removeEl (Node **hashtable, int n, string name)
{
    if (n == 0) return;
    unsigned int hashh = hashfunc(name) %n;
    unsigned int temphashh = hashh;
    while (hashtable[hashh]->state == STH_WAS_HERE || (hashtable[hashh]->state == OCCUPIED && hashtable[hashh]->name != name ) )
    {
        hashh = (hashh + 1) %n;
        if(temphashh == hashh) return;
    }
    if( hashtable[hashh]->state == EMPTY) return;
    hashtable[hashh]->state = STH_WAS_HERE;
}
void delete_hashtable (Node **hashtable, int n)
{
    for (int i=0; i<n; i++)
        delete hashtable[i];
    delete hashtable;
}
int main ()
{
    int n, k;
    string name, phone;
    char op;
    cout<<"liczba pozycji, liczba operacji" <<endl;
    cin >>n >>k;
    n = 3*n;
    Node **hashtable = create_hashtable(n);
    for(int i=0; i<k; i++)
    {
        cin >>op;
        switch (op)
        {
        case 'a':
            cin >>name >>phone;
            add_hashtable(hashtable, n, name, phone);
            break;
        case 'r':
            cin >>name;
            removeEl(hashtable, n, name);
            break;
        case 'g':
            cin >>name;
            cout<<getNumber(hashtable, n, name)<<endl;
            break;
        }
    }
    delete_hashtable(hashtable, n);
    return 0;
}
