#include <iostream>
using namespace std;
const int n = 5, m = 4;
struct queue
{
    int v;
    queue *next;
};
void put_queue (queue *&Q, int v)
{
    queue *nowy = new queue;
    nowy->v = v;
    nowy->next = Q;
    Q = nowy;
}
int pop_queue (queue *&Q)
{
    if (Q == nullptr)
        return -1;
    if(Q->next == nullptr)
    {
        int res = Q->v;
        Q = nullptr;
        return res;
    }
    queue *ptr = Q;
    while (ptr->next->next != nullptr)
        ptr=ptr->next;
    int res = ptr->next->v;
    delete ptr->next;
    ptr->next = nullptr;
    return res;
}
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
void BFS (bool **macierz, int v)
{
    queue *Q = nullptr;
    bool *visited = initVisited();
    visited[v] = true;
    put_queue(Q, v);
    while (Q != nullptr)
    {
        int x = pop_queue(Q);
        cout<<x<<" ";
        for(int i =0; i<n; i++)
        {
            if(macierz[x][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                put_queue(Q, i);
            }
        }
    }
}
int main()
{
    bool **macierz = initMacierz();
    printMacierz(macierz);
    BFS(macierz, 0);
}

