#include <iostream>
using namespace std;
int backpack(int W[], int C[], int m, int n) {
    n++; m++;
    int f[n][m];
    for (int i = 0; i < n; i++)
        f[i][0] = 0;
    for (int i = 0; i < m; i++)
        f[0][i] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (W[i-1] > j)
                f[i][j] = f[i - 1][j];
            else {
                int w = j - W[i-1];
                if (w < 0)
                    w = 0;
                f[i][j] = max(f[i - 1][j], f[i-1][w] + C[i-1]);
            }
        }
    }
    return f[n-1][m-1];
}
int main()
{
    int waga[5] =  {2,5,8,1,1};
    int value[5] = {1,5,8,2,4};
    int W = 11;
    cout<<backpack(waga, value, W, 5);
}
