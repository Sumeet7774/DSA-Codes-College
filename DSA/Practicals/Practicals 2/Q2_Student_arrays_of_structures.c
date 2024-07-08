// 1. Create a structure Student in C with student name, student roll number and student 
// address as its data members. Create the variable of type student and print the values.
// 2. Modify the above program to implement arrays of structure. Create an array of 5 
// students and print their values



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

   printf("Enter student name: ");
   scanf("%s", student.name);

   printf("Enter student roll number: ");
   scanf("%d", &student.rollno);

   printf("Enter student address: ");
   scanf("%s", student.address);

   printf("\nStudent Details:\n");
   printf("Name: %s\n", student.name);
   printf("Roll Number: %d\n", student.rollno);
   printf("Address: %s\n", student.address);

   struct Student studentArray[5];

   for (int i = 0; i < 5; i++)
   {
      printf("Enter the details of student %d: \n", i + 1);
      printf("Name: ");
      scanf("%s", studentArray[i].name);

      printf("Roll Number: ");
      scanf("%d", &studentArray[i].rollno);

      printf("Address: ");
      scanf("%s", studentArray[i].address);
   }

   printf("\nStudent Details (Array):\n");
   for (int i = 0; i < 5; i++)
   {
      printf("\nStudent %d:\n", i + 1);
      printf("Name: %s\n", studentArray[i].name);
      printf("Roll Number: %d\n", studentArray[i].rollno);
      printf("Address: %s\n", studentArray[i].address);

   }

   return 0;

}