#include <iostream>
using namespace std;
struct node{
  node* next;
  int v;
};

int n,m,cv;
node **graf;
int *D;
node *L;

node **init_graph ()
{
    int x,y;
    node **graph = new node *[n];
    for(int i=0; i<n; i++)
        graph[i] = nullptr;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        node *p = new node;
        p->v = y;
        p->next = graph[x];
        graph[x] = p;
        p = new node;
        p->v = x;
        p->next = graph[y];
        graph[y] = p;
    }
    return graph;
}

int DFSb(int v, int vf)
{
  int Low = D[v] = cv++;

  for(node *p = graf[v]; p; p = p->next){
    if(p->v != vf)
    {
      if(!D[p->v])
      {
        int temp = DFSb(p->v,v);
        if(temp < Low)
            Low = temp;
      }
      else if(D[p->v] < Low)
        Low = D[p->v];
    }
  }

  if((vf > -1) && (Low == D[v]))
  {
    node *p = new node;
    p->v = v;
    p->next = L;
    L = p;
    p = new node;
    p->v = vf;
    p->next = L;
    L = p;
  }
  return Low;
}

void mosty ()
{
    D = new int[n];
    L = nullptr;
    for(int i = 0; i < n; i++)
        D[i] = 0;

    for(int i = 0; i < n; i++){
        if(!D[i]){
            cv = 1;
            DFSb(i,-1);
        }
    }
    cout<<endl;
    int v = 0;
    while(L)
    {
        cout << L->v << " ";
        v ^= 1;
        if(!v)
            cout << endl;
        L = L->next;
    }
}
int main()
{
    cin >> n >> m;
    graf = init_graph();
    mosty();
    return 0;
}
