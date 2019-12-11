#include <iostream>
using namespace std;
struct node{
    node *left;
    node *right;
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
node *nastepny (node *root, node *p)
{
    if(p->right != nullptr)
        return minimal(p->right);
    node *succ = nullptr;
    while(root != nullptr)
    {
        if(p->key < root->key)
        {
            succ = root;
            root = root->left;
        }
        else if (p->key > root->key)
            root = root->right;
        else break;
    }
    return succ;
}
node *poprzedni (node *root, node *p)
{
    if(p->left != nullptr)
        return maxi(p->left);
    node *prev = nullptr;
    while(root != nullptr)
    {
        if(p->key < root->key)
        {
            root = root->left;
        }
        else if (p->key > root->key)
        {
            prev = root;
            root = root->right;
        }
        else break;
    }
    return prev;
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
    insertTree(p, 3);insertTree(p, 5);insertTree(p, 4);insertTree(p, 2);insertTree(p, 7);
    printTree(p);
    cout <<endl;
    if(findIte(p, 4))
        cout <<"jest 4" <<endl;
    if(findRec(p, 66))
        cout <<"jest 66" <<endl;
    cout <<maxi(p)->key <<endl;
    cout <<minimal(p)->key <<endl;
    if(nastepny(p, p->right->left))
        cout <<nastepny(p, p->right->left)->key <<endl;
    if(poprzedni(p, p->right->left))
        cout <<poprzedni(p, p->right->left)->key <<endl;
    return 0;
}
