// by Jan "Regzand" Golda

#include <stdio.h>
#include <algorithm>

using namespace std;

int goodThief(int  *A, int N){

    // tablica podzadan
    int sum[N+2];

    // tablica flag czy przedmiot zostal ukradziony
    bool stolen[N+2];

    // wartownicy
    sum[0] = 0;
    sum[1] = 0;

    // wyliczenie wartosci
    for(int i = 2; i<N+2; i++){

        // najlepsza wartosc
        sum[i] = max(A[i-2] + sum[i-2], sum[i-1]);

        // czy dany element zostal ukradziony
        stolen[i] = ( A[i-2] + sum[i-2] > sum[i-1] );
    }

    // wypisanie ukradzionych przedmiotow
    for(int i = N+1; i>=2; i--){
        if(stolen[i]){
            printf("%d ", i-2);
            i--;
        }
    }
    printf("\n");

    // zwrocenie wartosci
    return sum[N+1];
}

int main(){

    // iosc przedmiotow
    int N;
    scanf("%d", &N);

    // wczytanie przedmiotow
    int A[N];
    for(int i = 0; i<N; i++)
        scanf("%d", &A[i]);

    // wypisanie wyniku
    printf("Maksymalna suma przedmiotow: %d\n", goodThief(A, N));

    return 0;
}
