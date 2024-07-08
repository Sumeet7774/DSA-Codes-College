#include <iostream>
using namespace std;
int main()
{
    int arr[50];
    int n;
    int *ptr;

    cout<<"Enter the elements of the array: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<endl;

    ptr=arr;
    cout<<"The elements of the array are: "<<endl;

    for (int i=0; i<n; i++)
    {   
        cout<<*ptr<<endl;
        *ptr++;
    }
    
    return 0;
}