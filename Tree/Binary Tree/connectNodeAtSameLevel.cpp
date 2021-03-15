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

Node *buildTree(char in[], char pre[], int st, int end, unordered_map<char, int> &map)
{
    static int preIndex = 0;

    if (st > end)
        return NULL;

    char curr = pre[preIndex++];

    Node *node = new Node(curr);

    if (st == end)
        return node;

    int inIndex = map[curr];

    node->left = buildTree(in, pre, st, inIndex - 1, map);
    node->right = buildTree(in, pre, st + 1, inIndex, map);

    return node;
};

Node *buldTreeWrap(char in[], char pre[], int len)
{
    unordered_map<char, int> map;

    for (int i = 0; i < len; i++)
    {
        map[in[i]] = i;
    }

    return buildTree(in, pre, 0, len - 1, map);
}

/* This funtcion is here just to test buildTree() */
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int size = *(&in + 1) - in;

    struct Node *root = buldTreeWrap(in, pre, size);

    printInorder(root);
}