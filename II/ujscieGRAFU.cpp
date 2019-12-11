#include <iostream>
using namespace std;
const int n=4, m = 4;
bool **initMacierz ()
{
    bool **macierz = new bool *[n];
    for (int i=0; i<n; i++)
        macierz[i] = new bool [n];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            macierz[i][j] = 0;
    return macierz;
}
void printMacierz (bool **macierz)
{
     for (int i=0; i<n; i++)
     {
        for (int j=0; j<n; j++)
            cout<<macierz[i][j]<<" ";
        cout<<endl;
     }
}
bool check (bool **macierz, int kolumna)
{
    for(int i=0; i<n; i++)
    {
        if(i != kolumna && macierz[i][kolumna] == 0)
            return false;
    }
    return true;
}
bool ujscie (bool **macierz)
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
            if(check(macierz, i) == true)
                return true;
        flag = true;
    }
    return false;
}
int main()
{
    int v1, v2;
    bool **macierz = initMacierz();

    for(int i = 0; i<m; i++)
    {
        cin >>v1>>v2;
        macierz[v1][v2] = 1;
    }

    printMacierz(macierz);
    cout<<endl<<ujscie(macierz);
}
