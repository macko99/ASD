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
bool findIte (node *p, int k)
{
    while (p != nullptr && p->key != k)
    {
        if(k < p->key)
            p = p->left;
        else
            p = p->right;
    }
    if(p) return true;
    return false;
}
bool findRec (node *p, int k)
{
    if (p == nullptr) return false;
    if(p->key == k) return true;
    if(k < p->key)
        return findRec(p->left, k);
    return findRec(p->right, k);
}
node *findNodeIte (node *p, int k)
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
node *findRecNode (node *p, int k)
{
    if (p == nullptr || p->key == k)
        return p;
    if(k < p->key)
        return findRecNode(p->left, k);
    return findRecNode(p->right, k);
}
int minimal (node *p)
{
    while (p->left != nullptr)
        p=p->left;
    return p->key;
}
int maxi (node *p)
{
    while (p->right != nullptr)
        p=p->right;
    return p->key;
}
node* minimalNode (node *p)
{
    while (p->left != nullptr)
        p=p->left;
    return p;
}
node *maxiNode (node *p)
{
    while (p->right != nullptr)
        p=p->right;
    return p;
}
void printTree (node *p)
{
    if(p == nullptr) return;
    cout<<p->key<<" ";
    printTree(p->left);
    printTree(p->right);
}
int nastepnik (node *p, int k)
{
    node *n = findNodeIte(p, k);
    if(n->right != nullptr)
        return minimal(p->right);
    node *par = n->parent;
    while (par != nullptr && n == par->right)
    {
        n = par;
        par = par->parent;
    }
    if(par) return par->key;
    return -1;
}
int poprzednik (node *p, int k)
{
    node *n = findNodeIte(p, k);
    if(n->left != nullptr)
        return maxi(p->left);
    node *par = n->parent;
    while (par != nullptr && n == par->left)
    {
        n = par;
        par = par->parent;
    }
    if(par) return par->key;
    return -1;
}
node *nastepnikNode (node *p, int k)
{
    node *n = findNodeIte(p, k);
    if(n->right != nullptr)
        return minimalNode(p->right);
    node *par = n->parent;
    while (par != nullptr && n == par->right)
    {
        n = par;
        par = par->parent;
    }
    return par;
}
node *nastepnikNodeNode (node *p, node *n)
{
    if(n->right != nullptr)
        return minimalNode(p->right);
    node *par = n->parent;
    while (par != nullptr && n == par->right)
    {
        n = par;
        par = par->parent;
    }
    return par;
}
node *poprzednikNode (node *p, int k)
{
    node *n = findNodeIte(p, k);
    if(n->left != nullptr)
        return maxiNode(p->left);
    node *par = n->parent;
    while (par != nullptr && n == par->left)
    {
        n = par;
        par = par->parent;
    }
    return par;
}
void removeELbst (node *&root, node *n)
{
    if (n->right == nullptr && n->left == nullptr)
    {
        if(n->parent->left == n)
            n->parent->left = nullptr;
        else
            n->parent->right = nullptr;
        delete n;
    }
    else if (n->right != nullptr && n->left == nullptr)
    {
        if (n->parent->left == n)
            n->parent->left = n->right;
        else
            n->parent->right = n->right;
        delete n;
    }
    else if (n->right == nullptr && n->left != nullptr)
    {
        if (n->parent->left == n)
            n->parent->left = n->left;
        else
            n->parent->right = n->left;
        delete n;
    }
    else
    {
        node *nast = nastepnikNodeNode(root, n);
        n->key = nast->key;
        removeELbst(n, nast);
    }
}
void removeBST (node *&root, int k)
{
    node *n = findNodeIte(root, k);
    removeELbst(root, n);
}
void removeBST2 (node *&root, node *X)
{
    node * Y, * Z;
    if(X)
    {
        Y = !X->left || !X->right ? X : nastepnikNodeNode(root, X);
        Z = Y->left ? Y->left : Y->right;
        if(Z) Z->parent = Y->parent;
        if(!Y->parent) root = Z;
        else if(Y == Y->parent->left)
            Y->parent->left  = Z;
        else
            Y->parent->right = Z;
        if(Y != X) X->key = Y->key;
        delete Y;
    }
}
void removeBST3 (node *&root, int k)
{
    node *n = findNodeIte(root, k);
    removeBST2(root, n);
}
void inorder (node *p)
{
    if (p)
    {
        inorder(p->left);
        cout<<p->key<<" ";
        inorder(p->right);
    }
}
void rotacjaLewo (node *&root, node *A)
{
    node *B = A->right;
    if(B)
    {
        A->right = B->left;
        if(A->right)
            A->right->parent = A;
        B->left = A;
        B->parent = A->parent;
        A->parent = B;
        if(B->parent)
        {
            if(B->parent->left == A)
                B->parent->left = B;
            else
                B->parent->right = B;
        }
        else
            root = B;
    }
}
void rotacjaPrawo (node *&root, node *A)
{
    node *B = A->left;
    if(B)
    {
        A->left = B->right;
        if(A->left)
            A->left->parent = A;
        B->right = A;
        B->parent = A->parent;
        A->parent = B;
        if(B->parent)
        {
            if(B->parent->left == A)
                B->parent->left = B;
            else
                B->parent->right = B;
        }
        else
            root = B;
    }
}
unsigned log2 (unsigned x)
{
    unsigned y = 1;
    while ((x >>= 1) > 0) y <<= 1;
    return y;
}
void DSW (node *&root)
{
    unsigned n = 0;
    node *p = root;
    while(p)
    {
        if(p->left)
        {
            rotacjaPrawo(root, p);
            p = p->parent;
        }
        else
        {
            n++;
            p = p->right;
        }
    }
    unsigned s = n+1 - log2(n+1);
    p = root;
    for(unsigned i=0; i<s; i++)
    {
        rotacjaLewo(root,p);
        p = p->parent->right;
    }
    n = n - s;
    while(n > 1)
    {
        n >>= 1;
        p = root;
        for(unsigned i=0; i<n; i++)
        {
            rotacjaLewo(root,p);
            p = p->parent->right;
        }
    }
}
int main ()
{
    node *p = nullptr;
    INSERT(p, 3);INSERT(p, 5);INSERT(p, 4);INSERT(p, 2);INSERT(p, 7);INSERT(p, 8);
    printTree(p);
    /*cout<<endl<<findRec(p, 4)<<endl<<findRec(p, 81);
    cout<<endl<<findIte(p, 5)<<endl<<findIte(p, 9);
    cout<<endl <<maxi(p)<<endl<<minimal(p);
    cout<<endl<<nastepnik(p, 4)<<endl;
    cout<<poprzednik(p, 2)<<endl;
     inorder(p);
    removeBST3(p, 8);*/
    //rotacjaLewo(p, p);
    //rotacjaPrawo(p, p);
    DSW(p);
    cout<<endl;
    printTree(p);
    
    return 0;
}
