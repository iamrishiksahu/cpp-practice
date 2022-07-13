#include <bits/stdc++.h>

using namespace std;

// Implementation of stack by making push operation costly.
class Stack
{

    int N;

    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }

    void push(int a)
    {

        q2.push(a);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {

        q1.pop();
        N--;
    }

    int top()
    {
        if (N > 0)
        {
            return q1.front();
        }

        cout << "Stack is empty!\n";
        return INT_MIN;
    }

    int size()
    {
        return N;
    }
};

// Implementation of stack by making pop operation costly.
class Stack2
{

    int N;

    queue<int> q1;
    queue<int> q2;

public:
    Stack2()
    {
        N = 0;
    }

    void push(int a)
    {
        q1.push(a);
        N++;
    }

    void pop()
    {

        while (q1.size() != 1)
        {
            q2.push(q1.front());

            q1.pop();
        }

        q1.pop();
        N--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    bool empty()
    {

        if (N == 0)
        {
            return 1;
        }
        return 0;
    }

    int top()
    {
        if (empty())
        {
            cout << "No element found!\n";
            return INT_MIN;
        }

        return q1.back();
    }

    int size()
    {
        return N;
    }
};
int main()
{

    Stack s;
    // Stack2 s; //use this to test the stack 2


    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.top();

    s.pop();

    cout << s.top();

    return 0;
}