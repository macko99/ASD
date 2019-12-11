#include <iostream>
using namespace std;
struct pupil{
    int grupa;
    pupil *next;
};
void add (pupil *&head, int val)
{
    pupil *p = new pupil;
    p->grupa = val;
    p->next=head;
    head = p;
}
void print (pupil *head)
{
    while(head != nullptr){
        cout<<head->grupa<<" ";
        head=head->next;
    }
    cout<<endl;
}
int distance (pupil *head)
{
    int half=1;
    pupil *fast=head, *slow=head->next;
    while(fast != nullptr)
    {
        fast=(fast->next)->next;
        slow=slow->next;
        half++;
    }
    pupil *mid = slow;
    fast=head;
    int lewy=0, prawy=0, dist=0;
    while(1)
    {
        if(fast == mid || slow == nullptr)
            break;
        if(fast->grupa == 1 && slow->grupa == 0)
        {
            dist+=(half+prawy-lewy);
            fast=fast->next;
            slow=slow->next;
            lewy++; prawy++;
        }
        else if(fast->grupa == 1 && slow ->grupa == 1)
        {
            slow=slow->next;
            prawy++;
        }
        else if(fast->grupa == 0 && slow ->grupa == 0)
        {
            fast=fast->next;
            lewy++;
        }
        else
        {
            fast=fast->next;
            slow=slow->next;
            lewy++; prawy++;
        }
    }
    return dist*2;
}
int main()
{
    pupil *head = nullptr;
    add(head, 0);add(head, 1);add(head, 1);add(head, 0);add(head, 1);add(head, 1);
    add(head, 0);add(head, 0);add(head, 0);add(head, 1);add(head, 0);add(head, 1);
    cout<<"n: "<<distance(head)<<endl;
    print(head);
    return 0;
}
