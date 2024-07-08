#include <iostream>
using namespace std;

class Array_Deletion{
    public:
        void deletion(int arr[], int n, int pos)
        {
            if(pos>=n)
            {
                cout<<"Overflow"<<endl;
            }

            if (pos < 0 || pos >= n) 
            {
                cout << "Invalid position for deletion." <<endl;
                return;
            }
        
            for(int i=pos; i<n-1; i++)
            {
                arr[i] = arr[i+1];
            }
            n--;
        
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
    int n;
    int pos;
    
    cout<<"Enter the elements of the array: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<endl;
    cout<<"Before deletion: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<endl;

    cout<<"Enter the index to delete the element: "<<endl;
    cin>>pos;
    cout<<endl;

    cout<<"After deletion: "<<endl;
    Array_Deletion lmao;
    lmao.deletion(arr,n,pos);
    lmao.display(arr,n);

    return 0;
}