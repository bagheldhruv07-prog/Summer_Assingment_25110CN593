#include <stdio.h>

#define MAX_TICKETS 100

struct Ticket
{
    int ticketId;
    char passengerName[50];
    char source[30];
    char destination[30];
    int seatNumber;
    float fare;
};

int findTicketById(struct Ticket tickets[], int count, int ticketId)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (tickets[i].ticketId == ticketId)
        {
            return i;
        }
    }

    return -1;
}

int isSeatBooked(struct Ticket tickets[], int count, int seatNumber)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (tickets[i].seatNumber == seatNumber)
        {
            return 1;
        }
    }

    return 0;
}

void bookTicket(struct Ticket tickets[], int *count)
{
    int ticketId, seatNumber;

    if (*count >= MAX_TICKETS)
    {
        printf("\nAll tickets are booked. No more seats available.\n");
        return;
    }

    printf("\nEnter ticket ID: ");
    scanf("%d", &ticketId);

    if (findTicketById(tickets, *count, ticketId) != -1)
    {
        printf("\nTicket ID already exists.\n");
        return;
    }

    printf("Enter passenger name: ");
    scanf(" %[^\n]", tickets[*count].passengerName);

    printf("Enter source: ");
    scanf(" %[^\n]", tickets[*count].source);

    printf("Enter destination: ");
    scanf(" %[^\n]", tickets[*count].destination);

    printf("Enter seat number: ");
    scanf("%d", &seatNumber);

    if (seatNumber <= 0)
    {
        printf("\nSeat number must be greater than zero.\n");
        return;
    }

    if (isSeatBooked(tickets, *count, seatNumber))
    {
        printf("\nThis seat is already booked.\n");
        return;
    }

    printf("Enter fare: ");
    scanf("%f", &tickets[*count].fare);

    if (tickets[*count].fare <= 0)
    {
        printf("\nFare must be greater than zero.\n");
        return;
    }

    tickets[*count].ticketId = ticketId;
    tickets[*count].seatNumber = seatNumber;

    (*count)++;
    printf("\nTicket booked successfully.\n");
}

void displayTickets(struct Ticket tickets[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo tickets booked yet.\n");
        return;
    }

    printf("\n============================= TICKET LIST =============================\n");
    printf("%-10s %-22s %-15s %-15s %-10s %-10s\n",
           "Ticket ID", "Passenger Name", "Source", "Destination", "Seat No.", "Fare");
    printf("-----------------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-10d %-22s %-15s %-15s %-10d %-10.2f\n",
               tickets[i].ticketId,
               tickets[i].passengerName,
               tickets[i].source,
               tickets[i].destination,
               tickets[i].seatNumber,
               tickets[i].fare);
    }

    printf("=======================================================================\n");
}

void searchTicket(struct Ticket tickets[], int count)
{
    int ticketId, index;

    printf("\nEnter ticket ID to search: ");
    scanf("%d", &ticketId);

    index = findTicketById(tickets, count, ticketId);

    if (index == -1)
    {
        printf("\nTicket not found.\n");
    }
    else
    {
        printf("\nTicket Found\n");
        printf("Ticket ID      : %d\n", tickets[index].ticketId);
        printf("Passenger Name : %s\n", tickets[index].passengerName);
        printf("Source         : %s\n", tickets[index].source);
        printf("Destination    : %s\n", tickets[index].destination);
        printf("Seat Number    : %d\n", tickets[index].seatNumber);
        printf("Fare           : %.2f\n", tickets[index].fare);
    }
}

void cancelTicket(struct Ticket tickets[], int *count)
{
    int ticketId, index, i;

    printf("\nEnter ticket ID to cancel: ");
    scanf("%d", &ticketId);

    index = findTicketById(tickets, *count, ticketId);

    if (index == -1)
    {
        printf("\nTicket not found.\n");
        return;
    }

    for (i = index; i < *count - 1; i++)
    {
        tickets[i] = tickets[i + 1];
    }

    (*count)--;
    printf("\nTicket cancelled successfully.\n");
}

int main()
{
    struct Ticket tickets[MAX_TICKETS];
    int count = 0;
    int choice;

    do
    {
        printf("\n============ TICKET BOOKING SYSTEM ============\n");
        printf("1. Book Ticket\n");
        printf("2. Display All Tickets\n");
        printf("3. Search Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bookTicket(tickets, &count);
            break;

        case 2:
            displayTickets(tickets, count);
            break;

        case 3:
            searchTicket(tickets, count);
            break;

        case 4:
            cancelTicket(tickets, &count);
            break;

        case 5:
            printf("\nThank you for using the Ticket Booking System.\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
