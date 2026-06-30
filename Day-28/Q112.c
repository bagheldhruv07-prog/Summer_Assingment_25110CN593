#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact
{
    int id;
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
};

int findContactById(struct Contact contacts[], int count, int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (contacts[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

void addContact(struct Contact contacts[], int *count)
{
    int id;

    if (*count >= MAX_CONTACTS)
    {
        printf("\nContact list is full. Cannot add more contacts.\n");
        return;
    }

    printf("\nEnter contact ID: ");
    scanf("%d", &id);

    if (findContactById(contacts, *count, id) != -1)
    {
        printf("\nContact ID already exists.\n");
        return;
    }

    contacts[*count].id = id;

    printf("Enter name: ");
    scanf(" %[^\n]", contacts[*count].name);

    printf("Enter phone number: ");
    scanf(" %[^\n]", contacts[*count].phone);

    printf("Enter email: ");
    scanf(" %[^\n]", contacts[*count].email);

    printf("Enter address: ");
    scanf(" %[^\n]", contacts[*count].address);

    (*count)++;
    printf("\nContact added successfully.\n");
}

void displayContacts(struct Contact contacts[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo contacts available.\n");
        return;
    }

    printf("\n======================================== CONTACT LIST ========================================\n");
    printf("%-8s %-20s %-15s %-25s %-25s\n", "ID", "Name", "Phone", "Email", "Address");
    printf("----------------------------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-8d %-20s %-15s %-25s %-25s\n",
               contacts[i].id,
               contacts[i].name,
               contacts[i].phone,
               contacts[i].email,
               contacts[i].address);
    }

    printf("==============================================================================================\n");
}

void searchContact(struct Contact contacts[], int count)
{
    int id, index;

    printf("\nEnter contact ID to search: ");
    scanf("%d", &id);

    index = findContactById(contacts, count, id);

    if (index == -1)
    {
        printf("\nContact not found.\n");
    }
    else
    {
        printf("\nContact Found\n");
        printf("ID      : %d\n", contacts[index].id);
        printf("Name    : %s\n", contacts[index].name);
        printf("Phone   : %s\n", contacts[index].phone);
        printf("Email   : %s\n", contacts[index].email);
        printf("Address : %s\n", contacts[index].address);
    }
}

void updateContact(struct Contact contacts[], int count)
{
    int id, index;

    printf("\nEnter contact ID to update: ");
    scanf("%d", &id);

    index = findContactById(contacts, count, id);

    if (index == -1)
    {
        printf("\nContact not found.\n");
        return;
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", contacts[index].name);

    printf("Enter new phone number: ");
    scanf(" %[^\n]", contacts[index].phone);

    printf("Enter new email: ");
    scanf(" %[^\n]", contacts[index].email);

    printf("Enter new address: ");
    scanf(" %[^\n]", contacts[index].address);

    printf("\nContact updated successfully.\n");
}

void deleteContact(struct Contact contacts[], int *count)
{
    int id, index, i;

    printf("\nEnter contact ID to delete: ");
    scanf("%d", &id);

    index = findContactById(contacts, *count, id);

    if (index == -1)
    {
        printf("\nContact not found.\n");
        return;
    }

    for (i = index; i < *count - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }

    (*count)--;
    printf("\nContact deleted successfully.\n");
}

int main()
{
    struct Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n============ CONTACT MANAGEMENT SYSTEM ============\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact(contacts, &count);
            break;

        case 2:
            displayContacts(contacts, count);
            break;

        case 3:
            searchContact(contacts, count);
            break;

        case 4:
            updateContact(contacts, count);
            break;

        case 5:
            deleteContact(contacts, &count);
            break;

        case 6:
            printf("\nThank you for using the Contact Management System.\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
