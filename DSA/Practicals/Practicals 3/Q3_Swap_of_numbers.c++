#include <bits/stdc++.h>
using namespace std;

void swap(int *ptr1, int *ptr2)
{
    int temp;

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    int a, b;

    cout << "Enter value for a: ";
    cin >> a;
    cout << "Enter value for b: ";
    cin >> b;

    cout << endl;

    cout<<"Before swapping the values of a and b are: "<<a<<" "<<b<<endl;

    swap(&a,&b);
    cout<<"After swapping the values of a and b are: "<<a<<" "<<b<<endl;
    
    return 0;
}