#include <bits/stdc++.h>

using namespace std;

class node
{

public:
    int val;
    node *left;
    node *right;

    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void inOrderGeneral(node *root){

    while(root != NULL){

        while(root->left != NULL){

            cout<<root->val<<" ";

        }

        cout<<root->val;

        while(root->right != NULL){

            cout<<root->val<<' ';
        }

    }
}

void inOrderActualHelper(node *root, vector<int> list)
{

    if (root == NULL)
    {
        inOrderActualHelper(root->left, list);
        list.push_back(root->val);
        inOrderActualHelper(root->right, list);
        
    }
}

vector<int> inOrderHelperStarter(node *root)
{
    vector<int> list;

    inOrderActualHelper(root, list);

    cout<<list.at(1);

    return list;
}



void inOrderRecursion(node *root)
{

    if (root == NULL)
    {
        return;
    }

    inOrderRecursion(root->left);
    cout << root->val << " ";
    inOrderRecursion(root->right);
}

int main()
{

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

    inOrderRecursion(root);


    // inOrderHelperStarter(root);

    // inOrderGeneral(root);

    // cout<<start.at(0)<<" "<<start.at(1)<<" "<<start.at(2);

    return 0;
}