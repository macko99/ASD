#include <iostream>
#define N 5
#define k 5
using namespace std;
void countingSort(int A[N])
{
    int B[N];
    int C[k];
    for (int i=0; i<k; i++) C[i]=0;
    for (int i=0; i<N; i++) C[A[i]]++;
    for (int i=1; i<k; i++) C[i]+=C[i-1];
    for (int i=N-1; i>=0; i--) B[--C[A[i]]]=A[i];
    for(int i=0; i<N; i++) A[i]=B[i];
}
int main()
{
    int A[N]={4,3,4,2,1};
    countingSort(A);
    for(int i=0; i<N; i++)
        cout<<A[i]<<" ";
    return 0;
}
