// Linear queue using array


#include <bits/stdc++.h>
using namespace std;

int myQueue[5]; 
int n = 5;
int front =-1;
int rear = -1;
int size = 0;

void Enque()
{
    int element;
    cout<<"Enter the element to be inserted: ";
    cin>>element;

    if(rear == n-1)                           // if the rear is same as 5 then queue has overflown
    {
        cout<<"Queue Overflow"<<endl;
    }
    else if(rear == -1 && front == -1)      // if the rear and front are -1 then update them to 0 and so on
    {
        front++;
        rear++;
        myQueue[front] = element;
        size++;
    }
    else
    {
        rear++;                     // else just increment rear if the front is already 0 or is at any other index
        myQueue[rear]=element;          // assign the element to the myQueue[rear] which means this will assign to the array
        size++;
        cout<<"Element enqueued into the queue"<<endl;
    }   
}

void Deque()
{
    if(front==-1 and rear ==-1)                     // if front and rear are already -1 then this means that queue is empty
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(front == rear + 1 )                      // this means if front and rear are same which means there is only one element left so after we delete that element assign front and rear as -1
    {
        front = -1;
        rear = -1;
        size--;
        cout<<"Queue Underflow"<<endl;
    }
    else
    {
        int dequeued_element = myQueue[front];  // else just after deleting the front element then just increment the front element to point to next element
        front++;
        size--;     
        cout<<"Element "<<dequeued_element<<" dequeued from the queue"<<endl;
    }
}

void Size()
{
    cout<<"The size of the queue is: "<<size<<endl;      
}

void display()
{
    if(front==-1 && rear == -1 )                // if front and rear both are -1 then queue is empty
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        for(int i=front; i<=rear; i++)                   // looping till the last element that has been inserted
        {
            cout<<myQueue[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int choice;
    
    while(true)
    {
        cout<<endl;

        cout<<"Choose one operation:\n1. Enque\n2. Deque\n3. Size\n4. Display\n5. Exit";
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

    