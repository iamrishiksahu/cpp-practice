#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int data)
    {

        this->data = data;
        left = right = NULL;
    }
};

void deleteNode(TreeNode *root, int key)
{

    TreeNode *prev;

    while (root != NULL)
    {

        cout << endl
             << "current : " << root->data;

        if (key == root->data)
        {
            // mil gaya bacha delete karo ab isko
            delete prev;
            cout << endl
                 << root->data << " deleted successfully!";
            return;
        }
        else if (key > root->data)
        {
            prev = root;
            root = root->right;
        }
        else
        {
            prev = root;
            root = root->left;
        }
    }

    cout << "Given element was not found in the tree";
    return;
}

void inOrderRecursion(TreeNode *root)
{

    if (root == NULL)
    {
        return;
    }

    inOrderRecursion(root->left);
    cout << root->data << " ";
    inOrderRecursion(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(9);
    TreeNode *p1 = new TreeNode(6);
    TreeNode *p2 = new TreeNode(12);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(5);

    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;

    /**
     *       GIVEN TREE
     *
     *           9
     *          / \
     *         6   12
     *        / \
     *       3   5
     *
     */

    inOrderRecursion(root);

    cout << endl
         << endl;

    deleteNode(root, 3);

    cout<<"aage ka line";
    inOrderRecursion(root);


    return 0;
}