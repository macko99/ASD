#include <iostream>
using namespace std;
struct node{
    node *left;
    node *right;
    node *parent;
    int leftCount;
    int key;
};
node *insertTree (node *p, int k)
{
    if(p == nullptr)
    {
        p = new node;
        p->left = nullptr;
        p->right = nullptr;
        p->parent = nullptr;
        p->leftCount = 0;
        p->key = k;
    }
    else
    {
        node *tmp;
        if (k < p->key)
        {
            p->leftCount++;
            tmp = insertTree(p->left, k);
            p->left = tmp;
            tmp->parent = p;
        }
        else
        {
            tmp = insertTree(p->right, k);
            p->right = tmp;
            tmp->parent = p;
        }
    }
    return p;
}
void INSERT (node *&p, int k)
{
    p = insertTree(p, k);
}
node *findRecNode (node *p, int k)
{
    if (p == nullptr || p->key == k)
        return p;
    if(k < p->key)
        return findRecNode(p->left, k);
    return findRecNode(p->right, k);
}
void printTree (node *p)
{
    if(p == nullptr) return;
    cout<<p->key<<" ";
    printTree(p->left);
    printTree(p->right);
}
int findKth (node *p, int k)
{
    while (p)
    {
        if (p->leftCount + 1 == k)
            return p->key;
        else if (p->leftCount + 1 > k)
            return findKth(p->left, k);
        else
            return findKth(p->right, k-p->leftCount-1);
    }
    return -1;
}
node *findKthNode (node *p, int k)
{
    while (p)
    {
        if (p->leftCount + 1 == k)
            return p;
        else if (p->leftCount + 1 > k)
            return findKthNode(p->left, k);
        else
            return findKthNode(p->right, k-p->leftCount-1);
    }
    return nullptr;
}
int WhoAmI (node *p, int k)
{
    node *n = findRecNode(p, k);
    int path = n->leftCount+1;
    while (n->parent)
    {
        if(n->parent->right == n)
            path+=n->parent->leftCount+1;
        n=n->parent;
    }
    return path;
}
int WhoAmINode (node *p, node *n)
{
    int path = n->leftCount+1;
    while (n->parent)
    {
        if(n->parent->right == n)
            path+=n->parent->leftCount+1;
        n=n->parent;
    }
    return path;
}
int main()
{
    node *p = nullptr;
    INSERT(p, 3);INSERT(p, 5);INSERT(p, 4);INSERT(p, 2);INSERT(p, 7);INSERT(p, 8);
    printTree(p);
    cout<<endl<<findKth(p, 9)<<endl<<findKthNode(p, 4)->key;
    cout<<endl<<WhoAmI(p, 7);
    return 0;
}
