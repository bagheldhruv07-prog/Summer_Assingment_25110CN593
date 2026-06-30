#include <stdio.h>

int roll[100], n;
char name[100][50];
float marks[100];

// Function to add student records
void addStudents()
{
    int i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &roll[i]);

        printf("Enter Name: ");
        scanf("%s", name[i]);

        printf("Enter Marks: ");
        scanf("%f", &marks[i]);
    }
}

// Function to display student records
void displayStudents()
{
    int i;

    if(n == 0)
    {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n===== Student Records =====\n");
    printf("Roll No\tName\tMarks\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%s\t%.2f\n", roll[i], name[i], marks[i]);
    }
}

// Function to search a student by roll number
void searchStudent()
{
    int i, searchRoll;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &searchRoll);

    for(i = 0; i < n; i++)
    {
        if(roll[i] == searchRoll)
        {
            printf("\nStudent Found!\n");
            printf("Roll No : %d\n", roll[i]);
            printf("Name    : %s\n", name[i]);
            printf("Marks   : %.2f\n", marks[i]);
            return;
        }
    }

    printf("Student not found!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Students\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudents();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}