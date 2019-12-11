#include <iostream>
using namespace std;
bool subsum (int A[], int n, int T)
{
    bool F[n][T+1];
    for(int i=0; i<n; i++)
        F[i][0] = true;
    for(int k=0; k<=T; k++)
        F[0][k] = k == 0 || k == A[0];

    for(int i=0; i<n; i++)
        for(int k=0; k<=T; k++){
            if(k<A[i])
                F[i][k] = F[i-1][k];
            else
                F[i][k] = F[i-1][k] || F[i-1][k-A[i]];
        }

    return F[n-1][T];
}

int main()
{
    int k = 2, n = 5;
    int A[n] = {1,5,3,5,4};
    cout<<subsum(A, n, k);
}
