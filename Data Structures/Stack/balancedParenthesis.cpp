#include <iostream>
#include <stack>

using namespace std;

bool is_Valid(string s)
{

    stack<int> st;

    bool isValidString = 1;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {

            st.push(s[i]);

        }else if( s[i] == '}' || s[i] == ']' || s[i] == ')'){
            if (st.empty())
            {
                isValidString = 0;
            }
            else
            {

                char c = st.top();
                char a = s[i];
                if (c == '(' && a == ')')
                {
                    st.pop();
                    continue;
                }
                else if (c == '[' && a == ']')
                {
                    st.pop();
                    continue;
                }
                else if (c == '{' && a == '}')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    isValidString = 0;
                    break;
                }
            }
        }
    }
    

    return isValidString;
}

int main()
{

    string s = "{[[(])]}";

    if (is_Valid(s))
    {
        cout << "Yes! the string is valid!" << endl;
    }
    else
    {
        cout << "The string is invalid!";
    }

    return 0;
}