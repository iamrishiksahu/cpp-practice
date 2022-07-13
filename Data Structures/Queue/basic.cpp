#include <iostream>

using namespace std;

#define n 100

class queue {

    int *arr;
    int front;
    int back;

    

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int a)
    {

        if (back == n - 1)
        {
            cout << "Queue overflown!";
        }
        else
        {
            if(front == -1){
                front++;
            }
            arr[++back] = a;
        }
    }

    int dequeue()
    {
        if (empty())
        {
            cout << "Queue underflown!";
            return INT_MIN;
        }
        return arr[front++];
    }

    bool empty()
    {

        if (front == -1 || front > back)
        {
            return 1;
        }

        return 0;
    }

    int peak()
    {
        if (!empty())
        {
            return arr[back];
        }else{
            
            return INT_MIN;
        }
    }
};

int main()
{

    queue q;

    // cout<<n;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.peak()<<endl;

    cout<<q.empty();

    return 0;
}