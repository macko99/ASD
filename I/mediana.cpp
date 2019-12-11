#include <iostream>
using namespace std;
int partition (int A[], int p, int r)
{
    int x=A[r];
    int i = p-1;
    for(int j=p; j<r; j++)
    {
        if(A[j] < x)
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[r],A[i+1]);
    return i+1;
}
int select (int A[], int p, int r, int i)
{
    if (p == r) return A[p];
    int q = partition (A, p, r);
    int k = q-p+1;
    if (i == k) return A[q];
    if (i < k) return select(A, p, q-1, i);
    return select(A, q+1, r, i-k);
}
int main()
{
    int A[5]={5,3,1,4,2};
    cout <<select(A,0,4,2) <<endl;
    return 0;
}
