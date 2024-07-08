// 1. Create a structure Student in C with student name, student roll number and student 
// address as its data members. Create the variable of type student and print the values.
// 2. Modify the above program to implement arrays of structure. Create an array of 5 
// students and print their values

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    string studentName;
    int studentRollno;
    string studentAddress;

    void input_student_data()
    {
        cin.ignore(); 

        cout << "Enter the name of student: ";
        getline(cin, studentName);

        cout << "Enter the rollno of student: ";
        cin >> studentRollno;
        cin.ignore(); 

        cout << "Enter the address of student: ";
        getline(cin, studentAddress);
    }

    void display_student_data()
    {
        cout << endl;
        cout << "Student name: " << studentName << endl;
        cout << "Student rollno: " << studentRollno << endl;
        cout << "Student address: " << studentAddress << endl << endl;
    }
};

int main()
{
    Student student_data[5]; 

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter information for student " << i + 1 << ":" << endl;
        student_data[i].input_student_data();
    }

    cout << "Student Information for all students:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        student_data[i].display_student_data();
    }

    return 0;
}
