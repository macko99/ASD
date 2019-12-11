#include <iostream>
using namespace std;
struct node {
    int val;
    node *next;
};
void print (node *first)
{
    while(first->next != nullptr)
    {
        cout<<first->val<<" ";
        first=first->next;
    }
    cout<<endl;
}
node *partition(node *&first, node *last) {
    node *pivot = first;
    node *end_copy = first;
    node *temp = first->next;
    while (temp != last) {
        if (temp->val < pivot->val)
        {
            end_copy->next = temp->next;
            temp->next = first;
            first = temp;
            temp = end_copy->next;
        }
        else
        {
            temp = temp->next;
            end_copy = end_copy->next;
        }
    }
    return pivot;
}
void quickSort(node *&first, node *&last) {
    if (first != last) {
        node *pivot = partition(first, last);
        quickSort(first, pivot);
        quickSort(pivot->next, last);
    }
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
    node *empty = new node;
    empty->val=0;
    empty->next=nullptr;
    head->next=empty;
    return empty;
}
int main()
{
    node *head = nullptr;
    add(head, 1); add(head, 4); add (head, 7);add(head, 3); add(head, 5);
    node *last = getLast(head);
    quickSort(head, last);
    print (head);
    return 0;
}
