#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 5
#define MAX_WAITING 3


enum Status { CONFIRMED, WAITING };

typedef struct {
    int pnr;
    char name[50];
    enum Status status;
} Passenger;

Passenger confirmed[MAX_SEATS];
Passenger waiting[MAX_WAITING];

int gentrate_PNR(){
    return pnr++;
}

void Book_Tickect(char name[]){
    Passenger p;
    p.pnr = genrate_PNR();
    strcpy(p.name, name);
}

    
