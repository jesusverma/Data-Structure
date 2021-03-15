#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int data){
        this->data = data;
        left=right=NULL;
    }
};


bool isMirror(struct Node *node1,struct Node *node2){
    if(node1 == NULL && node2 == NULL) return true;

    if(node1 && node2 && node1->data == node2->data){
        return isMirror(node1->left,node2->right) &&  isMirror(node1->right,node2->left);
    }

    return false;
}

bool isSymmetric(struct Node *rootNode){
  return isMirror(rootNode,rootNode);
}


int main(){
    Node *root= new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout<<"Checking for symmetirci \n";
    bool isMirror = isSymmetric(root);

    cout<<"\n Tree is " << isMirror;
}