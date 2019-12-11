#include <iostream>
using namespace std;
struct stack{
    int *elements;
    int top;
    int max_size;
};
stack *new_stack (int size){
    stack *s = new stack;
    s->elements = new int[size];
    s->top = -1;
    s->max_size=size-1;
    return s;
}
void push (stack *s, int val){
    if(s->top == s->max_size){
        cout<<"error: full";
        return;
    }
    s->elements[++s->top]=val;
}
int pop (stack *s){
    if(s->top == -1){
        cout<<"error: empty";
        return 0;
    }
    s->top--;
    return s->elements[s->top+1];
}
bool is_empty (stack *s){
    return !(s->top);
}
int main (){
    stack *s = new_stack(5);
    push(s, 4);push(s, 3);push(s, 2);push(s, 1);push(s, 0);
    cout<<pop(s)<<pop(s)<<pop(s)<<pop(s)<<pop(s)<<pop(s);
    return 0;
}
