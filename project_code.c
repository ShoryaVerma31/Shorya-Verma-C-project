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

void printTicket(int pnr){
    for(int i =0; i < confirmedCount; i++){
        if(confirmed[i].pnr == pnr){
            printf("\n----------Train Ticket--------------\n");
            printf("PNR: %d\n", confirmed[i].pnr);
            printf("Name: %s\n", confirmed[i].name);
            printf("Status: CONFIRMED\n");
            printf("\n------------------------------------\n");
            return;
        }
    }
    for(int i =0; i < waitingCount; i++){
        if(waiting[i].pnr == pnr){
            printf("\n----------Train Ticket--------------\n");
            printf("PNR: %d\n", waiting[i].pnr);
            printf("Name: %s\n", waiting[i].name);
            printf("Status: WAITING\n");
            printf("\n------------------------------------\n");
            return;
        }
    }
    printf("No ticket found with PNR: %d\n", pnr);

}

int main(){
    int choice, pnr;
    char name[60];

    while(1){
        printf("\n--------Train ticket Reservation System-----------\n");
        printf("1. Check Seat Availability\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Print Ticket\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1 : 
                printf("Seat Available: %d\n", seatsAvailable());
                break;
            case 2 : 
                printf("Enter Passenger Name: "); 
                scanf("%s", name);
                bookTicket(name);
                break;
            case 3 :
                printf("Enter PNR to cancel: "); 
                scanf("%d", &pnr);
                cancelTicket(pnr);
                break;
            
            case 4 : 
                printf("Enter PNR to print: "); 
                scanf("%d", &pnr);
                printTicket(pnr);
                break;
            case 5 : 
                printf("Exiting...!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
                   
        }
    }
    return 0;
}


    



