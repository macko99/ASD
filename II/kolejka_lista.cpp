#include <iostream>
using namespace std;
struct node{
    node *next;
    int val;
};
void put (node *&Q, int val){
    node *p = new node;
    p->val =val;
    p->next=Q;
    Q=p;
}
int get (node *&Q){
    if(Q == nullptr){
        cout<<"error: empty";
        return 0;
    }
    node *p = Q;
    if(Q->next == nullptr){
        int res = Q->val;
        Q=nullptr;
        delete p;
        return res;
    }
    while(p->next->next != nullptr)
        p=p->next;
    int res = p->next->val;
    node *tmp = p->next;
    p->next = nullptr;
    delete tmp;
    return res;
}
bool isEmpty (node *Q){
return (Q == nullptr);
}
int main()
{
    node *Q = nullptr;
    put(Q, 4);put(Q, 5);put(Q, 6);put(Q, 7);put(Q, 8);
    cout<<get(Q)<<get(Q)<<get(Q)<<endl<<isEmpty(Q)<<endl<<get(Q)<<get(Q)<<endl<<isEmpty(Q)<<endl<<get(Q);
    return 0;
}
