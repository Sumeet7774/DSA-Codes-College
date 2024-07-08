#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        int prev_sum = sum(n-1);
        return n + prev_sum;
    }
}


int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<endl;

    int answer = sum(n);

    cout<<"The sum is: "<<answer<<endl;

    return 0;
}