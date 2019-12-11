#include <iostream>
using namespace std;
struct node{
    int val;
    node *next;
    node *prev;
};
void print (node *head)
{
    while (head->next != nullptr)
    {
        cout<<head->val <<" ";
        head=head->next;
    }
    cout<<head->val <<" "<<endl;
    while (head != nullptr)
    {
        cout<<head->val <<" ";
        head=head->prev;
    }
    cout<<endl;
}
void addLast (node *&head, int val)
{
    node *tmp = new node;
    tmp->val = val;
    tmp->next = nullptr;
    if (head == nullptr)
    {
        tmp->prev = nullptr;
        head = tmp;
    }
    else
    {
        node *i = head;
        while (i->next != nullptr)
            i=i->next;
        tmp->prev = i;
        i->next = tmp;
    }
}
node *mergeLists(node *a, node *b)
{
    if (a == nullptr)
        return b;
    else if (b == nullptr)
        return a;
    node *res = nullptr;
    if(a->val <= b->val)
    {
        res = a;
        res->next = mergeLists(a->next, b);
        res->next->prev = a;
    }
    else
    {
        res = b;
        res->next = mergeLists(a, b->next);
        res->next->prev = b;
    }
    return res;
}
void splitLists(node *&head, node *&a, node *&b)
{
    if(head == nullptr || head->next == nullptr)
    {
        a = head;
        b = nullptr;
        return;
    }
    node *slow = head;
    node *fast = head->next;
    while(fast != nullptr)
    {
        fast=fast->next;
        if(fast != nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    a = head;
    b = slow->next;
    b->prev = nullptr;
    slow->next = nullptr;
}
void mergeSort(node *&head)
{
    if(head == nullptr || head->next == nullptr)
        return;
    node *a;
    node *b;
    splitLists(head, a, b);
    mergeSort(a);
    mergeSort(b);
    head = mergeLists(a, b);
}
int main()
{
    node *head = nullptr;
    node *a = nullptr;
    node *b = nullptr;
    addLast(head, 6); addLast(head, 8); addLast(head, 4); addLast(head, 3); addLast(head, 1); addLast(head, 9);
	mergeSort(head);
	print(head);
	return 0;
}
