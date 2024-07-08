#include <iostream>
using namespace std;
int main()
{
    int arr[50];
    int n;
    
    cout<<"Enter the elements of the array: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<endl;
    cout<<"The elements of the array are: "<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;


}

