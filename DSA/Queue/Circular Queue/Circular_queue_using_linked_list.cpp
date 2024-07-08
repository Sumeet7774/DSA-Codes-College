// Circular Queue using linked list


#include <bits/stdc++.h>
using namespace std;

// Global variables
int size = 0;                       
const int maxSize = 5;          // maximum size of queue

class Queue
{
    public:
        int data;
        Queue* next;
};

Queue* Enque(Queue*& front,Queue*& rear,int data)
{
    if(size >= maxSize)
    {
        cout<<"Queue Overflow"<<endl;
        return rear;
    }

    Queue* ptr = new Queue;
    ptr -> data = data;
    ptr -> next = NULL;

    if (rear == NULL && front == NULL)
    {
        front = ptr;
        rear = ptr;
        rear -> next = front;
    }
    else
    {
        rear -> next = ptr;
        rear = ptr;
        rear -> next = front;
    }
    size++;
    cout<<"Element enqueued into the queue"<<endl;
    return rear;
}

Queue* Deque(Queue*& front,Queue*& rear)
{
    if(front == NULL)
    {
        cout<<"Queue Underflow"<<endl;
        return front;
    }

    Queue* ptr = front;
    int deleted_element = ptr->data;

    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front -> next;
        rear -> next = front;
    }
    size--;
    cout << "Element "<< deleted_element<<" dequed from the queue"<< endl;
    delete ptr;
    
    return front;
}

void Front(Queue*& front)                                         // for finding the front element of the queue
{   
    if(front == NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    cout<<"The Front element is: "<< front -> data <<endl;
}

void Rear(Queue*& rear)                                          // for finding the rear element of the queue
{
    if(rear == NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    cout<<"The Rear element is: "<< rear -> data <<endl;
}

void Size()
{
    cout<<"The size of the queue is: "<<size<<endl;
}

void display(Queue* &front, Queue* &rear)
{
    Queue* ptr = front;

    if(front == NULL && rear == NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        do
        {
            cout << "Element in the queue is: " << ptr->data << endl;
            ptr = ptr->next;
        } while (ptr != front);
    }
}


int main()
{
    Queue* front = NULL;
    Queue* rear = NULL;

    int choice;
    
    while(true)
    {
        cout<<endl;

        cout<<"Choose one operation:\n1. Enque\n2. Deque\n3. Front Element\n4. Rear Element\n5. Size\n6. Display\n7. Exit";
        cout<<endl<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: 
                int data;
                cout<<"Enter the element to be inserted: ";
                cin>>data;
                rear = Enque(front,rear,data);
                break;
            
            case 2:
                front = Deque(front,rear);
                break;
            
            case 3:
                Front(front);
                break;
            
            case 4:
                Rear(rear);
                break;

            case 5:
                Size();
                break;

            case 6:
                display(front,rear);
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