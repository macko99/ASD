#include <iostream>
using namespace std;
int max(int a, int b) {
    if(a>b) return a;
    return b;
}
struct snode {
    int val;
    int lvl;
    snode **next;
};
struct skiplist {
    snode *first;
    int maxlvl;
};
void init(skiplist* a, int maxlvl) {
    a->maxlvl = maxlvl;
    a->first = new snode;
    a->first->lvl = maxlvl;
    a->first->next = new snode*[maxlvl];
    for (int i = 0; i < maxlvl; i++)
        a->first->next[i] = NULL;
}
int getlvl(skiplist *a) {
    int lvl = 1;
    while (rand()%2 != 1)
        lvl++;
    if(lvl > a->maxlvl) return a->maxlvl;
    return lvl;
}
bool find(skiplist *a, int val) {
    int i = a->maxlvl - 1;
    snode *temp = a->first;
    while (i >= 0)
    {
        while (temp->next[i]!=NULL && temp->next[i]->val < val)
            temp = temp->next[i];
        if (temp->next[i] == NULL || temp->next[i]->val > val)
            i--;
        else if (temp->next[i]->val == val)
            return true;
    }
    return false;
}
void insert(skiplist *&a, int val) {
    snode *insert = new snode;
    int lvl = getlvl(a);
    insert->lvl = lvl;
    insert->val = val;
    insert->next = new snode*[lvl];
    for (int i = lvl - 1; i >= 0; i--)
    {
        snode *temp = a->first;
        while (temp->next[i] != NULL && temp->next[i]->val <= val)
            temp = temp->next[i];
        insert->next[i] = temp->next[i];
        temp->next[i] = insert;
    }
}
void del(skiplist *&a, int val) {
    int i = a->maxlvl - 1;
    snode *temp = a->first;
    while (i >= 0)
    {
        while (temp->next[i]!=NULL && temp->next[i]->val < val)
            temp = temp->next[i];
        if (temp->next[i]==NULL || temp->next[i]->val > val)
            i--;
        else if (temp->next[i]->val == val)
        {
            for (i; i >= 0; i--)
            {
                snode *help = temp->next[i];
                temp->next[i] = help->next[i];
                delete help;
                return;
            }
        }
    }
}
void print(skiplist *a) {
    snode *temp = a->first;
    temp = temp->next[0];
    while (temp != NULL)
    {
        cout <<temp->val <<" ";
        temp = temp->next[0];
    }
    cout << endl;
}
skiplist* merge(skiplist *&a, skiplist *&b) {
    skiplist* exit = new skiplist;
    init(exit, max(a->maxlvl, b->maxlvl));
    snode *tempa = a->first;
    snode *tempb = b->first;
    snode *tempexit = exit->first;
    while (tempa->next[0] != NULL || tempb->next[0] != NULL)
    {
        if (tempb->next[0] == NULL || ( tempa->next[0]->val < tempb->next[0]->val))
        {
            snode*insert = tempa->next[0];
            for (int i = insert->lvl - 1; i >= 0; i--)
            {
                while (tempexit->next[i] != NULL)
                    tempexit = tempexit->next[i];
                tempa->next[i] = insert->next[i];
                tempexit->next[i] = insert;
                insert->next[i] = NULL;
                tempexit = exit->first;
            }
        }
        if (tempa->next[0] == NULL || tempb->next[0]->val < tempa->next[0]->val)
        {
            snode*insert = tempb->next[0];
            for (int i = insert->lvl - 1; i >= 0; i--)
            {
                while (tempexit->next[i] != NULL)
                    tempexit = tempexit->next[i];
                tempb->next[i] = insert->next[i];
                tempexit->next[i] = insert;
                insert->next[i] = NULL;
                tempexit = exit->first;
            }
        }
    }
    return exit;
}
int main()
{
    skiplist* a = new skiplist;
    skiplist* b = new skiplist;
    init(b, 9);
    insert(b, 3);
    insert(b, 11);
    insert(b, 12);
    insert(b, 0);
    insert(b, 5);
    init(a,9);
    insert(a, 2);
    insert(a, 5);
    insert(a, 6);
    insert(a, 1);
    insert(a, 4);
    del(a, 5);
    print(a);
    print(b);
    cout << find(a, 5) << endl;
    cout << find(a, 4) << endl;
    skiplist* c = merge(a, b);
    print(c);
}
