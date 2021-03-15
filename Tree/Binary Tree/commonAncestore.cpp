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

Node *findLowestCommonAncesstor(Node *root, int n1, int n2)
{

    if (!root)
        return NULL;

    if (root->data == n1 || root->data == n2)
    {
        return root;
    };

    Node *left_lca = findLowestCommonAncesstor(root->left, n1, n2);
    Node *right_lca = findLowestCommonAncesstor(root->right, n1, n2);

    if (left_lca && right_lca)
        return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *node = findLowestCommonAncesstor(root, 4, 5);
    cout << node->data;
}