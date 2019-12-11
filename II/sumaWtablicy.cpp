#include <iostream>
using namespace std;
struct Node{
    int val;
    Node *next;
};
Node **create_hashtable (int n)
{
    Node **hashtable = new Node*[n];
    for(int i=0; i<n; i++)
        hashtable[i] = nullptr;
    return hashtable;
}
void delete_hashtable (Node **hashtable, int n)
{
    for(int i=0; i<n; i++)
        delete hashtable[i];
    delete hashtable;
}
void print_hashtable (Node **hashtable, int n)
{
    Node *ptr;
    for(int i=0; i<n; i++)
    {
        ptr = hashtable[i];
        while (ptr != nullptr)
        {
            cout<< ptr->val<<" ";
            ptr = ptr->next;
        }
        cout<<" || ";
    }
    cout<<endl;
}
unsigned int hash_func (int value, int n)
{
    int p = 2137;
    return (value*p)%n;
}
int findPairs (int *arr, int x, int n)
{
    int counter = 0;
    Node **hashtable = create_hashtable(n);
    unsigned int hashh, hashhX;
    Node *ptr;
    for(int i=0; i<n; i++)
    {
        hashhX = hash_func(x-arr[i], n) %n;
        ptr = hashtable[hashhX];
        while (ptr != nullptr)
        {
            if(arr[i] + ptr->val == x)
                counter++;
            ptr = ptr->next;
        }
        hashh = hash_func(arr[i], n) %n;
        Node *n = new Node;
        n->val = arr[i];
        n->next = hashtable[hashh];
        hashtable[hashh] = n;
    }
    print_hashtable(hashtable, n);
    delete_hashtable(hashtable, n);
    return counter;
}
int main()
{
    int n, x;
    cout<<"Liczba elementow, szukana suma\n";
    cin >>n >>x;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >>arr[i];
    cout<<findPairs(arr, x, n);
    return 0;
}
