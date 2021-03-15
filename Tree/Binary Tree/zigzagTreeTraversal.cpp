#include <iostream>
#include <stack> // std::stack

using namespace std;

struct Node
{
    Node *left, *right;
    int data;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void traverseZigZag(Node *root)
{

    if (!root)
        return;

    stack<struct Node *> currentLevel;
    stack<struct Node *> nextLevel;

    currentLevel.push(root);
    bool leftToRight = true;

    while (!currentLevel.empty())
    {
        struct Node *temp = currentLevel.top();
        currentLevel.pop();

        if (temp)
        {
            cout << temp->data << "\n";

            if (leftToRight)
            {
                if (temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }
        }

        if (currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
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
    root->right->right = new Node(7);

    cout << "Traversinig zigzag \n";
    traverseZigZag(root);
}