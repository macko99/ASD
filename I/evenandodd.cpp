#include <iostream>
using namespace std;
struct Node{
    Node *next;
    int val;
};
struct TwoLists{
    Node *even;
    Node *odd;
};
TwoLists *split(Node *head)
{
    TwoLists *res = new TwoLists;
    res->even=nullptr;
    res->odd=nullptr;
    while(head != nullptr)
    {
        if((head->val)%2 == 0)
        {
            Node *tmp = head;
            head=head->next;
            tmp->next=res->even;
            res->even=tmp;
        }
        else
        {
            Node *tmp = head;
            head=head->next;
            tmp->next=res->odd;
            res->odd=tmp;
        }
    }
    return res;
}
void addNode (Node *&head, int val)
{
    Node *tmp = new Node;
    tmp->val = val;
    tmp->next=head;
    head=tmp;
}
void print (Node *head)
{
    while(head!= nullptr){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    Node *head = nullptr;
    addNode(head, 3);addNode(head, 2);addNode(head, 7);addNode(head, 4);
    print(head);
    TwoLists *res=split(head);
    print(res->even);
    print(res->odd);
    return 0;
}
