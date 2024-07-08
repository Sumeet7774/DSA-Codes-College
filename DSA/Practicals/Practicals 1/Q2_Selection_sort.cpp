// 2. Write a program in C to perform bubble sort, insertion sort and selection sort. Take the 
// array size and array elements from user


#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    int temp;

    for(int i=0; i<n-1; i++)
    {
        int minIndex = i;

        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp; 
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
    selection_sort(arr,n);
    traverse(arr,n);

    return 0;
}