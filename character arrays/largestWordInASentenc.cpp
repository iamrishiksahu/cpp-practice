#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    cin.ignore();

    char arr[n + 1];

// the below function is ignoring my last element input in the array
    cin.getline(arr, n);
    cin.ignore();

    cout<<arr;

    int i = 0, maxLength = 0, length = 0, s=0, maxS=0;

    while (1)
    {

        if (arr[i] == ' ' || arr[i] == '\0')
        {

            
            if(maxLength < length){
                maxLength = length;
                maxS = s;
                
            }
           
            length = 0;
            s = i+1;

            
            
        }
        else
        {
            length++;
        }

        if(arr[i] == '\0'){
            break;
        }

        i++;
    }

    cout << maxLength;

   //printing the word with max length

    for(int j =0; j < maxLength; j++ ){

    cout<<arr[j + maxS];
    }
    return 0;
}