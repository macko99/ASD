#include<iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int findMedian(int arr[], int n)
{
    insertionSort(arr, n);
    return arr[n/2];
}
int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x) break;
    swap(arr[i], arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
int kthSmallest(int arr[], int l, int r, int k)
{
    int n = r-l+1;
    int i, median[(n+4)/5];
    for (i=0; i<n/5; i++)
        median[i] = findMedian(arr+l+i*5, 5);
    if (i*5 < n)
    {
        median[i] = findMedian(arr+l+i*5, n%5);
        i++;
    }
    int medOfMed;
    if(i == 1)
        medOfMed = median[i-1];
    else
        medOfMed = kthSmallest(median, 0, i-1, i/2);
    int pos = partition(arr, l, r, medOfMed);
    int ile = pos-l+1;
    if (ile == k)
        return arr[pos];
    if (ile > k)
        return kthSmallest(arr, l, pos-1, k);
    return kthSmallest(arr, pos+1, r, k-ile);
}
int main()
{
    int arr[] = {1, 1, 2, 7, 4, 19, 26, 30};
    int n = sizeof(arr)/sizeof(arr[0]), k = n/2+1;
    cout<<kthSmallest(arr, 0, n-1, k)<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
