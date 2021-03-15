#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int data){
        this->data = data;
        left= right = NULL;
    }
};


bool flag = true;

bool findIsTreeisSumTree(Node *root){

    if(!root)
         flag = false;

    if(!root->left && !root->right)
        return root->data;

    if(!flag) return flag;


    int l = findIsTreeisSumTree(root->left);
    int r = findIsTreeisSumTree(root->right);


    if(l+r != root->data) flag =0 ;

   return l + r + root->data;
}




int main(){


    Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    bool isTreeIsSumTree = findIsTreeisSumTree(root);
    cout << isTreeIsSumTree;
}