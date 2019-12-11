#include <iostream>
using namespace std;
struct node
{
    int val;
    node *next;
};
void print (node *head)
{
    while( head != nullptr )
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
void *add (node *&head, int val)
{
    node *p = new node;
    p->val = val;
    p->next = head;
    head=p;
}
node *getLast (node *head)
{
    while (head != nullptr && head->next != nullptr)
        head=head->next;
    return head;
}
node *part(node *head, node *tail, node *&newHead, node *&newEnd)
{
    node *pivot = tail;
    node *prev = nullptr;
    while (head != pivot)
    {
        if (head->val < pivot->val)
        {
            if (newHead == nullptr)
                newHead = head;
            prev = head;
            head = head->next;
        }
        else
        {
            if (prev != nullptr)
                prev->next = head->next;
            node *tmp = head->next;
            head->next = nullptr;
            tail->next = head;
            tail = head;
            head= tmp;
        }
    }
    if (newHead == nullptr)
        newHead = pivot;
    newEnd = tail;
    return pivot;
}
node *quickSort(node *&head, node *tail)
{
    if (head == nullptr || head == tail)
        return head;
    node *newHead = nullptr;
    node *newEnd = nullptr;
    node *pivot = part(head, tail, newHead, newEnd);
    if (newHead != pivot)
    {
        node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;
        newHead = quickSort(newHead, tmp);
        tmp->next = pivot;
    }
    pivot->next = quickSort(pivot->next, newEnd);
    return newHead;
}
int main()
{
    node *head = nullptr;
    add(head, 4); add (head, 5);add(head, 3); add (head, 7);
    print (head);
    head = quickSort(head, getLast(head));
    print (head);
    return 0;
}
