#include <iostream>
using namespace std;
bool indeksy (int A[], int n, int sum)
{
    int l=0, r=n-1;
    while (l < r)
    {
        if(A[l] + A[r] == sum) return 1;
        else if(A[l] + A[r] < sum)
            l++;
        else
            r--;
    }
    return 0;
}
int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int sum = 16;
    int n = sizeof(A)/sizeof(int);
    cout<<indeksy(A,n,sum);
    return 0;
}
