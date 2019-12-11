#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
};
Node* QuickerSort(Node* head)
{
    if(head == nullptr) return nullptr;

    Node* lesser,* equal,* greater,* l,* e,* g;
    lesser = new Node; equal = new Node; greater = new Node;
    lesser->next = equal->next = greater->next = nullptr;
    l = lesser; e = equal; g = greater;

    int c = head->val;
    while(head != nullptr)
    {
        if(head->val == c)
        {
            e->next = head;
            head = head->next;
            e = e->next;
            e->next = nullptr;
        }
        else if(head->val < c)
        {
            l->next = head;
            head = head->next;
            l = l->next;
            l->next = nullptr;
        }
        else
        {
            g->next = head;
            head = head->next;
            g = g->next;
            g->next = nullptr;
        }
    }
    lesser->next = QuickerSort(lesser->next);
    greater->next = QuickerSort(greater->next);

    Node *ret = new Node;
    ret->next = nullptr;
    Node *retTail = ret;

    ret->next = lesser->next;
    while(retTail->next != NULL)
        retTail = retTail->next;
    retTail->next = equal->next;
    while(retTail->next != NULL)
        retTail = retTail->next;
    retTail->next = greater->next;
    retTail = ret->next;
    return retTail;
}
void addNode(Node *&head, int val)
{
    Node *tmp = new Node;
    tmp->val = val;
    tmp->next=head;
    head=tmp;
}
void print(Node* head)
{
    while(head!= nullptr){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    Node* head=nullptr;
    addNode(head, 3);addNode(head, 2);addNode(head, 7);addNode(head, 11);addNode(head, 5);addNode(head, 7);
    print(head);
    head = QuickerSort(head);
    print(head);
}
