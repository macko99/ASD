#include <iostream>
using namespace std;
struct Node {
    string text;
    Node *next;
};
unsigned int hashfunc(string text)
{
    int p = 2137;
    unsigned int h = 0;
    for(int i=0; i<text.length(); i++)
        h = h*p + text[i];
    return h;
}
Node **create_hashtable (int n)
{
    Node **hashtable = new Node*[n];
    for(int i=0; i<n; i++)
        hashtable[i] = nullptr;
    return hashtable;
}
void add_hashtable (Node **hashtable, int n, string text)
{
    Node *node = new Node;
    node->text = text;
    unsigned hashh = hashfunc(text) % n;
    node->next = hashtable[hashh];
    hashtable[hashh] = node;
}
bool find_hashtable (Node **hashtable, int n, string text)
{
    if (n == 0) return false;
    unsigned int hashh = hashfunc(text) % n;
    Node *p = hashtable[hashh];
    while (p != nullptr)
    {
        if(p->text == text) return true;
        p = p->next;
    }
    return false;
}
void add_hashtable_noduplicate (Node **hashtable, int n, string text)
{
    if(find_hashtable(hashtable, n, text)) return;
    Node *node = new Node;
    node->text = text;
    unsigned hashh = hashfunc(text) % n;
    node->next = hashtable[hashh];
    hashtable[hashh] = node;
}
void deleteEl_hashtable (Node **hashtable, int n, string text)
{
    if (n == 0) return;
    unsigned int hashh = hashfunc(text) % n;
    Node *p = hashtable[hashh];
    while (p != nullptr && p->text == text)
    {
        hashtable[hashh] = p->next;
        delete p;
        p = hashtable[hashh];
    }
    if(p == nullptr) return;
    Node *p2 = p->next;
    while (p2 != nullptr)
    {
        if(p2->text == text)
        {
            p->next=p2->next;
            delete p2;
            p2=p->next;
        }
        else
        {
            p=p->next;
            p2=p2->next;
        }
    }
}
void remove_hashtable (Node **hashtable, int n)
{
    Node *p, *p2;
    for(int i=0; i<n; i++)
    {
        p = hashtable[i];
        while (p != nullptr)
        {
            p2 = p->next;
            delete p;
            p = p2;
        }
    }
    delete hashtable;
}
int main()
{
    int n, k, l; string text;
    cout<<"liczba wyrazow, liczba do spr, liczba do usu" <<endl;
    cin >>n >>k >>l;
    Node **hashtable = create_hashtable(n);
    for(int i=0; i<n; i++)
    {
        cin >>text;
        add_hashtable(hashtable, n, text);
    }
    for(int i=0; i<l; i++)
    {
        cin >>text;
        deleteEl_hashtable(hashtable, n, text);
    }
    for(int i=0; i<k; i++)
    {
        cin >>text;
        cout<<find_hashtable(hashtable, n, text);
    }
    remove_hashtable(hashtable, n);
    return 0;
}
