#include <iostream>
using namespace std;
int NWD (int a, int b)
{
    if (b == 0)
        return a;
    return NWD(b, a%b);
}
void shifter (int arr[], int n, int d)
{
    for (int i=0; i<NWD(d,n); i++)
    {
        int tmp = arr[i];
        int j = i;
        while (1)
        {
            int k = (j + d)%n;
            j = k;
            if (k == i)
                break;
            swap(arr[k], tmp);
        }
        arr[j] = tmp;
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n= sizeof(arr)/sizeof(int);
    int d;
    cin >>d;
    shifter(arr, n, d);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
