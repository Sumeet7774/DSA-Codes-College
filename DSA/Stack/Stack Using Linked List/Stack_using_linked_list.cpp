// Implementing stack using linked list

#include <bits/stdc++.h>
using namespace std;

// Global variables
int size = 0;                       
const int maxSize = 5;          // maximum size of stack

class Stack
{
    public:
        int data;
        Stack* next;
};

Stack* push(Stack* top, int data)                   // for inserting elements inside stack
{
    if(size >= maxSize)
    {
        cout<<"Stack overflow"<<endl;
        return top;
    }
    Stack* newNode = new Stack;
    newNode -> data = data;
    newNode -> next = top;
    top = newNode;
    size++;
    cout<<"Element "<< data << " pushed inside stack"<<endl;

    return top;
}

Stack* pop(Stack* top)                              // for deleting elements from stack
{
    if(top == NULL)
    {
        cout<<"Stack Underflow"<<endl;
        return top;
    }
    Stack* ptr = top;
    cout<<"Element "<<top -> data<<" popped from the list";
    top = top -> next;
    delete ptr;
    size--;

    return top;
}

void peek(Stack* top)                               // for finding the top element from the stack
{
    if(top == NULL)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"Top element in the list is: "<<top -> data<<endl;
}

void display(Stack* ptr)                        // for printing all the elements from the stack
{
    if (ptr == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    while(ptr != NULL)
    {
        cout<<"Element is: "<<ptr->data <<endl;
        ptr = ptr->next;
    }
}

int main()
{
    Stack* top = NULL;
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
                int element;
                cout<<"Enter the element to be inserted: ";
                cin>>element;
                top = push(top,element);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                peek(top);
                break;
            
            case 4:
                display(top);
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