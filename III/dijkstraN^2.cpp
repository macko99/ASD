#include <iostream>
using namespace std;
struct node{
    node *next;
    int v, w;
};
node ** initGraf (int n, int m)
{
    node **graf = new node *[n];
    for (int i=0; i<n; i++)
        graf[i] = nullptr;
    int v1, v2, w;
    for(int i = 0; i<m; i++){
        cin >>v1>>v2>>w;
        node *p = new node;
        p->v = v2;
        p->w = w;
        p->next = graf[v1];
        graf[v1] = p;
    }
    return graf;
}
int **initMacierz (int n, int m)
{
    int **macierz = new int *[n];
    for (int i=0; i<n; i++)
        macierz[i] = new int [n];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            macierz[i][j] = -1;
    int v1,v2,w;
    for(int i = 0; i<m; i++)
    {
        cin >>v1>>v2>>w;
        macierz[v1][v2] = w;
    }
    return macierz;
}
int minDistance (int *dist, bool *zbiorS, int n){
    int mini = INT_MAX, index;
    for(int i =0; i<n; i++){
        if(zbiorS[i] == false && dist[i] <= mini){
            mini = dist[i];
            index = i;
        }
    }
    return index;
}
void dijkstra (node **graf, int n, int start)
{
    bool *zbiorS = new bool [n];
    int *dist = new int [n];
    int *p = new int [n];
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
        p[i] = -1;
        zbiorS[i] = false;
    }

    dist[start] = 0;
    for(int i=0; i<n; i++)
    {
        int u = minDistance(dist, zbiorS, n);
        zbiorS[u] = true;

        for(node *ptr = graf[u]; ptr; ptr = ptr->next){
            if(!zbiorS[ptr->v] && (dist[ptr->v] > dist[u] + ptr->w)){
                dist[ptr->v] = dist[u] + ptr->w;
                p[ptr->v] = u;
            }
        }
    }

    int *Stack = new int [n];
    int stack_size = 0;
    for(int i=0; i<n; i++)
    {
        cout<<i <<": ";
        for(int j = i; j > -1; j = p[j])
            Stack[stack_size++] = j;
        while (stack_size)
            cout<<Stack[--stack_size] <<" ";
        cout <<" ,dist: " <<dist[i]<<endl;
    }
}
int main()
{
    int n, m, start;
    cin >>start>>n >>m;
    node **graf = initGraf(n, m);
    //int **macierz = initMacierz(n, m);
    dijkstra(graf, n, start);
    return 0;
}
