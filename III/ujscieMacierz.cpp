#include <iostream>
using namespace std;
bool **initMacierz (int n, int m)
{
    int v1,v2;
    bool **macierz = new bool *[n];
    for (int i=0; i<n; i++){
        macierz[i] = new bool [n];
        for (int j=0; j<n; j++)
            macierz[i][j] = false;
    }
    for(int i = 0; i<m; i++)
    {
        cin >>v1>>v2;
        macierz[v1][v2] = true;
    }
    return macierz;
}
bool check (bool **macierz, int kolumna, int n)
{
    for(int i=0; i<n; i++)
    {
        if(i != kolumna && macierz[i][kolumna] == 0)
            return false;
    }
    return true;
}
int ujscie (bool **macierz, int n)
{
    bool flag = true;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(macierz[i][j] == 1)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            if(check(macierz, i, n) == true)
                return i;
        flag = true;
    }
    return -1;
}
int main()
{
    int n, m, v1, v2;
    cin>>n >>m;
    bool **macierz = initMacierz(n, m);

    cout<<endl<<ujscie(macierz, n);
}
