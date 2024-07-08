// Implementing infix to postfix using stack

#include <bits/stdc++.h>
using namespace std;

int checkPrecedence(char ch)                    // for checking the precedence of the upcoming operator
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
    
        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:
            return -1;
    }
}

bool isOperand(char ch)                                 // for checking if the upcoming character is operand
{
    return (ch>='a' && ch<='z' ) || (ch>='A' && ch<='Z');
}

bool isOperator(char ch)                                // for checking if the upcoming character is operator
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

vector<char> infix_to_postix(vector<char> infix)            // for converting infix to postfix expression
{
    stack<char> myStack;
    vector<char> postfix;

    for(int i=0; i<infix.size(); i++)
    {
        if(isOperand(infix[i]))                         // checking if the upcoming character is an operand, if yes append it to postfix 
        {
            postfix.push_back(infix[i]);
        }
        else if(infix[i] == '(')                         // checking if the upcoming character is an opening parenthesis, if yes push it onto stack
        {
            myStack.push(infix[i]);
        }
        else if(infix[i] == ')')                             // checking if the upcoming character is an closing parenthesis, if yes run loop till we get opening parenthesis and keep on appending the characters from top of stack to postfix and keep on popping those characters from stack
        {
            while(!myStack.empty() && myStack.top() != '(')
            {
                postfix.push_back(myStack.top());
                myStack.pop();  
            }
            myStack.pop();                                      // for popping opening parenthesis
        }
        else if(isOperator(infix[i]))                           // checking if the upcoming character is an operator, if yes then run loop till stack is not empty and keep on checking its precedence. If the upcoming characters precedence is less than or equal to the precedence of top of the stack, then keep on appending the characters from top of stack to postfix and keep on popping those characters from stack
        {            
            while(!myStack.empty() && checkPrecedence(infix[i]) <= checkPrecedence(myStack.top()))
            {
                postfix.push_back(myStack.top());
                myStack.pop();
            }     
           myStack.push(infix[i]);                                  // after popping the characters of higher precedence, push the character with lower precedence into the stack
        }
    }
    while(!myStack.empty())                                 // for appending the remaining characters from stack to the postfix
    {
        postfix.push_back(myStack.top());
        myStack.pop();
    }

    return postfix;
}

int main()
{
    vector<char> infix = {'a','(','b','+','c','+','d',')'};
    vector<char> postfix = infix_to_postix(infix);

    cout<<"Infix Expression: ";
    for (int i = 0; i<infix.size(); i++) 
    {
        cout << infix[i];
    }
    cout<<endl;

    cout<<"Postfix Expression: ";
    for (int i = 0; i<postfix.size(); i++) 
    {
        cout << postfix[i];
    }
    return 0;
}