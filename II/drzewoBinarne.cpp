#include <iostream>
using namespace std;
struct node{
    node *left;
    node *right;
    node *parent;
    int key;
};
node *findIte (node *p, int k)
{
    while (p != nullptr && p->key != k)
    {
        if(k < p->key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}
node *findRec (node *p, int k)
{
    if (p == nullptr || p->key == k)
        return p;
    if(k < p->key)
        return findRec(p->left, k);
    return findRec(p->right, k);
}
void insertTree (node *&p, int k)
{
    if (p == nullptr)
    {
        p = new node;
        p->left = nullptr;
        p->right = nullptr;
        p->key = k;
    }
    else
    {
        if (k < p->key)
            insertTree(p->left, k);
        else
            insertTree(p->right, k);
    }
}
node *minimal (node *p)
{
    while (p->left != nullptr)
        p=p->left;
    return p;
}
node *maxi (node *p)
{
    while (p->right != nullptr)
        p=p->right;
    return p;
}
node *nastepny (node *p)
{
    if(p->right != nullptr)
        return (p->right);
    node *q = p->parent;
    while(q != nullptr && q->right == p)
    {
        p=q;
        q=q->parent;
    }
    return q;
}
void printTree (node *p)
{
    if(p == nullptr) return;
    cout<<p->key<<" ";
    printTree(p->left);
    printTree(p->right);
}
int main ()
{
    node *p = nullptr;
    insertTree(p, 3);insertTree(p, 4);insertTree(p, 7);insertTree(p, 2);
    printTree(p);
    if(findIte(p, 4))
        cout<<endl<<findIte(p,4)->key;
    if(findRec(p, 66))
        cout<<endl<<findRec(p,66)->key;
    cout<<endl<<maxi(p)->key;
    cout<<endl<<minimal(p)->key;
    return 0;
}
