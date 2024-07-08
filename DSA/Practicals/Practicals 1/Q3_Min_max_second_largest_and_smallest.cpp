// Write a program in C that obtains the minimum and maximum element from the array.
// Modify this program to give the second largest and second smallest element of the
// array.

#include <bits/stdc++.h>
using namespace std;

void min_element(int arr[], int n)
{
    int minElement = INT_MAX;
    int secondminElement = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minElement)
        {
            secondminElement = minElement;   
            minElement = arr[i];
        }
        if(arr[i] > minElement && secondminElement > arr[i])
        {
            secondminElement = arr[i];
        }
    }     
    cout<<"The first minimum element is:  "<<minElement<<" and second minimum element is: "<<secondminElement<<endl;;
}

void max_element(int arr[], int n)
{
    int maxElement = INT_MIN;
    int secondmaxElement = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxElement)
        {
            secondmaxElement = maxElement;
            maxElement = arr[i];
        }
        if(arr[i] < maxElement && secondmaxElement < maxElement)
        {
            secondmaxElement = arr[i];
        }
    }
    cout<<"The first maximum element is:  "<<maxElement<<" and second minimum element is: "<<secondmaxElement<<endl;
}

int main()
{

start:

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    if (n == 0)
    {
        cout << "Array cannot be empty" << endl;
        goto start;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    min_element(arr,n);
    cout<<endl;
    max_element(arr,n);

    return 0;
}