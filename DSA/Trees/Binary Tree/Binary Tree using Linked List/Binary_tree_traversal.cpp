// Implementing In-order, Pre-order, Post-order and Level-order traversal using linked list


#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
};

                    
class Queue
{
    public:
        Node* data;
        Queue* next;      
};


Node* createNode()                                  // function for creating a new Node
{
    int x;
    Node* newNode = new Node;

    cout<<"Enter data for node or enter -1 for no node: ";                  // Asking user to enter the data or enter -1 for no node
    cin>>x;
    cout<<endl<<endl;

    if(x == -1)                                                      // if user entered -1 then return NULL
    {
        return NULL;    
    }

    newNode -> data = x;                                         // Assign the data to new node
    
    cout<<endl;

    cout<<"Enter leftchild of "<< x <<":- ";                        // assign the left child 
    cout<<endl;
    newNode -> left = createNode();                                 // calling the createNode function recursively for creating the left child of the node

    cout<<endl;

    cout<<"Enter rightchild of "<< x <<":- ";                   // assign the rightchild 
    cout<<endl;
    newNode -> right = createNode();                                // calling the createNode function recursively for creating the right child of the node

    return newNode;                                     // At the end returning the created node
}

void in_order(Node* root)                           // function for in-order traversal
{
    if(root == NULL)                                // checking if the root is null, if yes simply return
    {
        return;
    }

    in_order(root -> left);                      // calling the in_order function recursively by passing root -> left which means by passing root's left.
    cout<< root -> data <<" ";                   // printing the root's data
    in_order(root -> right);                     // calling the in_order function recursively by passing root -> right which means by passing root's right.
}

void pre_order(Node* root)                          // function for pre-order traversal
{
    if(root == NULL)                                // checking if the root is null, if yes simply return
    {
        return;
    }

    cout<< root -> data <<" ";                        // printing the root's data
    pre_order(root -> left);                        // calling the pre_order function recursively by passing root -> left which means by passing root's left.
    pre_order(root -> right);                       // calling the pre_order function recursively by passing root -> right which means by passing root's right.
}

void post_order(Node* root)                         // function for post-order traversal
{
    if(root == NULL)                                // checking if the root is null, if yes simply return
    {
        return;
    }

    post_order(root -> left);                       // calling the post_order function recursively by passing root -> left which means by passing root's left.
    post_order(root -> right);                      // calling the post_order function recursively by passing root -> right which means by passing root's right.
    cout<< root -> data<<" ";                       // printing the root's data
}

Queue* Enque(Queue*& front,Queue*& rear,Node* data)
{   
    Queue* ptr = new Queue;     
    ptr -> data = data;
    ptr -> next = NULL;

    if(front == NULL && rear == NULL)            // if the front and rear are null then make the first element as both front and rear
    {
        front = ptr;
        rear = ptr; 
    }
    else
    {
        rear -> next = ptr;                 // if the front is already there then just make rear's next as ptr which is new node
        rear = ptr;                         // then after that make ptr as rear
    }

    return rear;
}

Node* Deque(Queue*& front, Queue*& rear)
{
    if (front == NULL)                              
    {
        rear = NULL;
        cout << "Queue Underflow" << endl;
        return NULL;
    }

    Queue* ptr = front;
    Node* deleted_element = ptr->data;

    if (front == rear)                              // if there is only one element in the queue     
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
    }
    delete ptr;

    if(front == NULL)                       // if after removing the element if the front becomes null then reset the rear to also null
    {
        rear = NULL; 
    }

    return deleted_element; 
}

void level_order(Node* root)
{
    Node* ptr = root;
    Node* cur_node;

    if(ptr == NULL)
    {
        cout<<"Binary Tree is empty"<<endl;
        return;
    }

    Queue* front = NULL;
    Queue* rear = NULL;

    Enque(front,rear,root);   

    while(front != NULL)
    {   
        cur_node = Deque(front,rear);
        cout << cur_node->data<< " ";
    
        if(cur_node -> left != NULL)
        {   
            Enque(front,rear,cur_node->left);       
        }

        if(cur_node -> right != NULL)
        {
            Enque(front,rear,cur_node->right);
        }
    } 
}

int main()
{
    Node* root = NULL;
    root = createNode();

    cout<<"In-order is: ";
    in_order(root);

    cout<<endl<<endl;

    cout<<"Pre-order is: ";
    pre_order(root);    

    cout<<endl<<endl;

    cout<<"Post-order is: ";
    post_order(root);

    cout<<endl<<endl;

    cout<<"Level-order is: ";
    level_order(root);
    
    return 0;
}