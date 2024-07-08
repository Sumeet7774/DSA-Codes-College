// Binary Trees Implementation using array
// This is for 0th based indexing.
// For 1st based indexing just making changes in the formula of inserting in insert_left as binaryTree[(2*parent)] = c; and for inserting in insert_right as binaryTree[(2*parent)+1]=c; 

#include <bits/stdc++.h>
using namespace std;
#define MAX 10

char binaryTree[MAX];                 // Global array of size MAX. And here the size of MAX is 10

void root(char c)                                   // for inserting root element
{
    if(binaryTree[0] != '\0')                       // if the 
    {
        cout<<"Root already exists"<<endl;
    }
    else
    {
        binaryTree[0] = c;
    }
}

void insert_left(char c, int parent)
{
    if(binaryTree[parent] == '\0')
    {
        cout<<"Cant insert "<<c<< "because the parent of "<<c<<" doesnt exist"<<endl;
    }
    else
    {
        binaryTree[(2*parent)+1] = c;
    }
}

void insert_right(char c, int parent)
{
    if(binaryTree[parent] == '\0')
    {
        cout<<"Cant insert "<<c<< "because the parent of "<<c<<" doesnt exist"<<endl;
    }
    else
    {
        binaryTree[(2*parent)+2] = c;
    }
}

void print()
{
    for(int i=0; i<MAX; i++)
    {
        if(binaryTree[i] == '\0')
        {
            cout<<"*";
        }
        else
        {
            cout<<binaryTree[i];
        }
    }
}


int main()
{
    root('A');
    //root('Z');                        //testcase
    insert_left('B',0);
    insert_right('C',0);
    insert_right('D',2);
    //insert_right('D',3);              //testcase

    cout<<endl;

    cout<<"The Binary Tree is: ";
    print();
    
    return 0;
}