// 145. Binary Tree Postorder Traversal
// Link - https://leetcode.com/problems/binary-tree-postorder-traversal/



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

void postOrder(class Node *root) {
    if (root == NULL) return;

    postOrder(root -> left);
    postOrder(root -> right);

    cout << root -> val << " ";
}

int main() {
    class Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);

    postOrder(root);

    return 0;
}