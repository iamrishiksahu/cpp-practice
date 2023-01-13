#include <bits/stdc++.h>

using namespace std;
template <typename T> class TreeNode {

    public:
    T data;
    TreeNode * left;
    TreeNode * right;

    TreeNode(T data){
        this->data = data;
        left = right = NULL;
    }
};


int main()
{

    TreeNode<int> *root = new TreeNode<int>(2);
    root->left = new TreeNode<int>(3);

    vector<int> sizeV;
    sizeV.resize(10);

    
    fill(sizeV.begin(), sizeV.end(), 3);
    sizeV.push_back(4);

    cout<<sizeV.at(10);






    return 0;
}
