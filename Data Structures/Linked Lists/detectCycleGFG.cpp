//{ Driver Code Starts
//Initial template code for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        
        
        
        Node * ptr1 = head;
        Node * ptr2 = head;
        
        unordered_map<Node*,int> map;
        
        
        // while(ptr1 != NULL){
            
        //     if(map.count(ptr1) == 0){
        //         map.insert(pair<Node*, int> (ptr1, ptr1->data));
        //         ptr1 = ptr1->next;
        //     }else{
        //         return true;
        //     }
            
            
            
        // }
        
        
    while(ptr2 != NULL && ptr2->next != NULL){
            
           
            ptr1 = ptr1->next;
            
            // if(ptr2 -> next->next)
            ptr2 = ptr2->next->next;
            
            if(ptr1 == ptr2) return 1;
        }

        return 0;
        
        
        
        // your code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}

// } Driver Code Ends