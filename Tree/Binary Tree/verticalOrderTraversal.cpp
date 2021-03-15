#include <iostream>
#include <stack>
#include <map>
#include <queue>

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

void printVerticalTraversal(Node *root)
{

    if (!root)
        return;

    multimap<int, int> map;

    queue<pair<Node *, int> > q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        Node *node = q.front().first;
        int dist = q.front().second;

        q.pop();

        map.insert(make_pair(dist, node->data));

        if (node->left)
            q.push(make_pair(node->left, dist - 1));

        if (node->right)
            q.push(make_pair(node->right, dist + 1));
    }

    //print the m ultimap

    int val = 0;
    // for (auto it = map.begin(); it != map.end(); it++)
    // // {
    // //     if (val != it->first)
    // //     {
    // //         cout << "\n";
    // //         val = it->first;
    // //     };
    // //     cout << it->second;
    // // }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->left->right->left = new Node(9);
    root->right->left->right->right = new Node(10);

    cout << "Subtree found in Master Tree \n";

    printVerticalTraversal(root);
}