#include <iostream>

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

node *search(node *root, int key)
{
    if (root == NULL)
    {
        // EMPTY TREE
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}

node *searchI(node *root, int key)
{

    while (root != NULL)
    {

        if (root->data == key)
        {
            return root;
        }

        else if (root->data < key)
        {
            root = root->right;
        }

        else
        {
            root = root->left;
        }
    } 
}

void inOrder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);

    cout << root->data << " ";

    inOrder(root->right);
}

int main()
{

    node *root = new node(6);
    node *p1 = new node(4);
    node *p2 = new node(7);
    node *p3 = new node(3);
    node *p4 = new node(5);

    /**
     *       GIVEN TREE
     *
     *           6
     *          / \
     *         4   7
     *        / \
     *       3   5
    p1->right = p4;
     *
     */

    root->left = p1;
    root->right = p2;

    p1->left = p3;

    inOrder(root);
    cout << endl
         << endl;

    node *result = searchI(root, 7);
    if (result)
        cout << result->data;

    else
        cout << "element not found";

    return 0;
}