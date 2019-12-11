#include <iostream>
using namespace std;
struct node{
    int val;
    node *next;
};
node *partition (node *&first, node *last)
{
    node *pivot=first;
    node *end_copy=first;
    node *tmp =first->next;
    while(tmp != last)
    {
        if(tmp->val < pivot->val)
        {
            end_copy->next=tmp->next;
            tmp->next=first;
            first=tmp;
            tmp=end_copy->next;
        }
        else
        {
            tmp=tmp->next;
            end_copy=end_copy->next;
        }
    }
    return pivot;
}
void QuickSort(node *&first, node *&last)
{
    if(first != last)
    {
        node *pivot = partition(first, last);
        QuickSort(first, pivot);
        QuickSort(pivot->next, last)
    }
}
