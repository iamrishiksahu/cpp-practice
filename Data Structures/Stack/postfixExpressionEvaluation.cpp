#include <iostream>
#include <stack>
#include<math.h>

using namespace std;

int postfixEvaluate(string s)
{

    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] >= '0' && s[i] <= '9')
        {
            // the character is a number.

            st.push(s[i] - '0');
        }
        else
        {
            // character is an operator.

            //the top most element in the stack is the second operator and the bottom element is the first operator.

            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':

                st.push(op1 + op2); 
                break;

             case '-':

                st.push(op1 - op2);
                break;

             case '/':

                st.push(op1 / op2);
                break;

            case '*':

                st.push(op1 * op2);
                break;

            case '%':

                st.push(op1 % op2);
                break;

            case '^':

                st.push(pow(op1,op2));
                break;

            default:
                break;
            }
        }
    }

    return st.top();
}

int main()
{

    string s = "46+2/5*7+";

    cout<<postfixEvaluate(s);


    return 0;
}
