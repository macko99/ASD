#include <iostream>
using namespace std;
struct node {
    node *next;
    int val;
};
void push (node *&s, int val){
    node *p = new node;
    p->val = val;
    p->next = s;
    s = p;
}
int pop (node *&s){
    if(s == nullptr){
        cout<<"error: empty";
        return 0;
    }
    int res = s->val;
    node *tmp = s;
    s = s->next;
    delete tmp;
    return res;
}
bool isEmpty (node *s){
    return (s == nullptr);
}
int main (){
    node *s = nullptr;
    push(s, 4);push(s, 5);push(s, 6);push(s, 7);push(s, 8);
    cout<<pop(s)<<pop(s)<<pop(s)<<endl<<isEmpty(s)<<endl<<pop(s)<<pop(s)<<endl<<isEmpty(s)<<endl;
    return 0;
}
