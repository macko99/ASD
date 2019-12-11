#include <iostream>
using namespace std;
struct node{
    node *left;
    node *right;
    node *parent;
    int key;
    char color;
};
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
node *minimalNode (node *p)
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
    cout<<p->key<<":"<<p->color<<" ";
    printTree(p->left);
    printTree(p->right);
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
node *poprzednikNodeNode (node *p, node *n)
{
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
void insertRBT(node *&p, int k)
{
    node *X, *Y;
    
    X = new node;        // Tworzymy nowy węzeł
    X->left  = nullptr;          // Inicjujemy pola
    X->right = nullptr;
    X->parent = p;
    X->key = k;
    if(X->parent == nullptr)
        p = X; // X staje się korzeniem
    else
        while(true)             // Szukamy liścia do zastąpienia przez X
        {
            if(k < X->parent->key)
            {
                if(X->parent->left == nullptr)
                {
                    X->parent->left = X;  // X zastępuje lewy liść
                    break;
                }
                X->parent = X->parent->left;
            }
            else
            {
                if(X->parent->right == nullptr)
                {
                    X->parent->right = X; // X zastępuje prawy liść
                    break;
                }
                X->parent = X->parent->right;
            }
        }
    X->color = 'R';         // Węzeł kolorujemy na czerwono
    while((X != p) && (X->parent->color == 'R'))
    {
        if(X->parent == X->parent->parent->left)
        {
            Y = X->parent->parent->right; // Y -> wujek X
            if(Y->color == 'R')  // Przypadek 1
            {
                X->parent->color = 'B';
                Y->color = 'B';
                X->parent->parent->color = 'R';
                X = X->parent->parent;
                continue;
            }
            if(X == X->parent->right) // Przypadek 2
            {
                X = X->parent;
                rotacjaLewo(p, X);
            }
            X->parent->color = 'B'; // Przypadek 3
            X->parent->parent->color = 'R';
            rotacjaPrawo(p,X->parent->parent);
            break;
        }
        else
        {                  // Przypadki lustrzane
            Y = X->parent->parent->left;
            if(Y->color == 'R') // Przypadek 1
            {
                X->parent->color = 'B';
                Y->color = 'B';
                X->parent->parent->color = 'R';
                X = X->parent->parent;
                continue;
            }
            if(X == X->parent->left) // Przypadek 2
            {
                X = X->parent;
                rotacjaPrawo(p, X);
            }
            X->parent->color = 'B'; // Przypadek 3
            X->parent->parent->color = 'R';
            rotacjaLewo(p, X->parent->parent);
            break;
        }
    }
    p->color = 'B';
}
void removeRBT(node *&p, node  *X)
{
    node *W, *Y, *Z;
    if((X->left == nullptr) || (X->right == nullptr))
        Y = X;
    else
        Y = nastepnikNodeNode(p, X);
    if(Y->left != nullptr)
        Z = Y->left;
    else
        Z = Y->right;
    Z->parent = Y->parent;
    if(Y->parent == nullptr)
        p = Z;
    else if(Y == Y->parent->left)
        Y->parent->left = Z;
    else
        Y->parent->right = Z;
    if(Y != X)
        X->key = Y->key;
    if(Y->color == 'B')   // Naprawa struktury drzewa czerwono-czarnego
        while((Z != p) && (Z->color == 'B'))
        {
            if(Z == Z->parent->left)
            {
                W = Z->parent->right;
                if(W->color == 'R')
                {              // Przypadek 1
                    W->color = 'B';
                    Z->parent->color = 'R';
                    rotacjaLewo(p, Z->parent);
                    W = Z->parent->right;
                }
                if((W->left->color == 'B') && (W->right->color == 'B'))
                {              // Przypadek 2
                    W->color = 'R';
                    Z = Z->parent;
                    continue;
                }
                if(W->right->color == 'B')
                {              // Przypadek 3
                    W->left->color = 'B';
                    W->color = 'R';
                    rotacjaPrawo(p, W);
                    W = Z->parent->right;
                }
                W->color = Z->parent->color; // Przypadek 4
                Z->parent->color = 'B';
                W->right->color = 'B';
                rotacjaLewo(p, Z->parent);
                Z = p;         // To spowoduje zakończenie pętli
            }
            else
            {                // Przypadki lustrzane
                W = Z->parent->left;
                if(W->color == 'R')
                {              // Przypadek 1
                    W->color = 'B';
                    Z->parent->color = 'R';
                    rotacjaPrawo(p, Z->parent);
                    W = Z->parent->left;
                }
                if((W->left->color == 'B') && (W->right->color == 'B'))
                {              // Przypadek 2
                    W->color = 'R';
                    Z = Z->parent;
                    continue;
                }
                if(W->left->color == 'B')
                {              // Przypadek 3
                    W->right->color = 'B';
                    W->color = 'R';
                    rotacjaLewo(p, W);
                    W = Z->parent->left;
                }
                W->color = Z->parent->color;  // Przypadek 4
                Z->parent->color = 'B';
                W->left->color = 'B';
                rotacjaPrawo(p, Z->parent);
                Z = p;         // To spowoduje zakończenie pętli
            }
        }
    Z->color = 'B';
    delete Y;
}
int main ()
{
    node *p = nullptr;
    insertRBT(p, 3);insertRBT(p, 5);insertRBT(p, 2);insertRBT(p, 7);insertRBT(p, 1);
    printTree(p);
    removeRBT(p, p);
    cout <<endl;
    printTree(p);
    return 0;
}
