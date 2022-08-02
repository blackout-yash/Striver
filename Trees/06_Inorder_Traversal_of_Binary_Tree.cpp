// 94. Binary Tree Inorder Traversal
// Link - https://leetcode.com/problems/binary-tree-inorder-traversal/



#include <iostream>

using namespace std;

class Node {
public:
    int val;
    class Node *left;
    class Node *right;

    Node(int data) {
        val = data;
        left = right = NULL;
    }
};

void inOrder(class Node *root) {
    if (root == NULL) return;

    inOrder(root -> left);

    cout << root -> val << " ";

    inOrder(root -> right);
}

int main() {
    class Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);

    inOrder(root);

    return 0;
}