//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

class student
{
    protected :
        int roll_number;
        
    public:
        void set_number(int a)
        {
            roll_number = a;
        }
        
        void display_number()
        {
            cout<<roll_number<<endl;
        }
};


// } Driver Code Ends
//User function Template for C++
class test: public student 
{
    // Add set_marks() method here.
    
    public:
    
    float s1, s2, s3, s4, s5;
    
    void set_marks(float arr[]){
        s1 = arr[0];
        s2 = arr[1];
        s3 = arr[2];
        s4 = arr[3];
        s5 = arr[4];
    }
    
    
};

class result: public test
{
    // Add display() method here.
    
    public:
    
    float tm = s1+s2+s3+s4+s5;
    
    void display(){
           cout<<roll_number<<" "<<tm<<" "<<tm/5<<endl;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
    	result student1;
	    int n;
	    cin>>n;
	    student1.set_number(n);
	    float temp[5];
	    int i;
	
	    for(i = 0; i < 5; i++)
	        cin>>temp[i];
	
	    student1.set_marks(temp);
	    student1.display();
	}

	return 0;    
}

// } Driver Code Ends