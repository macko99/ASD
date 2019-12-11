#include <iostream>
using namespace std;
int med;
struct node
{
    node *parent;
    node *left;
    node *right;
    int val;
};
node *createNode (int val)
{
    node *nowy = new node;
    nowy->parent = nullptr;
    nowy->left = nullptr;
    nowy->right = nullptr;
    nowy->val = val;
    return nowy;
}
void insert (node *&tree, int val)
{
    if (tree == nullptr)
        tree = createNode (val);
    else
    {
        node *ptr = tree;
        node *parent;
        while (ptr)
        {
            parent = ptr;
            if(ptr->val < val)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if(parent->val < val)
        {
            parent->right = createNode (val);
            parent->right->parent = parent;
        }
        else
        {
            parent->left = createNode (val);
            parent->left->parent = parent;
        }
    }
}
int countNodes (node *tree)
{
    int suma = 1;
    if(tree->left)
        suma+=countNodes(tree->left);
    if(tree->right)
        suma+=countNodes(tree->right);
    return suma;
}
void inorder (node *root)
{
    if(root)
    {
        inorder(root->left);
        --med;
        if(med == 0)
            cout<<root->val;
        inorder(root->right);
    }
}
void median (node *tree)
{
    int full = countNodes(tree);
     med = full/2+1;
    inorder(tree);
}
int main ()
{
    node *tree = nullptr;
    insert(tree, 6);
    insert(tree, 7);
    insert(tree, 2);
    insert(tree, 4);
    insert(tree, 20);
        insert(tree, 20);
    median(tree);
}
