#include <iostream>
using namespace std;
struct node{
    node *left;
    node *right;
    node *parent;
    int bf;
    int key;
};
void printTree (node *p)
{
    if(p == nullptr) return;
    cout<<p->key<<" ";
    printTree(p->left);
    printTree(p->right);
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
node *maxiNode (node *p)
{
    while (p->right != nullptr)
        p=p->right;
    return p;
}
node *poprzednikNode (node *p, node *n)
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
void RR (node *&root, node *A)
{
    node *B = A->right;
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
    else root = B;
    
    if(B->bf == -1)
        A->bf = B->bf = 0;
    else
    {
        A->bf = -1;
        B->bf = 1;
    }
}
void LL (node *&root, node *A)
{
    node *B = A->left;
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
    else root = B;
    
    if(B->bf == 1)
        A->bf = B->bf = 0;
    else
    {
        A->bf = 1;
        B->bf = -1;
    }
}
void RL (node *&root, node *A)
{
    node *B = A->right, *C = B->left, *p  = A->parent;
    B->left = C->right;
    if(B->left)
        B->left->parent = B;
    A->right = C->left;
    if(A->right)
        A->right->parent = A;
    C->left = A;
    C->right = B;
    A->parent = B->parent = C;
    C->parent = p;
    if(p)
    {
        if(p->left == A)
            p->left = C;
        else
            p->right = C;
    }
    else root = C;
    
    if(C->bf == -1)
        A->bf =  1;
    else
        A->bf = 0;
    
    if(C->bf ==  1)
        B->bf = -1;
    else
        B->bf = 0;
    
    C->bf = 0;
}
void LR (node *&root, node *A)
{
    node *B = A->left, *C = B->right, *p = A->parent;
    B->right = C->left;
    if(B->right)
        B->right->parent = B;
    A->left = C->right;
    if(A->left)
        A->left->parent = A;
    C->right = A;
    C->left = B;
    A->parent = B->parent = C;
    C->parent = p;
    if(p)
    {
        if(p->left == A)
            p->left = C;
        else
            p->right = C;
    }
    else root = C;
    
    if(C->bf ==  1)
        A->bf = -1;
    else
        A->bf = 0;
    
    if(C->bf == -1)
        B->bf =  1;
    else
        B->bf = 0;
    
    C->bf = 0;
}
void insertAVL (node *&root, int k)
{
    node *w = new node, *p = root;
    w->left = w->right = w->parent = nullptr;
    w->key  = k;
    w->bf  = 0;
    //----------------------------------------
    // FAZA 1 - wstawienie węzła do drzewa AVL
    //----------------------------------------
    if(!p)
        root = w;       // jeśli drzewo jest puste, to węzeł w umieszczamy w korzeniu
    else
    {                      // inaczej szukamy miejsce dla w
        while(true)
            if(k < p->key)     // porównujemy klucze
            {
                if(!p->left)     // jeśli p nie posiada lewego syna, to
                {
                    p->left = w;   // lewym synem p staje się węzeł w
                    break;         // wychodzimy z pętli
                }
                p = p->left;     // inaczej przechodzimy do lewego syna
            }
            else
            {
                if(!p->right)    // jeśli p nie posiada prawego syna, to
                {
                    p->right = w;  // prawym synem staje się węzeł w
                    break;         // wychodzimy z pętli
                }
                p = p->right;    // inaczej przechodzimy do prawego syna
            }
        w->parent = p;           // ojcem w jest p
        //---------------------------------
        // FAZA 2 - równoważenie drzewa AVL
        //---------------------------------
        if(p->bf)
            p->bf = 0; // UWAGA NR 1
        else
        {
            if(p->left == w)   // UWAGA NR 2
                p->bf = 1;
            else
                p->bf = -1;
            node *r = p->parent;        // będziemy szli w górę drzewa w kierunku korzenia
            bool t = false;// r i p wskazują ojca i syna na tej ścieżce
            while(r)
            {
                if(r->bf)
                {
                    t = true;     // ustalamy wynik pętli
                    break;        // przerywamy pętlę
                }
                if(r->left == p)
                    r->bf =  1;// inaczej modyfikujemy r.bf
                else
                    r->bf = -1;
                p = r;          // przechodzimy w górę na wyższy poziom
                r = r->parent;
            }
            if(t)             // jeśli r.bf = +/- 1, to musimy
            {                 // równoważyć drzewo
                if(r->bf == 1)
                {
                    if(r->right == p)
                        r->bf = 0;  // gałęzie się równoważą
                    else if(p->bf == -1)
                        LR(root,r);
                    else
                        LL(root,r);
                }
                else
                {              // r.bf = -1
                    if(r->left == p)
                        r->bf = 0;  // gałęzie się równoważą
                    else if(p->bf == 1)
                        RL(root,r);
                    else
                        RR(root,r);
                }
            }
        }
    }
}
node *removeAVL(node *&root, node *x)
{
    node  *t,*y,*z;
    bool nest;
    if(x->left && x->right)
    {
        y = removeAVL(root,poprzednikNode(root, x));
        nest = false;
    }
    else
    {
        if(x->left)
        {
            y = x->left;
            x->left = nullptr;
        }
        else
        {
            y = x->right;
            x->right = nullptr;
        }
        x->bf = 0;
        nest  = true;
    }
    if(y)
    {
        y->parent = x->parent;
        y->left = x->left;
        if(y->left)
            y->left->parent = y;
        y->right = x->right;
        if(y->right)
            y->right->parent = y;
        y->bf = x->bf;
    }
    if(x->parent)
    {
        if(x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    else
        root = y;
    if(nest)
    {
        z = y;
        y = x->parent;
        while(y)
        {
            if(!y->bf)
            {              // Przypadek nr 1
                if(y->left == z)
                    y->bf = -1;
                else
                    y->bf = 1;
                break;
            }
            else
            {
                if(((y->bf == 1) && (y->left == z)) || ((y->bf == -1) && (y->right == z)))
                {           // Przypadek nr 2
                    y->bf = 0;
                    z = y;
                    y = y->parent;
                }
                else
                {
                    if(y->left == z)
                        t = y->right;
                    else
                        t = y->left;
                    if(!t->bf)
                    {         // Przypadek 3A
                        if(y->bf == 1)
                            LL(root,y);
                        else
                            RR(root,y);
                        break;
                    }
                    else if(y->bf == t->bf)
                    {         // Przypadek 3B
                        if(y->bf == 1)
                            LL(root,y);
                        else
                            RR(root,y);
                        z = t;
                        y = t->parent;
                    }
                    else
                    {         // Przypadek 3C
                        if(y->bf == 1)
                            LR(root,y);
                        else
                            RL(root,y);
                        z = y->parent;
                        y = z->parent;
                    }
                }
            }
        }
    }
    return x;
}
void removeAVL2 (node *&root, int k)
{
    node *n = findNodeIte(root, k);
    removeAVL(root, n);
}
int main()
{
    node *p = nullptr;
    insertAVL(p, 4);insertAVL(p, 12);insertAVL(p, 6);insertAVL(p, 2);insertAVL(p, 1);insertAVL(p, 10);
    printTree(p);
    cout<<endl;
    removeAVL2(p, 2);
    printTree(p);
    return 0;
}
