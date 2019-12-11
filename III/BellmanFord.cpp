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
void Bellman_Ford (node **graf, int n, int start)
{
    int *dist = new int[n];
    int *parent = new int[n];
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX/2;
        parent[i] = -1;
    }

    dist[start] = 0;
    for(int i=1; i<n; i++)
        for(int x=0; x<n; x++)
            for(node *p = graf[x]; p; p=p->next)
                if(dist[p->v] > dist[x] + p->w){
                    dist[p->v] = dist[x] + p->w;
                    parent[p->v] = x;
                }
    for(int x=0; x<n; x++)
        for(node *p = graf[x]; p; p=p->next)
            if(dist[p->v] > dist[x] + p->w){
                cout<<"ujemny cykl";
                return;
            }
    int *S = new int[n];
    int size_s = 0;
    for(int i=0; i<n; i++){
        cout<<i <<": ";
        for(int x = i; x != -1; x = parent[x]){
            S[size_s++] = x;
            cout<<x<<" ";}
        while(size_s)
            cout<<S[--size_s] <<" ";
        cout<<" , dist: "<<dist[i]<<endl;
    }
}
int main ()
{
    int n, m, start;
    cin >>start>>n >>m;
    node **graph = init_graph(n, m);
    Bellman_Ford(graph, n, start);
    return 0;
}
