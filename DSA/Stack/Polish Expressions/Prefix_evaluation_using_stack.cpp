// Implementing Prefix evaluation using stack

#include <bits/stdc++.h>
#include <cctype>                                                   // importing this library for using isdigit() function
using namespace std;

int prefix_eval(vector<char> prefix)                                    // for evaluating prefix expression
{
    stack<int> myStack;

    for(int i=prefix.size()-1; i>=0; i--)                                 // scanning the expression from right to left
    {
        if(isdigit(prefix[i]))                                          // checking if the upcoming character is a digit, if yes then push it into stack by converting into int which can be done by subtracting it with '0' 
        {
            myStack.push(prefix[i] - '0');
        }
        else                                                            // if the upcoming character is a operator, simply store the top element into operand1 then pop element. After that store the new top value into operand2 and then again pop
        {
            int operand1 = myStack.top();
            myStack.pop();
            int operand2 = myStack.top();
            myStack.pop();

            switch (prefix[i])                                      // to perform different operations according to the operator encountered in the stack. For eg we have to do addition between two operands then first we will take operand1 and then we will take operand2 like this operand1 + operand2 because it is rule in prefix evaluation
            {
            case '+':
                myStack.push(operand1 + operand2);
                break;
            
            case '-':
                myStack.push(operand1 - operand2);
                break;

            case '*':
                myStack.push(operand1 * operand2);
                break;

            case '/':
                myStack.push(operand1 / operand2);
                break;;

            case '^':
                myStack.push(pow(operand1, operand2));;
                break;

            default:
                break;
            } 
        }
    } 

    return myStack.top();                                   // at the end returning the top element because only 1 element will be there in the stack which will be the final answer
}

int main()
{
    vector<char> prefix = {'*', '+', '6', '9', '-', '3', '1'};

    cout<<"Prefix Expression: ";
    for (int i = 0; i<prefix.size(); i++) 
    {
        cout << prefix[i];
    }
    cout<<endl;

    int answer = prefix_eval(prefix);
    
    cout<<"Prefix Evaluated Answer: "<<answer<<endl;
    

    return 0;
}