// Implementing Deletion on Binary Search Tree and handling all the 3 cases of deletion

// Case 1:-- Node with no child
// Case 2:-- Node with 1 child either left child or right child
// Case 3:-- Node with 2 children


#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* parent;
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

// Case 1:-- Node with no child
// In case 1, ptr must point to the node that is to be deleted and parent must point to the parent of the node to be deleted.
Node* delete_case1(Node* root, Node* ptr, Node* parent)             // function for deleting the node with value in the BST which handles case 1.
{
    if(parent == NULL)                                      // checking if the parent is null, if yes then make root as null
    {
        root = NULL;
    }
    else if (ptr == parent->left)                       // else if the ptr has reached the parent node of the node that is to be deleted, then make the parent's node left side as null
    {
        parent->left = NULL;
    }
    else 
    {
        parent->right = NULL;                       // else make the right side of the parent's node as null.
    }

    delete ptr;                                 // delete the ptr so that the element that is to be deleted will be deleted. By deleting ptr, it will free the memory space.

    return root;                                // return root at the end.
}


// Case 2:-- Node with 1 child either left child or right child
// In case 2, ptr must point to the node to be deleted and parent must be pointed to the parent of the node to be deleted.
Node* delete_case2(Node* root, Node* ptr, Node* parent)          // function for deleting the node with value in the BST which handles case 2.
{
    Node* child;

    if(ptr->left != NULL)                           // checking if the ptr's left is not equal to NULL, if condition is true then point child to ptr's left
    {
        child = ptr->left;
    }
    else if(ptr->right != NULL)                     // else if, if the ptr's right is not equal to NULL, if condtion is true then point child to ptr's right.
    {
        child = ptr->right;
    }

    if(parent == NULL)                              // checking if there is no parent node of the node to be deleted then make child as root.
    {
        root = child;
    }
    else if(ptr == parent -> left)               // else if the ptr is equal to parent's left, if yes then point parent's left as child.
    {                      
        parent->left = child;
    }
    else                                     // else point parent's right as child.
    {
        parent->right = child;             
    }

    delete ptr;                             // delete the ptr so that the element that is to be deleted will be deleted. By deleting ptr, it will free the memory space.

    return root;                            // return root at the end.
}


// Case 3:-- Node with 2 children
Node* delete_case3(Node* root, Node* ptr)           // function for deleting the node with value in the BST which handles case 3.
{
    Node* successor;
    Node* parent_successor;

    parent_successor = ptr;
    successor = ptr->right;

    while(successor->left != NULL)
    {
        parent_successor = successor;
        successor = successor->left;
    }

    ptr->data = successor->data;

    if(successor->left == NULL && successor->right == NULL)
    {
        root = delete_case1(root,successor,parent_successor);
    }
    else
    {
        root = delete_case2(root,successor,parent_successor);
    }

    return root;
}


Node* delete_node(Node* root, int value)                // function for going to the node that is to be deleted
{
    Node* ptr = root;
    Node* parent = NULL;

    while(ptr != NULL)                                          // running while loop till the end of the binary tree.
    {
        if(value == ptr->data)                          // checking if the value is equal to ptr's data then break the loop.
        {
            break;
        }

        parent = ptr;                           // Assigning parent to ptr.

        if(value < ptr->data)                   // checking if the value of the item to be deleted is less than ptr's data then make ptr go to left side of the tree.
        {
            ptr = ptr->left;
        }
        else                                    // else make ptr go to right side.
        {
            ptr = ptr->right;                   
        }
    }

    if(ptr == NULL)                                         // checking if we dont find the value to be deleted, if we dont find then print msg and return root at the end.
    {
        cout << "Element not found in the BST." << endl;
        return root;
    }

    if(ptr->left == NULL && ptr->right == NULL)         // checking if both the left and right side of the ptr is NULL, if yes then we are making a call to function delete_case1.
    {
        root = delete_case1(root,ptr,parent);
    }
    else if(ptr->left != NULL && ptr->right != NULL)
    {
        root = delete_case3(root,ptr);
    }
    else
    {
        root = delete_case2(root,ptr,parent);
    }

    return root;                                // returning root at the end.
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
   
    root = insert(root, 67);
    insert(root, 34);
    insert(root, 80);
    insert(root, 10);
    insert(root, 55);
    insert(root, 60);

    cout<<"----Insertion Successfull----"<<endl<<endl;

    
    cout<<"Before Deletion In-order is: ";
    in_order(root);

    cout<<endl;

    cout<<"Before Deletion Pre-order is: ";
    pre_order(root);    

    cout<<endl;

    cout<<"Before Deletion Post-order is: ";
    post_order(root);

    cout<<endl<<endl;

    int value;
    cout<<"Enter the element from the BST to be deleted: ";
    cin>>value;

    cout<<endl;

    root = delete_node(root,value);
    
    cout<<"After Deletion In-order is: ";
    in_order(root);

    cout<<endl;

    cout<<"After Deletion Pre-order is: ";
    pre_order(root);    

    cout<<endl;

    cout<<"After Deletion Post-order is: ";
    post_order(root);

    cout<<endl;

    return 0;
}