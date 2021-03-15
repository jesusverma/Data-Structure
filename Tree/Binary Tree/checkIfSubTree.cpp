#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

bool isTreeIdentical(Node *masterTreeRoot, Node *subTreeRoot)
{

    if (!masterTreeRoot && !subTreeRoot)
        return true;

    if (!masterTreeRoot || !subTreeRoot)
        return false;

    return masterTreeRoot->data == subTreeRoot->data && isTreeIdentical(masterTreeRoot->left, subTreeRoot->left) && isTreeIdentical(masterTreeRoot->right, subTreeRoot->right);
};

bool isSubTree(Node *T, Node *S)
{

    if (!S)
        return true;

    if (!T)
        return false;

    if (isTreeIdentical(T, S))
        return true;

    return isSubTree(T->left, S) || isSubTree(T->right, S);
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->left->right = new Node(7);

    Node *root1 = new Node(5);
    root1->right = new Node(7);

    cout << "Subtree found in Master Tree  " << isSubTree(root, root1);
}