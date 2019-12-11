#include <iostream>
using namespace std;
struct node{
    float val;
    node *next;
};
void put (node *&head, float val)
{
    node *n = new node;
    n->val = val;
    if( head == nullptr || n->val<head->val)
    {
        n->next=head;
        head=n;
        return;
    }
    node *p=head;
    while(p->next != nullptr && p->next->val < n->val)
        p=p->next;
    n->next=p->next;
    p->next=n;
}
void BucketSort (float A[], int n)
{
    node *lista[10];
    for(int i=0; i<10; i++)
        lista[i]= nullptr;
    for (int i=0; i<n; i++)
        put(lista[int(10*A[i])], A[i]);
    int k=0;
    for(int i=0; i<10; i++)
    {
        while(lista[i] != nullptr)
        {
            A[k++]=lista[i]->val;
            lista[i]=lista[i]->next;
        }
    }
}
int main()
{
    float A[5]={0.1,0.4,0.43,0.3,0.6};
    BucketSort(A, 5);
    for(int i=0; i<5; i++)
        cout<<A[i]<<" ";
    return 0;
}
