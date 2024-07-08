// Circular Queue using Array

#include <bits/stdc++.h>
using namespace std;

int myQueue[5];
int n = 5;
int size = 0;
int front = -1;
int rear = -1;

void Enque()
{
    int element;
    cout<<"Enter the element to be inserted: ";
    cin>>element;

    if(front == (rear + 1) % n)                         // checking if the queue has become full
    {
        cout<<"Queue Overflow"<<endl;
        return;
    }
    else if(front == -1 && rear == -1)                  // after inserting the 1st element we are checking if front and rear are both -1 then point front and rear to 1st index 
    {
        front = 0;
        rear = 0;
        myQueue[rear] = element;
        size++;
    }
    else                                                // if there are elements already in queue then just increment rear  
    {   
        rear = (rear + 1) % n;
        myQueue[rear] = element;
        size++;
        cout<<"Element enqueued into the queue"<<endl;
    }   
}

// void Deque()
// {
//     if(front == -1 && rear == -1)
//     {
//         cout<<"Queue Underflow"<<endl;
//         return;
//     }
//     else if(front == rear)
//     {
//         front = -1;
//         rear = -1;
//         size--;
//     }
//     else
//     {
//         int dequeued_element = myQueue[front];
//         front = (front + 1) % n;
//         size--;
//         cout<<"Element "<<dequeued_element<<" dequeued from the queue"<<endl;
//     }
// }

void Deque()
{
    if (front == -1 && rear == -1)                          // checking if the queue is empty
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    else                                                    // if not then else part
    {
        int dequeued_element = myQueue[front];              // storing the dequeued element inside dequeued_element 
        
        if (front == rear)                                  // checking if we have reached the last element of the queue, if yes then make front and rear both -1
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % n;                    // if there are elements still inside queue then just increment front
        }   
        size--;
        cout << "Element " << dequeued_element << " dequeued from the queue" << endl;
    }
}

void Size()
{
    cout<<"The size of the queue is: "<<size<<endl;
}

void Front()
{
    if(front == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"The Front element in the queue is: "<<myQueue[front]<<endl;  
    }
}

void Rear()
{
    if(rear == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"The Rear element in the queue is: "<<myQueue[rear]<<endl;  
    }
}

void display()
{
    if(front == -1 && rear == -1)                   // checking if the queue is empty or not
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    else
    {
        int i = front;                              // assigning the front value to i

        do                                          // running a do while loop untill the while condition which is we dont reach till the rear element it will print all the elements of the queue
        {
            cout << myQueue[i]<<" ";
            i = (i + 1) % n;   
        } while (i != (rear + 1) % n );

        cout<<endl<<endl;
    }
}   

int main()
{
    int choice;
    
    while(true)
    {
        cout<<endl;

        cout<<"Choose one operation:\n1. Enque\n2. Deque\n3. Size\n4. Front Element \n5. Rear Element\n6. Display\n7. Exit";
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
                Size();
                break;

            case 4:
                Front();
                break;
                
            case 5:
                Rear();
                break;

            case 6:
                display();
                break;

            case 7:
                cout<<"Exiting the program"<<endl;
                exit(0);

            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}