#include <iostream>
using namespace std;
struct node{
int val;
node *next;
};
node *removeMAX(node *head)
{
    node *p=head;
    node *q= nullptr;
    for(node*n=head; n->next!=nullptr; n=n->next)
    {
        if(n->next->val>n->val)
        {
            q=n;
            p=n->next;
        }
    }
    if(q==nullptr)
    {
        head=head->next;
        p->next=nullptr;
        return p;
    }
    q->next=p->next;
    p->next=nullptr;
    return p;
}
node *SelectionSort(node *head)
{
    node *n = nullptr;
    while(head->next!=nullptr)
    {
        node *p=removeMAX(head);
        p->next=n;
        n=p;
    }
    return n;
}
void add(node *&head, int val)
{
    node *n = new node;
    n->val=val;
    n->next=head;
    head=n;
}
int main()
{
    node *head=nullptr;
    node *p=nullptr;
    add(head, 2);add(head, 4);add(head, 8);add(head, 1);add(head, 00);
    head=SelectionSort(head);
        while(head!=nullptr){
        cout<<head->val<<" ";
        head=head->next;
    }
}
