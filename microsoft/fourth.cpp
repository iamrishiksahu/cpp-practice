#include<bits/stdc++.h>

using namespace std;


class node{


    private:

    int data;
    node *left;
    node *right;

    node(int d){

        data = d;
        left = NULL;
        right = NULL;
    }
};


int main(){


    node *root = new node(2);
    
    root->left = new node(3);
    root->right = new node(4);

    cout<<root->right->data;

    return 0;
}