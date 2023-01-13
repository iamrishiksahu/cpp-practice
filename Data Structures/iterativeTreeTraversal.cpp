#include<bits/stdc++.h>

using namespace std;

template <typename T> class TreeNode {

    public:

    T data;
    TreeNode *left, *right;

    TreeNode(int data){

        this->data = data;
        left = right = NULL;
        
    }
};

vector<int> preorderstatictrick (TreeNode<int> *root){

    static vector<int> res;

    if(root == NULL) return {};

    res.push_back(root->data);
    preorderstatictrick(root->left);
    preorderstatictrick(root->right);

    return res;

}

vector<int> preorderTraversal (TreeNode<int> *root){
    vector<int> res;

    if(root == NULL) return res;

    stack<TreeNode<int>*> st;

    st.push(root);

    while(!st.empty()){

        TreeNode<int> *t = st.top();
        st.pop();
        res.push_back(t->data);

        if(t->right !=NULL){
            st.push(t->right);
        }
        if(t->left !=NULL){
            st.push(t->left);
        }
    }

    return res;

    
}


vector<int> postorderTraversal (TreeNode<int> *root){
    vector<int> res;

    if(root == NULL) return res;

    stack<TreeNode<int>*> s1;
    stack<int> s2;

    s1.push(root);

    while(!s1.empty()){

        TreeNode<int> *t = s1.top();

        s1.pop();
        s2.push(t->data);

        if(t->right != NULL) s1.push(t->right);
        if(t->left != NULL) s1.push(t->left);
        
    }

    while(!s2.empty()){
        res.push_back(s2.top());

        s2.pop();
    }


    return res;
}


vector<int> inorderTraversal (TreeNode<int> *root){
    vector<int> res;

    if(root == NULL) return res;

    stack<TreeNode<int>*> st;
    TreeNode<int> *curr = root;

    while(!st.empty() || curr != NULL){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }

        //above while loop will terminate on curr == NULL

        curr = st.top();
        st.pop();

        res.push_back(curr->data);
        curr = curr->right;
    }


    return res;
}


int main(){


    TreeNode<int> *root = new TreeNode<int> (4);
    root->left = new TreeNode<int> (3);
    root->right = new TreeNode<int> (2);

    vector<int> pre = preorderTraversal(root);
    vector<int> pos = postorderTraversal(root);
    vector<int> ino = inorderTraversal(root);
    vector<int> prestatic = preorderstatictrick(root);

    for(int c : pre) cout<<c << " ";

    

    return 0;

}