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
int abs (int a)
{
    return (a >= 0)? a: -a;
}
int max(int a, int b)
{
    return (a >= b)? a: b;
}
int height(node* node)
{
    if(node == nullptr)
        return 0;
    return 1+max(height(node->left),height(node->right));
}
bool isBalanced(node *root)
{
    if(root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if( abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return 0;
}
int main ()
{
    node *tree = nullptr;
    insert(tree, 6);
    insert(tree, 7);
    insert(tree, 2);
    insert(tree, 4);
    insert(tree, 20);
    print(tree);
    cout<<endl<<isBalanced(tree);
}
