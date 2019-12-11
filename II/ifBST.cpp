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
void print (node *root)
{
    if(root)
    {
        cout<<root->val<<" ";
        print(root->left);
        print(root->right);
    }
}
bool isBST (node *tree, int min, int max)
{
    if(tree == nullptr)
        return true;
    if(tree->val < min || tree->val > max)
        return false;
    return isBST(tree->left, min, tree->val) && isBST(tree->right, tree->val, max);
}
int main ()
{
    node *tree = nullptr;
    insert(tree, 6);
    insert(tree, 7);
    insert(tree, 2);
    insert(tree, 4);
    insert(tree, 20);
    cout<<isBST(tree, INT_MIN, INT_MAX)<<endl;
    tree->left->right->val = 1;
    cout<<isBST(tree, INT_MIN, INT_MAX)<<endl;
    print(tree);
}
