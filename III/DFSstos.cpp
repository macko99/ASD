#include <iostream>
using namespace std;
struct stos{
    stos *next;
    int v;
};
void push_stos (stos *&S, int v)
{
    stos *p = new stos;
    p->v = v;
    p->next = S;
    S = p;
}
int get_stos (stos *&S)
{
    if(S == nullptr)
        return -1;
    int res = S->v;
    S = S->next;
    return res;
}
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
    stos *S = nullptr;
    bool *visited = new bool [n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    visited[v] = true;
    push_stos(S, v);
    while (S)
    {
        int x = get_stos(S);
        cout<<x<<" ";
        for(node *ptr = graph[x]; ptr; ptr=ptr->next){
            if(visited[ptr->v] == false){
                visited[ptr->v] = true;
                push_stos(S, ptr->v);
            }
        }
    }
}
void DFS_macierz (int **macierz, int v, int n)
{
    stos *S = nullptr;
    bool *visited = new bool [n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    visited[v] = true;
    push_stos(S, v);
    while (S)
    {
        int x = get_stos(S);
        cout<<x<<" ";
        for(int i=0; i<n; i++){
            if(macierz[x][i] != -1 && visited[i] == false){
                visited[i] = true;
                push_stos(S, i);
            }
        }
    }
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
