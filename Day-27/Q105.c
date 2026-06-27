#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    int rollNo;
    char name[50];
    char course[30];
    float marks;
};

int findStudent(struct Student students[], int count, int rollNo)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (students[i].rollNo == rollNo)
        {
            return i;
        }
    }

    return -1;
}

void addStudent(struct Student students[], int *count)
{
    int rollNo;

    if (*count >= MAX_STUDENTS)
    {
        printf("Record limit reached. Cannot add more students.\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &rollNo);

    if (findStudent(students, *count, rollNo) != -1)
    {
        printf("Student with this roll number already exists.\n");
        return;
    }

    students[*count].rollNo = rollNo;

    printf("Enter name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter course: ");
    scanf(" %[^\n]", students[*count].course);

    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;
    printf("Student record added successfully.\n");
}

void displayStudents(struct Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No student records found.\n");
        return;
    }

    printf("\n%-10s %-25s %-20s %-10s\n", "Roll No", "Name", "Course", "Marks");
    printf("-------------------------------------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("%-10d %-25s %-20s %-10.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].course,
               students[i].marks);
    }
}

void searchStudent(struct Student students[], int count)
{
    int rollNo, index;

    printf("Enter roll number to search: ");
    scanf("%d", &rollNo);

    index = findStudent(students, count, rollNo);

    if (index == -1)
    {
        printf("Student record not found.\n");
        return;
    }

    printf("\nStudent Record\n");
    printf("Roll Number: %d\n", students[index].rollNo);
    printf("Name       : %s\n", students[index].name);
    printf("Course     : %s\n", students[index].course);
    printf("Marks      : %.2f\n", students[index].marks);
}

void updateStudent(struct Student students[], int count)
{
    int rollNo, index;

    printf("Enter roll number to update: ");
    scanf("%d", &rollNo);

    index = findStudent(students, count, rollNo);

    if (index == -1)
    {
        printf("Student record not found.\n");
        return;
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", students[index].name);

    printf("Enter new course: ");
    scanf(" %[^\n]", students[index].course);

    printf("Enter new marks: ");
    scanf("%f", &students[index].marks);

    printf("Student record updated successfully.\n");
}

void deleteStudent(struct Student students[], int *count)
{
    int rollNo, index, i;

    printf("Enter roll number to delete: ");
    scanf("%d", &rollNo);

    index = findStudent(students, *count, rollNo);

    if (index == -1)
    {
        printf("Student record not found.\n");
        return;
    }

    for (i = index; i < *count - 1; i++)
    {
        students[i] = students[i + 1];
    }

    (*count)--;
    printf("Student record deleted successfully.\n");
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0, choice;

    do
    {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student Record\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(students, &count);
            break;
        case 2:
            displayStudents(students, count);
            break;
        case 3:
            searchStudent(students, count);
            break;
        case 4:
            updateStudent(students, count);
            break;
        case 5:
            deleteStudent(students, &count);
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
