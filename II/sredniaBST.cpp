#include <iostream>
using namespace std;
struct node{
    node *left;
    node *right;
    node *parent;
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
        p->key = k;
    }
    else
    {
        node *tmp;
        if (k < p->key)
        {
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
void inorder (node *p, int &suma, int &ile)
{
    if (p)
    {
        inorder(p->left, suma,ile);
        suma+=p->key;
        ile++;
        inorder(p->right,suma, ile );
    }
}
int main ()
{
    node *p = nullptr;
    INSERT(p, 3);INSERT(p, 5);INSERT(p, 4);INSERT(p, 2);INSERT(p, 7);INSERT(p, 8);
    int suma =0, ile = 0;
    inorder(p, suma, ile);
    cout<<suma<<" "<<ile;
    return 0;
}
