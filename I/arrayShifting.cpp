#include <iostream>
using namespace std;
int NWD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return NWD(b, a%b);
}
void leftRotate(int arr[], int d, int n)
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
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n = sizeof(arr)/sizeof(int);
    leftRotate(arr, 4, n);

    for (int i=0; i<n; i++)
        cout <<arr[i]<< " ";
    return 0;
}
