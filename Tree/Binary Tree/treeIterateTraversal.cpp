#include <iostream>
#include <stack>

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

void iterateTreeInOrderTraversal(Node *root)
{

    stack<Node *> s;
    Node *current = root;

    while (current != NULL || s.empty() == false)
    {
        while (current)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << "\n";

        current = current->right;
    }
}

void iterateTreePreOrderTraversal(Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {

        Node *temp = s.top();
        s.pop();

        cout << temp->data << "\n";

        if (temp->right)
        {
            s.push(temp->right);
        };

        if (temp->left)
        {
            s.push(temp->left);
        };
    }
}

void iterateTreePostOrderTraversal(Node *root)
{
    stack<Node *> s;
    s.push(root);

    stack<int> data;
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        data.push(temp->data);
        if (temp->right)
        {
            s.push(temp->right);
        };
        if (temp->left)
        {
            s.push(temp->left);
        };
    }

    while (!data.empty())
    {
        cout << data.top() << "\n";
        data.pop();
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->left->right = new Node(7);

    cout << "Subtree found in Master Tree \n";
    iterateTreeInOrderTraversal(root);

    iterateTreePreOrderTraversal(root);
    iterateTreePostOrderTraversal(root);
}