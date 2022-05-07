#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAR 40

typedef struct giocatore{
    char colore;
    int num;
    int pos;
}giocatore;

typedef struct casella{
    int num;
    int type;
    int val;
    char dom[MAX_CHAR];
    char risp[MAX_CHAR];
}casella;

int main() {
    giocatore *testa=NULL, *coda=NULL;
    casella table[62];
    genera_partita(testa, coda, table);
    gioca_partita(testa, coda, table);
    return 1;

}
