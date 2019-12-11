#include <iostream>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
};
struct queue
{
    node *node;
    queue *next;
};
void insert_node (node *&root, int k)
{
    if (root == nullptr)
    {
        root = new node;
        root->val = k;
        root->left = nullptr;
        root->right = nullptr;
    }
    else
    {
        node *ptr = root;
        node *parent;
        while (ptr)
        {
            parent = ptr;
            if(ptr->val < k)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if(parent->val < k)
        {
            parent->right = new node;
            parent->right->val = k;
            parent->right->right = nullptr;
            parent->right->left = nullptr;
        }
        else
        {
            parent->left = new node;
            parent->left->val = k;
            parent->left->right = nullptr;
            parent->left->left = nullptr;
        }
    }
}
void print (node *root)
{
    if(root)
    {
        cout<<root->val<<" ";
        print(root->left);
        print(root->right);
    }
}
void put_queue (queue *&Q, node *node)
{
    queue *nowy = new queue;
    nowy->node = node;
    nowy ->next = Q;
    Q= nowy;
}
node *pop_queue (queue *&Q)
{
    if (Q == nullptr)
        return nullptr;
    if(Q->next == nullptr)
    {
        node *res = Q->node;
        Q = nullptr;
        return res;
    }
    queue *ptr = Q;
    while (ptr->next->next != nullptr)
        ptr=ptr->next;
    node *res = ptr->next->node;
    delete ptr->next;
    ptr->next = nullptr;
    return res;
}
void BFS (node *root)
{
    queue *Q = nullptr;
    put_queue(Q, root);
    while (Q != nullptr)
   {
        node *ptr = pop_queue(Q);
        cout<<ptr->val<<" ";
        if(ptr->left != nullptr) put_queue(Q, ptr->left);
        if(ptr->right != nullptr) put_queue(Q, ptr->right);
    }
}
int main()
{
    node *root = nullptr;
    insert_node(root, 7);insert_node(root, 5);insert_node(root, 12);insert_node(root, 2);insert_node(root, 1);
    insert_node(root, 3);insert_node(root, 6);;insert_node(root, 10);insert_node(root, 20);
    print(root);
        cout<<endl;
    BFS(root);
}
