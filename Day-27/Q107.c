#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

struct Salary
{
    int empId;
    char name[50];
    float basicSalary;
    float allowance;
    float deduction;
    float netSalary;
};

float calculateNetSalary(float basicSalary, float allowance, float deduction)
{
    return basicSalary + allowance - deduction;
}

int findSalaryRecord(struct Salary records[], int count, int empId)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (records[i].empId == empId)
        {
            return i;
        }
    }

    return -1;
}

void addSalaryRecord(struct Salary records[], int *count)
{
    int empId;

    if (*count >= MAX_RECORDS)
    {
        printf("Record limit reached. Cannot add more salary records.\n");
        return;
    }

    printf("Enter employee ID: ");
    scanf("%d", &empId);

    if (findSalaryRecord(records, *count, empId) != -1)
    {
        printf("Salary record with this employee ID already exists.\n");
        return;
    }

    records[*count].empId = empId;

    printf("Enter employee name: ");
    scanf(" %[^\n]", records[*count].name);

    printf("Enter basic salary: ");
    scanf("%f", &records[*count].basicSalary);

    printf("Enter allowance: ");
    scanf("%f", &records[*count].allowance);

    printf("Enter deduction: ");
    scanf("%f", &records[*count].deduction);

    records[*count].netSalary = calculateNetSalary(records[*count].basicSalary,
                                                   records[*count].allowance,
                                                   records[*count].deduction);

    (*count)++;
    printf("Salary record added successfully.\n");
}

void displaySalaryRecords(struct Salary records[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No salary records found.\n");
        return;
    }

    printf("\n%-10s %-22s %-14s %-12s %-12s %-12s\n",
           "Emp ID", "Name", "Basic Salary", "Allowance", "Deduction", "Net Salary");
    printf("------------------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-10d %-22s %-14.2f %-12.2f %-12.2f %-12.2f\n",
               records[i].empId,
               records[i].name,
               records[i].basicSalary,
               records[i].allowance,
               records[i].deduction,
               records[i].netSalary);
    }
}

void searchSalaryRecord(struct Salary records[], int count)
{
    int empId, index;

    printf("Enter employee ID to search: ");
    scanf("%d", &empId);

    index = findSalaryRecord(records, count, empId);

    if (index == -1)
    {
        printf("Salary record not found.\n");
        return;
    }

    printf("\nSalary Record\n");
    printf("Employee ID  : %d\n", records[index].empId);
    printf("Name         : %s\n", records[index].name);
    printf("Basic Salary : %.2f\n", records[index].basicSalary);
    printf("Allowance    : %.2f\n", records[index].allowance);
    printf("Deduction    : %.2f\n", records[index].deduction);
    printf("Net Salary   : %.2f\n", records[index].netSalary);
}

void updateSalaryRecord(struct Salary records[], int count)
{
    int empId, index;

    printf("Enter employee ID to update: ");
    scanf("%d", &empId);

    index = findSalaryRecord(records, count, empId);

    if (index == -1)
    {
        printf("Salary record not found.\n");
        return;
    }

    printf("Enter new employee name: ");
    scanf(" %[^\n]", records[index].name);

    printf("Enter new basic salary: ");
    scanf("%f", &records[index].basicSalary);

    printf("Enter new allowance: ");
    scanf("%f", &records[index].allowance);

    printf("Enter new deduction: ");
    scanf("%f", &records[index].deduction);

    records[index].netSalary = calculateNetSalary(records[index].basicSalary,
                                                  records[index].allowance,
                                                  records[index].deduction);

    printf("Salary record updated successfully.\n");
}

void deleteSalaryRecord(struct Salary records[], int *count)
{
    int empId, index, i;

    printf("Enter employee ID to delete: ");
    scanf("%d", &empId);

    index = findSalaryRecord(records, *count, empId);

    if (index == -1)
    {
        printf("Salary record not found.\n");
        return;
    }

    for (i = index; i < *count - 1; i++)
    {
        records[i] = records[i + 1];
    }

    (*count)--;
    printf("Salary record deleted successfully.\n");
}

int main()
{
    struct Salary records[MAX_RECORDS];
    int count = 0, choice;

    do
    {
        printf("\nSalary Management System\n");
        printf("1. Add Salary Record\n");
        printf("2. Display All Salary Records\n");
        printf("3. Search Salary Record\n");
        printf("4. Update Salary Record\n");
        printf("5. Delete Salary Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addSalaryRecord(records, &count);
            break;
        case 2:
            displaySalaryRecords(records, count);
            break;
        case 3:
            searchSalaryRecord(records, count);
            break;
        case 4:
            updateSalaryRecord(records, count);
            break;
        case 5:
            deleteSalaryRecord(records, &count);
            break;
        case 6:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
