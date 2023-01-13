#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void preOrder(node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    //processing
    cout << root->data << " ";

    //recursive call
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root){

    //base case
    if(root == NULL){
        return;
    }

    // recursive call

    postOrder(root->left);
    postOrder(root->right);

    // processing
    cout<<root->data<<" ";
}

void inOrder(node *root){

    // base case
    if(root == NULL){
        return;
    }

    //recursive call

    inOrder(root->left);

    //processing

    cout<<root->data<< " ";

    //recursive call

    inOrder(root->right);
}


int main()
{
   /**
    *       GIVEN TREE
    * 
    *           4
    *          / \
    *         1   6
    *        / \        
    *       5   2
    * 
   */

    node *root = new node(5);
    node* r1 = new node(1);
    node* r1r1 = new node(7);
    node* r1l1 = new node(6);
    node* l1 = new node(3);
    node* l1l1 = new node(4);
    node * l1r1 = new node(1);
    node* l1r1l1 = new node(7);
    node* l1r1r1 = new node(8);


    root->left = l1;
    root->right = r1;

    l1->left = l1l1;
    l1->right = l1r1;

    l1r1->left = l1r1l1;
    l1r1->right = l1r1r1;

    r1->left = r1l1;
    r1->right = r1r1;

    // node *root = new node(4);
    // node *p1 = new node(1);
    // node *p2 = new node(6);
    // node *p3 = new node(5);
    // node *p4 = new node(2);

    // root->left = p1;
    // root->right = p2;

    // p1->left = p3;
    // p1->right = p4;

    preOrder(root);
    cout<<endl<<endl;
    postOrder(root);
    cout<<endl<<endl;
    inOrder(root);

    // cout << endl
    //      << root->right->data <<endl<< endl;

    return 0;
}
