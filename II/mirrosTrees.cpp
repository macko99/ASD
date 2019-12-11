#include <iostream>
using namespace std;
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
void insert2 (node *&tree, int val)
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
            if(ptr->val > val)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if(parent->val > val)
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
void print (node *root)
{
    if(root)
    {
        cout<<root->val<<" ";
        print(root->left);
        print(root->right);
    }
}
bool mirror (node *tree, node *tree2)
{
    if(tree == nullptr && tree2 == nullptr)
        return true;
    else if (tree != nullptr && tree2 != nullptr)
    {
        return tree->val == tree2->val && mirror(tree->left, tree2->right) && mirror(tree->right, tree2->left);
    }
    return false;
}
int main ()
{
    node *tree = nullptr;
    node *tree2 = nullptr;
    insert(tree, 6);
    insert(tree, 7);
    insert(tree, 2);
    insert(tree, 4);
    insert(tree, 20);
    insert2(tree2, 6);
    insert2(tree2, 7);
    insert2(tree2, 2);
    insert2(tree2, 4);
    insert2(tree2, 20);
    cout<<mirror(tree,tree2);
}
