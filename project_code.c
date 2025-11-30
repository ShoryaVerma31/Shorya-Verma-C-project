#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 5       // maximum avaliable seats for confirmation
#define MAX_WAITING 3     // maximum number of seats for waiting list

// status either confirmed or waiting for each passenger
enum Status { CONFIRMED, WAITING }; 

// to store passenger details we use  -> structure
typedef struct {
    int pnr;
    char name[50];
    enum Status status;
} Passenger;

Passenger confirmed[MAX_SEATS];   // array which stores confirmed passengers 
Passenger waiting[MAX_WAITING];   // array which stores waiting passengers 

// counters to check how many seats are filled
int confirmedCount = 0;
int waitingCount = 0;

int next_pnr = 1001;  // variable to genrate pnr

// function for genrating unique PNR for each passenger
int gentrate_PNR(){
    return next_pnr++;
}

// function for checking  availability of seats
int seatsAvailable() {
    return MAX_SEATS - confirmedCount;
}

//function to book the tickets
void Book_Tickect(char name[]){
    Passenger p;
    p.pnr = genrate_PNR();
    strcpy(p.name, name);

     if(confirmedCount < MAX_SEATS){
        p.status = CONFIRMED;
        confirmed[confirmedCount++] = p;
        printf("Ticket Booked Successfully!\n");
    } 
    else if(waitingCount < MAX_WAITING){
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

// function for printing the the ticket 
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
    printf("No ticket found with this PNR: %d\n", pnr);

}

// function to cancel the tickets
void cancelTicket(int pnr){
    int found=0;
    for(int i =0; i< confirmedCount; i++){
        if(confirmed[i].pnr == pnr){
            found=1;
            printf("Ticket with PNR %d cancelled.\n", pnr);

            for(int j = i; j < confirmedCount - 1; j++){   // shifting remaining pasengers
                confirmed[j] = confirmed[j+1];
            }
            confirmedCount--;
            
            // shifting the paasenger from waiting list to confirmed
            if(waitingCount > 0){
                confirmed[confirmedCount++] = waiting[0];
                confirmed[confirmedCount-1].status = CONFIRMED;
            
                // shifting of waiting list
                for(int j=0; j<waitingCount -1; j++){
                waiting[j] = waiting[j+1];
                }
                waitingCount--;
                printf("Seat confirmed for the passenger from waiting list");
                
           }
           break;
       }  
    }
    if(!found){
        printf("passenger with PNR %d not found in confirmed list\n");
    }
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
                Book_Tickect(name);
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


    








