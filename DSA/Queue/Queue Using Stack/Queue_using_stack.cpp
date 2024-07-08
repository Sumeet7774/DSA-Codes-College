// Implementing Queue using Stack

#include <bits/stdc++.h>
using namespace std;

// Global Variables
int n = 5;
int myCount = 0;
int top1 = -1;
int top2 = -1;
int myStack1[5];
int myStack2[5];


void push1(int element)                                                     // for pushing elements into Stack1
{
    if(top1 == n-1)
    {
        cout<<"Queue Overflow"<<endl;
        return;
    }
    top1++;
    myStack1[top1] = element;
}

int pop1()                                                                  // for popping elements from Stack1
{
    return myStack1[top1--];
}

void Enque()                                                                // For inserting elements into queue
{
    if(myCount == n)
    {
        cout<<"Queue overflow"<<endl;
        return;
    }

    int element;
    cout<<"Enter the element to be inserted: ";
    cin>>element;

    push1(element);
    cout<<"Element "<<element<< " enqueued into the queue"<<endl;
    myCount++;
}

void push2(int element)                                                    // For pushing elements into Stack2
{
    if(top2 == n-1)
    {
        cout<<"Queue Overflow"<<endl;
        return;
    }
    top2++;
    myStack2[top2] = element;
}

int pop2()                                                                  // For popping elements from Stack2
{
    return myStack2[top2--];
}

void Deque()                                                               // For deleting elements from queue
{
    int a, b;

    if(top1 == -1 && top2 == -1)
    {
        cout<<"Queue Underflow"<<endl;
        return;
    }
    else
    {
        while(top1 != -1)                                               // Moving elements from myStack1 to myStack2
        {
            a = pop1();
            push2(a);
        }

        b = pop2();                                                             // Popped the front element from myStack2
        int dequeued_element = b;
        cout<<"Element "<< dequeued_element<< " is dequeued from the queue"<<endl;
        myCount--;

        while(top2 != -1)                                                   // Moving elements back from myStack2 to myStack1
        {
            a = pop2();
            push1(a);
        }
    }
}

void display()                                                              // For displaying elements of the queue
{
    if(top1 == -1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        cout<<"The elements in the queue are: "<<endl;

        for(int i=0; i<=top1; i++)
        {
            cout<<myStack1[i]<<" ";
        }
        cout<<endl<<endl;
    }
}

int main()
{
    int choice;
    
    while(true)
    {
        cout<<endl;

        cout<<"Choose one operation:\n1. Enque\n2. Deque\n3. Display\n4. Exit";
        cout<<endl<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: 
                Enque();
                break;
            
            case 2:
                Deque();
                break;
            
            case 3:
                display();
                break;

            case 4:
                cout<<"Exiting the program"<<endl;
                exit(0);

            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}