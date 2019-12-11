#include<iostream>
using namespace std;
struct node{
    double val;
    node *next;
};
void put(node *&head, double val)
{
    node *n = new node;
    n->val =val;
    if(head == nullptr || head->val > val)
    {
        n->next=head;
        head=n;
        return;
    }
    node *tmp=head;
    while(tmp->next != nullptr && tmp->next->val < val)
        tmp=tmp->next;
    n->next=tmp->next;
    tmp->next=n;
}
void BucketSort(double A[], int n)
{
    node *lista[10];
    for(int i=0; i<10; i++)
        lista[i]=nullptr;
    for(int i=0; i<n; i++)
        put(lista[int(A[i]*10)], A[i]);
    int k=0;
    for(int i=0; i<10; i++){
        while(lista[i] != nullptr){
            A[k++]=lista[i]->val;
            lista[i]=lista[i]->next;
        }
    }
}
int main()
{
    double tab[8]={0.4,0.6,0.66,0.71,0.79,0,0.34,0.99};
    BucketSort(tab, 8);
    for(int i=0; i<8; i++)
        cout<<tab[i]<<" ";
    return 0;
}
