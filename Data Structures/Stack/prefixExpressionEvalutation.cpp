#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int prefixEvaluate(string s)
{

    stack<int> st;

    for (int i = s.length()-1; i >=0; i--)
    {

        if (s[i] >= '0' && s[i] <= '9')
        {
            // the character is an integer number

            // we are pushing the actual integer value; not the character

            st.push(s[i] - '0');
        }
        else
        {
            // the character is an operator

            int op1 = st.top();
            st.pop();
            int op2 = st.top();
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

    string s = "-+7*45+20"; // the output should be 25

    cout<<prefixEvaluate(s);

    return 0;
}