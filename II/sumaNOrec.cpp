#include <iostream>
using namespace std;
struct node{
    node *left;
    node *right;
    int key;
};
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
void printTree (node *p)
{
    if(p == nullptr) return;
    cout<<p->key<<" ";
    printTree(p->left);
    printTree(p->right);
}
struct queue
{
    node *node;
    queue *next;
};
void put_queue (queue *&Q, node *node)
{
    queue *nowy = new queue;
    nowy->node = node;
    nowy->next = Q;
    Q = nowy;
}
node *pop_queue (queue *&Q)
{
    if (Q == nullptr)
        return nullptr;
    if(Q->next == nullptr)
    {
        node* res = Q->node;
        Q = nullptr;
        return res;
    }
    queue *ptr = Q;
    while (ptr->next->next != nullptr)
        ptr=ptr->next;
    node*res = ptr->next->node;
    delete ptr->next;
    ptr->next = nullptr;
    return res;
}
int suma (node *tree)
{
    int suma = 0;
    queue *Q = nullptr;
    put_queue(Q, tree);
    while (Q)
    {
        node *x = pop_queue(Q);
        suma+=x->key;
        if(x->left)
            put_queue(Q, x->left);
        if(x->right)
            put_queue(Q, x->right);
    }
    return suma;
}
int main ()
{
    node *p = nullptr;
    insertTree(p, 3);
    insertTree(p, 5);
    insertTree(p, 4);
    insertTree(p, 2);
    insertTree(p, 7);
    printTree(p);
    cout<<endl<<suma(p);
}
