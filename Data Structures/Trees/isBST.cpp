#include<iostream>

using namespace std;


class node{

    public:

    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

bool isBst(node *root){

    static node *prev = NULL;   //important making this static.

    //STATIC ensures that each stack doesn't have their own prev variable.
    //otherwise each stack will store different value for prev and the value
    //will not be updated.

    if(root == NULL){
        return 1;
    }else{

        //checking the left subtree
        if(!isBst(root->left)){
            return 0;
        }

        //analyzing the current root

        if(prev != NULL && root->data <= prev->data){
            return 0;
        }

        prev = root;

        //checking the right subtree
        return isBst(root->right);
    }

    /**
     * This is basically an inorder tranveral with checking
     * the element returned is greater than the previous element
     * or not. If it is greater than the previous element,
     * this will produces a strictly ascending set of values
     * which represents a binary search tree.
    */

}

void inOrder(node *root){

    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";

    inOrder(root->right);


}

int main(){

    node *root = new node(6);
    node *p1 = new node(4);
    node *p2 = new node(1);
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
    * 
   */


    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;

    inOrder(root);
    cout<<endl<<endl;

    cout<<isBst(root);

    return 0;
}