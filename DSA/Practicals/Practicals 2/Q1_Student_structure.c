// 1. Create a structure Student in C with student name, student roll number and student 
//    address as its data members. Create the variable of type student and print the values.

#include <stdio.h>
#include <conio.h>

struct Student
{
    char name[50];
    int rollno;
    char address[100];
};

int main()
{
    struct Student student;

    printf("Enter the name of student: ");
    scanf("%49[^\n]", student.name);                // Read up to 49 characters until a newline

    printf("Enter Roll Number: ");
    scanf("%d", &student.rollno);

    while (getchar() != '\n');                      // clear the input buffer
        

    printf("Enter Address: ");
    scanf("%99[^\n]", student.address);             // Read up to 99 characters until a newline

    printf("\n\n\n");
    printf("Displaying student data: \n\n");

    printf("Student Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollno);
    printf("Address: %s\n", student.address);

    return 0;
}