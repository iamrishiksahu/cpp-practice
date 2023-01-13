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

void insertInBst(TreeNode *root, int key)
{

    TreeNode *prev;

    while (root != NULL)
    {
        prev = root;

        if (root->data == key)
        {
            cout << "Sorry, " << key << " is already present and cannot be inserted in this BST";
            return;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    TreeNode *toIns = new TreeNode(key);

    if (key < prev->data)
        prev->left = toIns,
        cout << "Node inserted successfully at the left of " << prev->data<<endl;
    else
        prev->right = toIns,
        cout << "Node inserted successfully at the right of " << prev->data<<endl;
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
    cout<<endl<<endl;

    insertInBst(root, 1);
    insertInBst(root, 4);
    cout<<endl<<endl;

    inOrderRecursion(root);

    return 0;
}