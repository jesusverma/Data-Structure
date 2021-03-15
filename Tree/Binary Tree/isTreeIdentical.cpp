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

bool isTreesEqual(Node *root1, Node *root2)
{

    if (!root1 && !root2)
        return true;

    if (root1 && root2)
        return root1->data == root2->data && isTreesEqual(root1->left, root2->left) && isTreesEqual(root1->right, root2->right);
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(9);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    root1->right->left = new Node(5);
    root1->right->right = new Node(7);
    cout << "Height of tree is " << isTreesEqual(root, root1);
}