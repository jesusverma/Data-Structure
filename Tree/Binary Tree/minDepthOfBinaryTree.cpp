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

int findMinDepth(Node *root)
{

    if (!root)
        return 0;

    return min(findMinDepth(root->left), findMinDepth(root->right)) + 1;
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

    cout << "Minium depth of tree is" << findMinDepth(root);
}