#include <iostream>
using namespace std;
/*void BucketSort (float A[], int k)
{
    list *B;
    B = new list[k];
    for (int i=0; i<N; i++)
        put(B[int(k*A[i])], A[i]);
    for (int i=0; i<k; i++)
        sort(B[i]);
    // przepisz z B do A
}*/
int partition (int t[], int p, int v)
{
    int x=t[v];
    int i = p-1;
    for(int j=p; j<v; j++)
    {
        if(t[j] < x)
        {
            i++;
            swap(t[i],t[j]);
        }
    }
    swap(t[v],t[i+1]);
    return i+1;
}
int select (int A[], int p, int r, int i)
{
    if (p == r) return A[p];
    int q = partition (A, p, r);
    int k = q-p+1;
    if (i == k) return A[q];
    if (i < k) return select(A, p, q-1, i);
    return select(A, q+1,r, i-k);
}
int main()
{
    int A[5]={1,5,3,9,5};

    cout <<select(A,0,4,2) <<endl;
    return 0;
}
