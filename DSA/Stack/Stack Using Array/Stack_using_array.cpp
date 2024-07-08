#include <bits/stdc++.h>
using namespace std;

int stack[10];          // max size of stack                                    // declared as global
int n = 10;             // max size of stack                                    // declared as global
int top = -1;           // by default the top of the stack will be -1           // declared as global

void push()                             // for inserting element inside stack
{
    int element;
    cout<<"Enter the element to be inserted: ";
    cin>>element;

    if(top >= n-1)                          // checking if the top element is more than the size of the stack. We write n-1 because array index start with 0
    {
        cout<<"Stack overflow"<<endl;       // if yes then stack is overflown
    }
    else
    {
        top++;                              // if not then we increment the value of top and assign the elment to stack[top]. This means we are assigning the inserted element in the stack as top
        ::stack[top] = element;             // we have to write :: its because we are specifying that we want to use global stack array rather than any other stack array from different scope
        cout<<"Element pushed in stack"<<endl;
    }   
}

void pop()                          // for deleting the element
{
    if(top < 0)                         // checking if the top element is less than 0. This means if the top element is -1 which also means that stack is empty. 
    {   
        cout<<"Underflow"<<endl;        // if yes then underflow
    }
    else
    {
        top--;                                      // else then decrement the value of top which means that element is removed from the stack
        cout<<"Element popped in stack"<<endl;
    }
}

void peek()                         // for finding the top of the element
{
    if(top < 0)                         // checking if stack is empty
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {           
        cout<<"Top element in the stack is: "<<::stack[top]<<endl;          // if not then we just print the current top elment of the stack by writing stack[top]
    }
}

void display()                  // for displaying elements of the stack
{
    if(top < 0)                         // checking if stack is empty
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        for(int i=0; i<=top; i++)           // if not then we loop through the stack will we reach the top element and then we print all those elements
        {
            cout<<::stack[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int choice;
    
    while(true)
    {
        cout<<endl<<endl;

        cout<<"Choose one operation:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Quit\n";
        cout<<endl<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;
            
            case 4:
                display();
                break;

            case 5:
                cout<<"Exiting the program"<<endl;
                exit(0);

            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}