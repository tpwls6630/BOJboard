#include <iostream>
#include <string>
#include <stack>

using namespace std;

int priorityOperator(char& c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    default:
        break;
    }
    return 0;
}

string infixToPostfix(string& infix)
{
    string postfix;
    stack<char> opStack;
    for (char token : infix)
    {
        int prioOp = priorityOperator(token);
        if (prioOp >= 1)
        {

            while (!opStack.empty() && priorityOperator(opStack.top()) >= prioOp)
            {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
        else
        {
            // prioOp = 0
            if (token == '(')
            {
                opStack.push('(');
            }
            else if (token == ')')
            {
                while (opStack.top() != '(')
                {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.pop(); // pop '('
            }
            else
            {
                postfix.push_back(token);
            }
        }
    }
    while (!opStack.empty())
    {
        postfix.push_back(opStack.top());
        opStack.pop();
    }
    return postfix;
}

int main()
{

    //while (1)
    //{
        string infixExpression;
        //cout << "Infix expression: ";
        cin >> infixExpression;
        //cout << "Postfix expression: " << infixToPostfix(infixExpression) << "\n";
        cout << infixToPostfix(infixExpression);
    //}
    return 0;
}
