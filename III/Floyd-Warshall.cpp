#include <iostream>
using namespace std;
void print_path(int **parent, int i, int j)
{
    if(i == j) cout<<i <<" ";
    else if (parent[i][j] == -1) cout<<"no path";
    else
    {
        print_path(parent, i, parent[i][j]);
        cout<<j<< " ";
    }
}
void Floyd_Warshall (int **parent, int **macierz, int n)
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(macierz[i][j] > macierz[i][k] + macierz[k][j]){
                    macierz[i][j] = macierz[i][k] + macierz[k][j];
                    parent[i][j] = parent[k][j];
            }
    for(int i=0; i<n; i++)
        if(macierz[i][i] <0){
            cout<<"cykl ujemny";
            return;
        }
    cout<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cout<<i<<"-"<<j<<" : ";
            print_path(parent, i, j);
            if(macierz[i][j] < INT_MAX/2)
                cout<<" $$dist: "<<macierz[i][j]<<endl;

        }
}
int main ()
{
    int x,y,w, n, m;
    cin >>n >>m;
    int **parent = new int *[n];
    int **macierz = new int* [n];
    for(int i=0; i<n; i++){
        macierz[i] = new int[n];
        parent[i] = new int[n];
        for(int j=0; j<n; j++){
            if(i != j) macierz[i][j] = INT_MAX/2;
            else macierz[i][j] = 0;
            parent[i][j] = -1;
        }
    }
    for(int i=0; i<m; i++){
        cin>>x>>y>>w;
        macierz[x][y] = w;
        parent[x][y] = x;
    }
    Floyd_Warshall(parent, macierz, n);
    return 0;
}
