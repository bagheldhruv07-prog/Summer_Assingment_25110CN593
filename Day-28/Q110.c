#include <stdio.h>

#define MAX_ACCOUNTS 100

struct BankAccount
{
    int accountNumber;
    char name[50];
    char accountType[20];
    float balance;
};

int findAccount(struct BankAccount accounts[], int count, int accountNumber)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            return i;
        }
    }

    return -1;
}

void createAccount(struct BankAccount accounts[], int *count)
{
    int accountNumber;

    if (*count >= MAX_ACCOUNTS)
    {
        printf("\nBank account storage is full.\n");
        return;
    }

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    if (findAccount(accounts, *count, accountNumber) != -1)
    {
        printf("\nAccount number already exists.\n");
        return;
    }

    accounts[*count].accountNumber = accountNumber;

    printf("Enter account holder name: ");
    scanf(" %[^\n]", accounts[*count].name);

    printf("Enter account type (Saving/Current): ");
    scanf(" %[^\n]", accounts[*count].accountType);

    printf("Enter opening balance: ");
    scanf("%f", &accounts[*count].balance);

    if (accounts[*count].balance < 0)
    {
        printf("\nOpening balance cannot be negative.\n");
        return;
    }

    (*count)++;
    printf("\nAccount created successfully.\n");
}

void displayAccounts(struct BankAccount accounts[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo accounts available.\n");
        return;
    }

    printf("\n======================== ACCOUNT LIST ========================\n");
    printf("%-15s %-25s %-15s %-12s\n", "Account No.", "Name", "Type", "Balance");
    printf("--------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-15d %-25s %-15s %-12.2f\n",
               accounts[i].accountNumber,
               accounts[i].name,
               accounts[i].accountType,
               accounts[i].balance);
    }

    printf("==============================================================\n");
}

void searchAccount(struct BankAccount accounts[], int count)
{
    int accountNumber, index;

    printf("\nEnter account number to search: ");
    scanf("%d", &accountNumber);

    index = findAccount(accounts, count, accountNumber);

    if (index == -1)
    {
        printf("\nAccount not found.\n");
    }
    else
    {
        printf("\nAccount Found\n");
        printf("Account Number : %d\n", accounts[index].accountNumber);
        printf("Holder Name    : %s\n", accounts[index].name);
        printf("Account Type   : %s\n", accounts[index].accountType);
        printf("Balance        : %.2f\n", accounts[index].balance);
    }
}

void depositMoney(struct BankAccount accounts[], int count)
{
    int accountNumber, index;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    index = findAccount(accounts, count, accountNumber);

    if (index == -1)
    {
        printf("\nAccount not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("\nDeposit amount must be greater than zero.\n");
        return;
    }

    accounts[index].balance += amount;
    printf("\nAmount deposited successfully.\n");
    printf("Updated Balance: %.2f\n", accounts[index].balance);
}

void withdrawMoney(struct BankAccount accounts[], int count)
{
    int accountNumber, index;
    float amount;

    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);

    index = findAccount(accounts, count, accountNumber);

    if (index == -1)
    {
        printf("\nAccount not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("\nWithdrawal amount must be greater than zero.\n");
    }
    else if (amount > accounts[index].balance)
    {
        printf("\nInsufficient balance.\n");
    }
    else
    {
        accounts[index].balance -= amount;
        printf("\nAmount withdrawn successfully.\n");
        printf("Updated Balance: %.2f\n", accounts[index].balance);
    }
}

int main()
{
    struct BankAccount accounts[MAX_ACCOUNTS];
    int count = 0;
    int choice;

    do
    {
        printf("\n============ BANK ACCOUNT SYSTEM ============\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount(accounts, &count);
            break;

        case 2:
            displayAccounts(accounts, count);
            break;

        case 3:
            searchAccount(accounts, count);
            break;

        case 4:
            depositMoney(accounts, count);
            break;

        case 5:
            withdrawMoney(accounts, count);
            break;

        case 6:
            printf("\nThank you for using the Bank Account System.\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
