#include <iostream>
using namespace std;
const int n = 5, m = 8;

bool **A = new bool * [n];
int **W = new int * [n];
bool *visited = new bool [n];

int *S = new int [n];
int *Sh = new int [n];
int sptr = 0, shptr = 0;

int d  = INT_MAX, dh = 0, v0 = 0;

void TSP(int v)
{
  Sh[shptr++] = v;

  if(shptr < n)
  {
    visited[v] = true;
    for(int i = 0; i < n; i++)
      if(A[v][i] && visited[i] == false)
      {
        dh += W[v][i];
        TSP(i);
        dh -= W[v][i];
      }
    visited[v] = false;
  }

  else if(A[v0][v])
  {
    dh += W[v][v0];
    if(dh < d)
    {
      d = dh;
      for(int i = 0; i < shptr; i++)
        S[i] = Sh[i];
      sptr = shptr;
    }
    dh -= W[v][v0];
  }

  shptr--;
}

int main()
{
  int x,y,z;

  for(int i = 0; i < n; i++)
  {
    A[i] = new bool [n];
    W[i] = new int [n];
    for(int j = 0; j < n; j++)
    {
      A[i][j] = false;
      W[i][j] = 0;
    }
    visited[i] = false;
  }

  for(int i = 0; i < m; i++)
  {
    cin >> x >> y >> z;
    A[x][y] = A[y][x] = true;
    W[x][y] = W[y][x] = z;
  }

  TSP(v0);
  if(sptr)
  {
    for(int i = 0; i < sptr; i++)
        cout << S[i] << " ";
    cout << v0 << endl;
    cout << "d = " << d << endl;
  }
  else cout << "NO HAMILTONIAN CYCLE" << endl;

  return 0;
}
