#include <iostream>
#define N 20
using namespace std;
int zalanyPoziom (int p[N][N], int A)
{
    int sum=0;
    for(int i=N-1; i>=0; i--){
        for(int j=0; j<N; j++){
            A-=p[i][j];
            if(A == 0){
                while(j!=N-1){
                    j++;
                    sum+=p[i][j];
                }
                if ( sum == 0 )
                    return N-1-i;
                else
                    return N-2-i;
            }
        }
    }
    return N-1;
}
void wpisz(int p[N][N], int poj[4], int poziom[N])
{
    poziom[poj[1]-1]++;
    poj[1]=N-1-poj[1];
    poj[3]=N-1-poj[3];
    for(int i=poj[1]+1; i<=poj[3]; i++)
        for(int j=poj[0]; j<poj[2]; j++)
            p[i][j]++;
}
void ileZalanych(int p[N][N], int A, int poziom[N])
{
    int ile=0;
    for(int i=0; i<=zalanyPoziom(p, A); i++)
        ile+=poziom[i];
    cout<<"Zalanych pojemnikow: "<<ile;
}
int main ()
{
    int p[N][N], n, A, poziom[N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            p[i][j]=0;
            poziom[i]=0;
        }
    cout <<"ile pojemnikow?\n";
    cin >>n;
    for(int i=0; i<n; i++)
    {
        cout<<"podaj wymiary pojemnika: ";
        int poj[4];
        for(int j=0; j<4; j++)
            cin>>poj[j];
        wpisz(p, poj, poziom);
    }
    cout<<"ile wody?\n";
    cin>>A;
    ileZalanych(p, A, poziom);
    return 0;
}
