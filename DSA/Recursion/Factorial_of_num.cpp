#include <bits/stdc++.h>
using namespace std;

int factos(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        int prev_factos = factos(n-1);
        return n * prev_factos;
    }
}


int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<endl;

    int answer = factos(n);

    cout<<"The factorial is: "<<answer;

    return 0;
}