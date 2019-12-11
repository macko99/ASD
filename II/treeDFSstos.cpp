#include <iostream>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
};
struct stack
{
    node *node;
    stack *next;
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
void push_stack (stack *&S, node *node)
{
    stack *nowy = new stack;
    nowy->node = node;
    nowy ->next = S;
    S = nowy;
}
node *pop_stack (stack *&S)
{
    if (S == nullptr)
        return nullptr;
    node *ptr = S->node;
    S = S->next;
    return ptr;
}
void DFS (node *root)
{
    stack *S = nullptr;
    push_stack(S, root);
    while (S)
    {
        node *ptr = pop_stack (S);
        cout<<ptr->val<<" ";
        if(ptr->right) push_stack (S, ptr->right);
        if(ptr->left) push_stack (S, ptr->left);
    }
}
int main()
{
    node *root = nullptr;
    insert_node(root, 7);insert_node(root, 5);insert_node(root, 12);insert_node(root, 2);insert_node(root, 1);
    insert_node(root, 3);insert_node(root, 6);;insert_node(root, 10);insert_node(root, 20);
    print(root);
        cout<<endl;
    DFS(root);
}
