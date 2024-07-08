// Implementing/Creating Binary tree using linked list


#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
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


int main()
{
    Node* root = NULL;
    root = createNode();                        // creating the root node by calling the createNode function

    return 0;
}