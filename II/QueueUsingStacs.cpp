#include <iostream>
using namespace std;
struct node{
    node *next;
    int val;
};
struct queue{
    node *push;
    node *pop;
};
void push_queue(queue &Q, int val)
{
    node *p = new node;
    p->val =val;
    p->next=Q.push;
    Q.push=p;
}
int pop_queue(queue &Q)
{
    if(Q.pop == nullptr){
        while(Q.push != nullptr){
            node *p = new node;
            p->val=Q.push->val;
            p->next=Q.pop;
            Q.pop=p;
            node *tmp=Q.push;
            Q.push=Q.push->next;
            delete tmp;
        }
        if(Q.pop == nullptr){cout<<"error"; return NULL;}
    }
    int res=Q.pop->val;
    node *tmp =Q.pop;
    Q.pop=Q.pop->next;
    delete tmp;
    return res;
}
void init_queue(queue &Q)
{
    Q.push=nullptr;
    Q.pop=nullptr;
}
int main()
{
    queue Q;
    init_queue(Q);
    push_queue(Q,2);
    cout<<pop_queue(Q);
    return 0;
}
