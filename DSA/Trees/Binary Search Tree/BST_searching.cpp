// Implementing Searching on Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
};


Node* insert(Node* root, int value)                             // for inserting element into BST
{
    if(root == NULL)                                            // if the root is NULL which means there is no node in BST then create a newNode and assign data to it and assign left and right of that node to NULL and at last return newNode
    {
        Node* newNode = new Node;
        newNode -> data = value;
        newNode -> left = NULL;
        newNode -> right = NULL;

        return newNode;
    }

    if(value < root -> data)                                    // checking if the value that is being is inserted is less than the root, if yes then it will be part of left subtree.
    {
        root -> left = insert(root -> left, value);
    }
    else                                                        // else if the value that is being is inserted is greater than the root, then it will be part of right subtree.
    {
        root -> right = insert(root -> right, value);
    }

    return root;
}

Node* search(Node* root, int item)                              // for searching value from BST
{
    if(root == NULL)                                        // if there are no nodes which means the root is NULL, then return NULL
    {
        return NULL;
    }

    if(root -> data == item)                            // if the root's data is equal to item, then return root
    {
        return root;
    }

    if(item < root -> data)                             // if item's value is less than root -> data which means item < root's data, then call the search function and search on root's left side like this root -> left
    {
        search(root -> left, item);
    }
    else                                                // else if the item's value is more than root -> data which means item > root's data, then call the search function and search on root's right side like this root -> right
    {
        search(root -> right, item);    
    }
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


int main()
{
    Node* root = NULL;

    cout<<"----Inserting into BST:----"<<endl<<endl;
   
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout<<"----Insertion Successfull----"<<endl<<endl;

    cout<<"In-order is: ";
    in_order(root);

    cout<<endl<<endl;

    cout<<"Pre-order is: ";
    pre_order(root);    

    cout<<endl<<endl;

    cout<<"Post-order is: ";
    post_order(root);

    cout<<endl<<endl;

    int item;

    cout<<"Enter the element to be searched in BST: ";
    cin>>item;

    cout<<endl;

    if(search(root,item) == NULL)                       // if the search function return NULL then this means item was not found
    {
        cout<<"Value Not Found"<<endl;
    }
    else                                                // if the search function returns root then this means item was found
    {
        cout<<"Value Found"<<endl;
    }
 
    return 0;
}