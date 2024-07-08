// Implementing Postfix evaluation using stack


#include <bits/stdc++.h>
#include <cctype>                                                   // importing this library for using isdigit() function
using namespace std;

int postfix_eval(vector<char> postfix)                              // for evaluating postfix expression
{
    stack<int> myStack;

    for(int i=0; i<postfix.size(); i++)                            // scanning the expression from left to right
    {
        if(isdigit(postfix[i]))                                     // checking if the upcoming character is a digit, if yes then push it into stack by converting into int which can be done by subtracting it with '0' 
        {
            myStack.push(postfix[i] - '0');
        }   
        else                                                        // if the upcoming character is a operator, simply store the top element into operand1 then pop element. After that store the new top value into operand2 and then again pop
        {
            int operand1 = myStack.top();                   
            myStack.pop();
            int operand2 = myStack.top();
            myStack.pop();

            switch (postfix[i])                                     // to perform different operations according to the operator encountered in the stack. For eg we have to do addition between two operands then first we will take operand2 and then we will take operand1 like this operand2 + operand1 because it is rule in postfix evaluation
            {
            case '+':
                myStack.push(operand2 + operand1);
                break;

            case '-':
                myStack.push(operand2 - operand1);
                break;
            
            case '*':
                myStack.push(operand2 * operand1);
                break;

            case '/':
                myStack.push(operand2 / operand1);
                break;

            case '^':
               myStack.push(pow(operand2, operand1));
                break;

            default:
                break;
            }
        }
    }
    return myStack.top();                                       // at the end returning the top element because only 1 element will be there in the stack which will be the final answer
}

int main()
{
    vector<char> postfix = {'2', '3', '1', '*', '+', '9', '-'};

    cout<<"Postfix Expression: ";
    for(int i=0; i<postfix.size(); i++)
    {
        cout<<postfix[i];
    }
    cout<<endl;

    int answer = postfix_eval(postfix);

    cout<<"Postfix Evaluated answer: "<<answer<<endl;

    return 0;
}