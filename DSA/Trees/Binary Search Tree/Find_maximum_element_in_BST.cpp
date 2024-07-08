// Finding the maximum element in BST


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

int non_recursive_maximum(Node* root)
{
    if(root != NULL)
    {
        while(root->right != NULL)
        {
            root = root->right;
        }
        return root->data;
    }
    return -1;
}

int recursive_maximum(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    else if(root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return recursive_maximum(root->right);
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

    int non_recursive_max = non_recursive_maximum(root);
    int recursive_max = recursive_maximum(root);

    if(non_recursive_max != -1)
    {
        cout << "The maximum element using Non-recursive method is: " << non_recursive_max << endl << endl;
    }
    else
    {
        cout << "The tree is empty." << endl<< endl;
    }

    if(recursive_max != -1)
    {
        cout << "The maximum element using Recursive method is: " << recursive_max << endl<<endl;
    }
    else
    {
        cout << "The tree is empty." << endl;
    }

    return 0;
}