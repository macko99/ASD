#include <iostream>
using namespace std;
int n = 10;
struct Data
{
    string firstName;
    string lastName;
    int age;
};
struct node
{
    Data dane;
    node *next;
};
node **createHashTable ()
{
    node **hashTable = new node *[n];
    for(int i =0; i<n; i++)
        hashTable[i] = nullptr;
    return hashTable;
}
unsigned int hashfunc (string lastName)
{
    int p = 2137;
    unsigned int h = 0;
    for(int i=0; i<lastName.length(); i++)
        h = h*p + lastName[i];
    return h;
}
void addHashTable (node **hashtable, Data dane)
{
    node *nowy = new node;
    nowy->dane = dane;
    unsigned int hashh = hashfunc(dane.lastName) %n;
    nowy->next = hashtable[hashh];
    hashtable[hashh] = nowy;
}
Data findHashTable (node **hashtable, string lastName)
{
    unsigned int hashh = hashfunc(lastName) %n;
    node *p = hashtable[hashh];
    while (p != nullptr)
    {
        if(p->dane.lastName == lastName)
            return p->dane;
        p=p->next;
    }
    Data pusty;
    pusty.age = -1;
    return pusty;
}
int main ()
{
    node **hashTable = createHashTable();
    Data dane;
    string firstName, lastName;
    int age;

    for(int i=0; i<1; i++)
    {
        cin>>firstName >>lastName >>age;
        dane.age = age;
        dane.firstName = firstName;
        dane.lastName = lastName;
        addHashTable(hashTable, dane);
    }
    for(int i=0; i<5; i++)
    {
        cin>>lastName;
        cout<<findHashTable(hashTable, lastName).age<<endl;
    }
}
