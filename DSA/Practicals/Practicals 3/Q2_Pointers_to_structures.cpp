// 2. Write a program in C to implement pointers to structures.

#include <bits/stdc++.h>
using namespace std;

class Pointers_to_class
{
    public:

        int a,b;
    
        void display()
        {
            cout<<"Enter the size of a: ";
            cin>>a;

            cout<<"Enter the size of b: ";
            cin>>b;
            
            cout<<"Sum of a and b is: "<<a+b<<endl;
        }
};

int main()
{
    Pointers_to_class *ptr = new Pointers_to_class;           // we have to initialize the pointer with an object of Pointer_to_class before calling display()

    cout<<"The values of a and b are: "<<ptr->a<<" "<<ptr->b <<endl;
    ptr -> display();                                                     // we have to use -> arrow operator to access class members because we are using pointer
   
    return 0;
}