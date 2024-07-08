// Double Ended Queue using array

#include <bits/stdc++.h>
using namespace std;

int myDeck[5];
int n = 5;
int size = 0;
int front = -1;
int rear = -1;

void Enque_front()                                                          // for enqueing element at front
{
    int element;
    cout<<"Enter the element to be inserted: ";
    cin>>element;

    if((front == 0 && rear == n-1) || (front == rear + 1))                  // checking if the deque is full
    {
        cout<<"Deque Overflow"<<endl;
        return;
    }
    else if(front == -1 && rear == -1)                                      // after inserting the 1st element we are checking if front and rear are both -1 then point front and rear to 1st index 
    {
        front = 0;
        rear = 0;
        size++;
        myDeck[front] = element;
        cout<<"Element "<<element<<" enqueued at the front"<<endl;
    }
    else if(front == 0)                                                 // if front is already at 0th index and you want to insert element then u have to make front point to last index and insert element
    {
        front = n-1;
        size++;
        myDeck[front] = element;
        cout<<"Element "<<element<<" enqueued at the front"<<endl;
    }
    else                                                            // if there are elements inside deque then decrement front and insert element
    {
        front--;
        size++;
        myDeck[front] = element;
        cout<<"Element "<<element<<" enqueued at the front"<<endl;
    }
}

void Enque_rear()                                                       // for enqueing element at rear 
{
    int element;
    cout<<"Enter the element to be inserted: ";
    cin>>element;

    if((front == 0 && rear == n-1 ) || (front == rear + 1 ))            // checking if the deque is full
    {
        cout<<"Deque Overflow"<<endl;
        return;
    }
    else if(front == -1 && rear == -1)                                  // after inserting the 1st element we are checking if front and rear are both -1 then point front and rear to 1st index 
    {
        front = 0;
        rear = 0;
        size++;
        myDeck[rear] = element;
        cout<<"Element "<<element<<" enqueued at the rear"<<endl;
    }
    else if(rear == n-1)                                                // if rear is already at last index and you want to insert element then u have to make rear point to 0th index and insert element
    {
        rear = 0;
        size++;
        myDeck[rear] = element;
        cout<<"Element "<<element<<" enqueued at the rear"<<endl;
    }
    else                                                                // if there are elements inside deque then increment rear and insert element
    {
        rear++;
        size++;
        myDeck[rear] = element;
        cout<<"Element "<<element<<" enqueued at the rear"<<endl;
    }
}

void Deque_front()
{
    int dequeued_element = myDeck[front];                   // storing the front element inside a variable


    if(front == -1 && rear == -1)                           // checking if the deque is empty                           
    {
        cout<<"Deque Underflow"<<endl;
        return;
    }
    else if(front == rear)                              // checking if both front and rear are at same position meaning that there is only 1 element left 
    {
        front = -1;
        rear = -1;
        size--;
    }
    else if(front == n-1)                           // checking if front has came to the last index of the deque 
    {
        front = 0;
        size--;
    }
    else                                            // if there are elements inside deque then increment front
    {
        front++;
        size--;
    }
    cout << "The dequeued element is: " << dequeued_element << endl;
}

void Deque_rear()
{
    int dequeued_element = myDeck[rear];                // storing the rear element inside a variable


    if(front == -1 && rear == -1)                       // checking if the deque is empty 
    {
        cout<<"Deque Underflow"<<endl;
        return;
    }       
    else if(front == rear)                              // checking if both front and rear are at same position meaning that there is only 1 element left 
    {
        front = -1;
        rear = -1;
        size--;
    }
    else if(rear == 0)                                  // checking if rear has came to the first index of the deque 
    {
        rear = n-1;
        size--;
    }
    else                                                // if there are elements inside deque then decrement rear
    {
        rear--;
        size--;
    }
    cout << "The dequeued element is: " << dequeued_element << endl;
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
            cout << myDeck[i]<<" ";
            i = (i + 1) % n;   
        } while (i != (rear + 1) % n );

        cout<<endl<<endl;
    }
}

void Size()                                                         // for finding the size of the deque
{
    if(size <= 0)
    {
        cout<<"Deque is empty"<<endl;
    }
    else
    {
        cout<<"The size of the deque is: "<<size<<endl;
    }
}

void Front()                                                        // for finding the front element in the deque
{
    if(front == -1)
    {
        cout<<"Deque is empty"<<endl;
    }
    else
    {
        cout<<"Front element in the deque is: "<<myDeck[front]<<endl;
    }
}

void Rear()                                                         // for finding the rear element in the deque
{
    if(rear == -1)
    {
        cout<<"Deque is empty"<<endl;
    }
    else
    {
        cout<<"Rear element in the deque is: "<<myDeck[rear]<<endl;
    }

}

int main()
{
    int choice;
    
    while(true)
    {
        cout<<endl;

        cout<<"Choose one operation:\n1. Enque Front\n2. Enque Rear\n3. Deque Front\n4. Deque Rear\n5. Size\n6. Front Element \n7. Rear Element\n8. Display\n9. Exit";
        cout<<endl<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1: 
                Enque_front();
                break;
            
            case 2:
                Enque_rear();
                break;
            
            case 3:
                Deque_front();
                break;

            case 4:
                Deque_rear();
                break;
                
            case 5:
                Size();
                break;

            case 6:
                Front();
                break;

            case 7:
                Rear();
                break;
            
            case 8:
                display();
                break;

            case 9:
                cout<<"Exiting the program"<<endl;
                exit(0);

            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}