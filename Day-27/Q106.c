#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee
{
    int id;
    char name[50];
    char department[30];
    float salary;
};

int findEmployee(struct Employee employees[], int count, int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (employees[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

void addEmployee(struct Employee employees[], int *count)
{
    int id;

    if (*count >= MAX_EMPLOYEES)
    {
        printf("Record limit reached. Cannot add more employees.\n");
        return;
    }

    printf("Enter employee ID: ");
    scanf("%d", &id);

    if (findEmployee(employees, *count, id) != -1)
    {
        printf("Employee with this ID already exists.\n");
        return;
    }

    employees[*count].id = id;

    printf("Enter name: ");
    scanf(" %[^\n]", employees[*count].name);

    printf("Enter department: ");
    scanf(" %[^\n]", employees[*count].department);

    printf("Enter salary: ");
    scanf("%f", &employees[*count].salary);

    (*count)++;
    printf("Employee record added successfully.\n");
}

void displayEmployees(struct Employee employees[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No employee records found.\n");
        return;
    }

    printf("\n%-12s %-25s %-20s %-12s\n", "Emp ID", "Name", "Department", "Salary");
    printf("-----------------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-12d %-25s %-20s %-12.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }
}

void searchEmployee(struct Employee employees[], int count)
{
    int id, index;

    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    index = findEmployee(employees, count, id);

    if (index == -1)
    {
        printf("Employee record not found.\n");
        return;
    }

    printf("\nEmployee Record\n");
    printf("Employee ID : %d\n", employees[index].id);
    printf("Name        : %s\n", employees[index].name);
    printf("Department  : %s\n", employees[index].department);
    printf("Salary      : %.2f\n", employees[index].salary);
}

void updateEmployee(struct Employee employees[], int count)
{
    int id, index;

    printf("Enter employee ID to update: ");
    scanf("%d", &id);

    index = findEmployee(employees, count, id);

    if (index == -1)
    {
        printf("Employee record not found.\n");
        return;
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", employees[index].name);

    printf("Enter new department: ");
    scanf(" %[^\n]", employees[index].department);

    printf("Enter new salary: ");
    scanf("%f", &employees[index].salary);

    printf("Employee record updated successfully.\n");
}

void deleteEmployee(struct Employee employees[], int *count)
{
    int id, index, i;

    printf("Enter employee ID to delete: ");
    scanf("%d", &id);

    index = findEmployee(employees, *count, id);

    if (index == -1)
    {
        printf("Employee record not found.\n");
        return;
    }

    for (i = index; i < *count - 1; i++)
    {
        employees[i] = employees[i + 1];
    }

    (*count)--;
    printf("Employee record deleted successfully.\n");
}

int main()
{
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0, choice;

    do
    {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Employee Record\n");
        printf("4. Update Employee Record\n");
        printf("5. Delete Employee Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee(employees, &count);
            break;
        case 2:
            displayEmployees(employees, count);
            break;
        case 3:
            searchEmployee(employees, count);
            break;
        case 4:
            updateEmployee(employees, count);
            break;
        case 5:
            deleteEmployee(employees, &count);
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
