#include <iostream>
using namespace std;
struct node{
    int v, w;
    node *next;
};
node **init_graph (int n, int m)
{
    int x,y,w;
    node **graph = new node *[n];
    for(int i=0; i<n; i++)
        graph[i] = nullptr;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        node *p = new node;
        p->w=w;
        p->v = y;
        p->next = graph[x];
        graph[x] = p;
    }
    return graph;
}
int **init_macierz (int n, int m)
{
    int x,y,w;
    int **macierz = new int* [n];
    for(int i=0; i<n; i++){
        macierz[i] = new int[n];
        for(int j=0; j<n; j++)
            macierz[i][j] = -1;
    }
    for(int i=0; i<m; i++){
        cin>>x>>y>>w;
        macierz[x][y] = w;
    }
    return macierz;
}
void print_graph (node **graph, int n)
{
    for(int i=0; i<n; i++){
        cout<<i <<": ";
        for(node *ptr = graph[i]; ptr; ptr=ptr->next)
            cout<<ptr->v<<" ";
        cout<<endl;
    }
}
void print_macierz (int **macierz, int n)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<macierz[i][j]<<" ";
        cout<<endl;
    }
}
void DFS_graph (node **graph, int v, int n)
{
    bool *visited = new bool [n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    visited[v] = true;
    cout<<v<<" ";
    for(node *ptr = graph[v]; ptr; ptr = ptr->next)
        if(visited[ptr->v] == false)
            DFS_graph(graph, ptr->v, n);
}
void DFS_macierz (int **macierz, int v, int n)
{
    bool *visited = new bool [n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    visited[v] = true;
    cout<<v<<" ";
    for(int i=0; i<n; i++)
        if(macierz[v][i] != -1 && visited [i] == false)
            DFS_macierz(macierz, i, n);
}
int main ()
{
    int n, m;
    cin >>n >>m;
    node **graph = init_graph(n, m);
    int **macierz = init_macierz (n, m);
    //print_graph(graph, n);
    //print_macierz(macierz, n);
    DFS_graph(graph, 0, n);
    DFS_macierz(macierz, 0, n);
    return 0;
}
