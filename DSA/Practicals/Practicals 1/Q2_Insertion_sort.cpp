// 2. Write a program in C to perform bubble sort, insertion sort and selection sort. Take the 
// array size and array elements from user


#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int temp = arr[i];
        int j=i-1;

        for(j=i-1; j>=0; j--)
        {
            if(arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

void traverse(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];

    if(n==0)
    {
        cout<<"Array cannot be empty"<<endl;
        exit(0);
    }

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }    
    cout<<endl;

    cout<<"Before sorting: "<<endl;
    traverse(arr,n);

    cout<<endl<<endl;

    cout<<"After sorting: "<<endl;
    insertion_sort(arr,n);
    traverse(arr,n);

    return 0;
}