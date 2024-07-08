// Finding the minimum element in the BST


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

int non_recursive_minimum(Node* root)                 // Non recursive function to find the minimum element in BST
{
    if(root != NULL)                                    // checking if root is not equal to NULL, if condition is true then inside that run a while loop till root->left != NULL and keep on updating root=root->left
    {
        while(root->left != NULL)
        {
            root = root -> left;
        }
        return root->data;                                       // if the condition is false then return root->data
    }
    return -1;
}

int recursive_minimum(Node* root)                 // Non recursive function to find the minimum element in BST
{
    if(root == NULL)                               // checking if the root is NULL, if yes then return -1
    {
        return -1;
    }
    else if(root->left == NULL)                 // checking if the root's left is NULL which means there is no left child then return root->data
    {
        return root->data;
    }
    else                                        // else just make a recursive call to the function by passing root's left as argument like this root->left
    {
        return recursive_minimum(root->left);
    }
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

    int non_recursive_min = non_recursive_minimum(root);
    int recursive_min = recursive_minimum(root);

    if(non_recursive_min != -1)
    {
        cout << "The minimum element using Non-recursive method is: " << non_recursive_min << endl << endl;
    }
    else
    {
        cout << "The tree is empty." << endl<< endl;
    }

    if(recursive_min != -1)
    {
        cout << "The minimum element using Recursive method is: " << recursive_min << endl<<endl;
    }
    else
    {
        cout << "The tree is empty." << endl;
    }
 
    return 0;
}