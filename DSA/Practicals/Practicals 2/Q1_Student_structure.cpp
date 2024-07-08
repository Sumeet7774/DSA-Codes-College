// 1. Create a structure Student in C with student name, student roll number and student
// address as its data members. Create the variable of type student and print the values

#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string studentName;
    int studentRollno;
    string studentAddress;

    void input_student_data()
    {
        cin.ignore();                               // after reading the int intputs we ensure that newline character is cleared from the input buffer before attempting to read the strings

        cout << "Enter the name of student: ";
        getline(cin,studentName);

        cout << "Enter the rollno of student: ";
        cin >> studentRollno;

        cin.ignore(); 

        cout << "Enter the address of student: ";
        getline(cin,studentAddress);
    }

    void display_student_data()
    {
        cout<<endl;
        cout << "Student name: " << studentName << endl;
        cout << "Student rollno: " << studentRollno << endl;
        cout << "Student address: " << studentAddress << endl <<endl;
    }
};

int main()
{
    Student student_data;

    int count = 0;

start:

    int choice;
    cout << "Enter '0' to go forward or Enter '1' to exit the program: ";
    cin >> choice;

    cout<<endl;

    if (choice == 0)
    {
        student_data.input_student_data();

        cout<<endl<<endl;
        cout << "Student Information: " << endl;
        student_data.display_student_data();
        goto start;
    }
    else if(choice == 1)
    {
        cout<<"Exiting the program"<<endl;
        exit(1);
    }
    else 
    {
        cout<<"Invalid Choice please try again"<<endl<<endl;
        count++;

        if(count==3)
        {
            cout<<"Exiting the program!! Maximum invalid choices reached"<<endl;
        }
        else
        {
            goto start;
        }
    }
    return 0;
}