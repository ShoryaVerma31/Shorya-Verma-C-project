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
int confirmedCount = 0, waitingCount = 0;
int next_pnr = 1001;

int gentrate_PNR(){
    return next_pnr++;
}

int seatsAvailable() {
    return MAX_SEATS - confirmedCount;
}

void Book_Tickect(char name[]){
    Passenger p;
    p.pnr = genrate_PNR();
    strcpy(p.name, name);

     if(confirmedCount < MAX_SEATS) {
        p.status = CONFIRMED;
        confirmed[confirmedCount++] = p;
        printf("Ticket Booked Successfully!\n");
    } 
    else if(waitingCount < MAX_WAITING) {
        p.status = WAITING;
        waiting[waitingCount++] = p;
        printf("Train Full .Added to waiting list.\n");
    } 
    else{
        printf("Sorry! No seat and waiting list also full.\n");
        return;
    }
    printf("Your PNR: %d\n", p.pnr);
}


    

