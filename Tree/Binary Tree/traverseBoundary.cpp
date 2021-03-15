#include <iostream>
#include <stack>
#include <unordered_map>

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

void traverseOnlyLeft(Node *root)
{
    if (!root || !root->left)
        return;
    cout << root->data << "\n";
    traverseOnlyLeft(root->left);
}

void traverseOnlyRight(Node *root)
{
    if (!root || !root->right)
        return;
    cout << root->data << "\n";
    traverseOnlyRight(root->right);
}

void traverseOnlyLeave(Node *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        cout << root->data << "\n";
    traverseOnlyLeave(root->left);
    traverseOnlyLeave(root->right);
}

void boundaryTreeTraversal(Node *root)
{
    if (!root)
        return;
    traverseOnlyLeft(root);
    traverseOnlyLeave(root);
    traverseOnlyRight(root->right);
}

int main()
{

    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    boundaryTreeTraversal(root);
}