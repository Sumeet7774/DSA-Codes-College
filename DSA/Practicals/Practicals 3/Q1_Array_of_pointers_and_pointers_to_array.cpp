// 1. Write a program in C to implement arrays of pointers and pointers to arrays.

#include <bits/stdc++.h>
using namespace std;

void pointers_to_array(int arr[], int n, int *ptr[])                // implementing the concept of pointers to arrays
{
    for(int i=0; i<n; i++)
    {
        ptr[i] = &arr[i];           // assigning the address of each element to the pointer array which is ptr
    }

    cout<<"Printing the addresses of array elements using pointer: "<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<ptr[i]<<" ";              // printing the addresses of the values 
    }
    cout<<endl<<endl;

    cout<<"Printing the values using array of pointers: "<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<*ptr[i]<<" ";                     // deferencing the pointer and printing the values of the array
    }       
    cout<<endl<<endl;

}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    int *ptr[n];                    // array of pointers of size n

    cout<<"Enter the elements inside array: "<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl<<endl;

    pointers_to_array(arr,n,ptr);

    return 0;
}