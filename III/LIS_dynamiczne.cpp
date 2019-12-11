#include <iostream>
using namespace std;
int lis (int A[], int n)
{
    int F[n], ind_r = 0;
    for(int i=0; i<n; i++)
    {
        F[i] = 1;
        for(int j =0; j<i; j++)
            if(A[j] < A[i] && F[i] < F[j]+1){
                F[i] = F[j]+1;
            }
        if(F[i] > F[ind_r])
            ind_r = i;
    }
    return F[ind_r];
}
int main()
{
    int n = 9;
    int A[n] = {3,5,1,7,4,8,2,9,6};
    cout<<lis(A, n);
}
