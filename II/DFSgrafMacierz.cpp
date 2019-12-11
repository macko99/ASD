#include <iostream>
using namespace std;
const int n = 5, m = 4;
bool **initMacierz ()
{
    bool **macierz = new bool *[n];
    for (int i=0; i<n; i++)
        macierz[i] = new bool [n];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            macierz[i][j] = 0;
    int v1,v2;
    for(int i = 0; i<m; i++)
    {
        cin >>v1>>v2;
        macierz[v1][v2] = 1;
    }
    return macierz;
}
bool *initVisited ()
{
    bool *visited = new bool [n];
    for (int i=0; i<n; i++)
        visited[i] = false;
    return visited;
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
void DFS (bool **macierz, int v)
{
    bool *visited = initVisited();
    visited[v] = true;
    cout<<v<<" ";
    for(int i =0; i<n; i++)
        if(macierz[v][i] == 1 && visited[i] == false )
            DFS(macierz, i);
}
int main()
{
    bool **macierz = initMacierz();
    printMacierz(macierz);
    DFS(macierz, 0);
}
