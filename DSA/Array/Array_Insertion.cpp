#include <iostream>
using namespace std;

class Array_Insertion{
    public:
        void insertion(int arr[], int n, int capacity, int element, int pos)
        {
            if(n>=capacity)
            {
                cout<<"Overflow"<<endl;
            }
        
            for(int i=n-1; i>=pos; i--)
            {
                arr[i+1] = arr[i];
            }
            arr[pos] = element;
            n++; 
        }

        void display(int arr[], int n)
        {
            for(int i=0; i<n; i++)
            {
                cout<<arr[i]<<endl;
            }
        }
};

int main()
{
    int arr[100];
    int capacity=100;
    int element;
    int n;
    int pos;
    
    cout<<"Enter the elements of the array: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<endl;
    cout<<"Before insertion: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<endl;

    cout<<"Enter the element to be inserted: "<<endl;
    cin>>element;
    cout<<endl;

    cout<<"Enter the index to insert the element: "<<endl;
    cin>>pos;
    cout<<endl;

    cout<<"After insertion: "<<endl;
    Array_Insertion lmao;
    lmao.insertion(arr,n,capacity,element,pos);
    lmao.display(arr,n);
    
    return 0;

}