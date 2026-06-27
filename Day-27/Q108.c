#include <stdio.h>

#define SUBJECTS 5

struct Student
{
    int rollNo;
    char name[50];
    char subjects[SUBJECTS][30];
    float marks[SUBJECTS];
    float total;
    float percentage;
    char grade;
};

char calculateGrade(float percentage)
{
    if (percentage >= 90)
    {
        return 'A';
    }
    else if (percentage >= 75)
    {
        return 'B';
    }
    else if (percentage >= 60)
    {
        return 'C';
    }
    else if (percentage >= 40)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

int isPassed(float marks[])
{
    int i;

    for (i = 0; i < SUBJECTS; i++)
    {
        if (marks[i] < 33)
        {
            return 0;
        }
    }

    return 1;
}

void inputStudentDetails(struct Student *student)
{
    int i;

    printf("Enter roll number: ");
    scanf("%d", &student->rollNo);

    printf("Enter student name: ");
    scanf(" %[^\n]", student->name);

    for (i = 0; i < SUBJECTS; i++)
    {
        printf("Enter subject %d name: ", i + 1);
        scanf(" %[^\n]", student->subjects[i]);

        printf("Enter marks for %s: ", student->subjects[i]);
        scanf("%f", &student->marks[i]);
    }
}

void calculateMarksheet(struct Student *student)
{
    int i;

    student->total = 0;

    for (i = 0; i < SUBJECTS; i++)
    {
        student->total += student->marks[i];
    }

    student->percentage = student->total / SUBJECTS;
    student->grade = calculateGrade(student->percentage);
}

void displayMarksheet(struct Student student)
{
    int i;

    printf("\n================ MARKSHEET ================\n");
    printf("Roll Number : %d\n", student.rollNo);
    printf("Name        : %s\n", student.name);
    printf("-------------------------------------------\n");
    printf("%-25s %-10s\n", "Subject", "Marks");
    printf("-------------------------------------------\n");

    for (i = 0; i < SUBJECTS; i++)
    {
        printf("%-25s %-10.2f\n", student.subjects[i], student.marks[i]);
    }

    printf("-------------------------------------------\n");
    printf("Total Marks : %.2f / %.0f\n", student.total, (float)SUBJECTS * 100);
    printf("Percentage  : %.2f%%\n", student.percentage);
    printf("Grade       : %c\n", student.grade);

    if (isPassed(student.marks))
    {
        printf("Result      : Pass\n");
    }
    else
    {
        printf("Result      : Fail\n");
    }

    printf("===========================================\n");
}

int main()
{
    struct Student student;

    printf("Marksheet Generation System\n\n");

    inputStudentDetails(&student);
    calculateMarksheet(&student);
    displayMarksheet(student);

    return 0;
}
