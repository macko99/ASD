#include <iostream>
using namespace std;
struct sum
{
    int val;
    int x;
};
print2 (sum sumy[], int n)
{
    for(int i=0; i<n; i++)
        cout<<sumy[i].val<<", x: "<<sumy[i].x<<endl;
    cout<<endl;
}
print (int A[], int n)
{
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
void sumSort(int A[], int B[], int n)
{
    sum *sumy = new sum[n];
    for(int i=0; i<n; i++)
    {
        sumy[i].x=i*n;
        sumy[i].val=0;
        for(int j=0; j<n; j++)
            (sumy[i].val)+=A[n*i+j];
    }
    print2(sumy, n);

    int max, min;
    max=min=sumy[0].val;
    for(int i=1; i<n; i++)
    {
        if(sumy[i].val>max)
            max=sumy[i].val;
        if(sumy[i].val<min)
            min=sumy[i].val;
    }

    int k =(max-min)+1;
    sum *sumy2 = new sum[n];
    int C[k];
    for(int i=0; i<k; i++) C[i]=0;
    for(int i=0; i<n; i++) C[(sumy[i].val - min)]++;
    for(int i=1; i<k; i++) C[i]+=C[i-1];
    for(int i=n-1; i>=0; i--) sumy2[--C[(sumy[i].val -min)]]=sumy[i];

    for(int i=0; i<n; i++)
    {
        int tmp=sumy2[i].x;
        for(int j=0; j<n; j++)
            B[i*n+j]=A[tmp+j];
    }
    delete sumy;
	delete sumy2;
}
int main()
{
    const int n=3;
    int A[n*n]={2,4,6,11,3,9,0,3,12}, B[n*n];
    print(A, n*n);
	sumSort(A, B, n);
	print(B, n*n);
	return 0;
}
