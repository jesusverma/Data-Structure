#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int data){
        this->data = data;
        left= right = NULL;
    }
};

int getHeightofTrrr(Node *root){

    if(!root) return 0;

    return max(getHeightofTrrr(root->left) ,getHeightofTrrr(root->right) ) + 1;

};

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    cout<< "Height of tree is" << getHeightofTrrr(root);
}