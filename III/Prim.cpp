#include <iostream>
using namespace std;
struct node{
    node *next;
    int v, w;
};
struct edge{
    int v1, v2, w;
};
struct queue {
    edge *heap;
    int h;
};
void insertEdge (node **graph, int x, int y, int w)
{
    node *p = new node;
    p->w = w;
    p->v = y;
    p->next = graph[x];
    graph[x] = p;
    node *p2 = new node;
    p2->w = w;
    p2->v = x;
    p2->next = graph[y];
    graph[y] = p2;
}
node **init_graph (int n, int m)
{
    int x, y, w;
    node **graph = new node*[n];
    for(int i=0; i<n; i++)
        graph[i] = nullptr;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        insertEdge (graph, x,y,w);
    }
    return graph;
}

queue *init_Q (int m)
{
    queue *Q = new queue;
    Q->heap = new edge[m];
    Q->h = 0;
    return Q;
}
edge front_Q (queue *Q)
{
    return Q->heap[0];
}
void push_Q (queue *&Q, edge e)
{
    int i = Q->h++;
    int j = (i-1) >> 1;
    while(i && (Q->heap[j].w > e.w))
    {
        Q->heap[i] = Q->heap[j];
        i = j;
        j = (i-1) >> 1;
    }
    Q->heap[i] = e;
}
void pop_Q (queue *Q)
{
    if(Q->h)
    {
        edge e = Q->heap[--(Q->h)];
        int i = 0;
        int j = 1;
        while(j < Q->h)
        {
            if((j + 1 < Q->h) && (Q->heap[j + 1].w < Q->heap[j].w))
                j++;
            if(e.w <= Q->heap[j].w)
                break;
            Q->heap[i] = Q->heap[j];
            i = j;
            j = (j << 1) + 1;
        }
        Q->heap[i] = e;
    }
}

node **init_tree (int n)
{
    node **tree = new node*[n];
    for(int i=0; i<n; i++)
        tree[i] = nullptr;
    return tree;
}
void print_tree (node **tree, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<i<<": ";
        for(node *ptr = tree[i]; ptr; ptr=ptr->next)
            cout<<ptr->v <<"(w:"<<ptr->w<<") ";
        cout<<endl;
    }
}
void Prim (node **graph, int n, int m)
{
    queue *Q = init_Q(m);
    int weight = 0;
    node **tree = init_tree(n);
    bool *visited = new bool [n];
    for(int i=0; i<n; i++)
        visited[i] = false;

    int v = 0;
    visited[v] = true;
    for(int i =1; i<n; i++)
    {
        edge e;
        for(node *ptr = graph[v]; ptr; ptr=ptr->next){
            if(!visited[ptr->v])
            {
                e.v1 = v;
                e.v2 = ptr->v;
                e.w = ptr->w;
                push_Q(Q, e);
            }
        }
        while (1)
        {
            e = front_Q(Q);
            pop_Q(Q);
            if(!visited[e.v2])
                break;
        }
        insertEdge(tree, e.v1, e.v2, e.w);
        weight+=e.w;
        visited[e.v2] = true;
        v = e.v2;
    }

    print_tree (tree, n);
    cout<<endl<<weight;
}
int main()
{
    int n, m;
    cin >>n>>m;
    node **graph = init_graph(n, m);
    Prim(graph, n, m);
    return 0;
}
