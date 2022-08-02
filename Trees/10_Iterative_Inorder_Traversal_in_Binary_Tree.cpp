// 94. Binary Tree Inorder Traversal
// Link - https://leetcode.com/problems/binary-tree-inorder-traversal/



#include <iostream>
#include <vector>
#include <stack>


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

vector<int> inOrder(Node *root) {
    vector <int> ans;
    if (root == NULL) return ans;

    stack <Node*> s;
    Node *node = root;

    while (true) {
        if (node != NULL) {
            s.push(node);
            node = node -> left;
        } else {
            if (s.empty()) break;

            node = s.top();
            s.pop();

            ans.push_back(node -> val);
            node = node -> right;
        }
    }
    return ans;
}

int main() {
    class Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);

    vector <int> ans = inOrder(root);

    for (auto x : ans) cout << x << " ";

    return 0;
}