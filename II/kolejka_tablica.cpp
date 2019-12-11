#include <iostream>
using namespace std;
struct node{
    int head, tail, max_size, size;
    int *elements;
};
node *new_queue (int size){
    node *Q = new node;
    Q->head=0;
    Q->tail=0;
    Q->max_size=size;
    Q->size=0;
    Q->elements = new int[size];
    return Q;
}
void put (node *Q, int val){
    if(Q->size == Q->max_size){
        cout<<"error: full";
        return ;
    }
    Q->elements[Q->tail] = val;
    if(Q->tail == Q->max_size)
        Q->tail = 0;
    else
        Q->tail++;
    Q->size++;
}
int get (node *Q){
    if(Q->size == 0){
        cout<<"error: empty";
        return 0;
    }
    int res = Q->elements[Q->head];
    if(Q->head == Q->max_size)
        Q->head = 0;
    else
        Q->head++;
    Q->size--;
    return res;
}
int main(){
    node *Q = new_queue(5);
    put(Q,4);put(Q,5);put(Q,6);put(Q,7);put(Q,8);put(Q,10);
    cout<<get(Q)<<get(Q)<<get(Q)<<get(Q)<<get(Q)<<get(Q);
    return 0;
}
