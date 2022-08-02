// 144. Binary Tree Preorder Traversal
// Link - https://leetcode.com/problems/binary-tree-preorder-traversal/



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

vector<int> preOrder(Node *root) {
    vector <int> ans;
    if (root == NULL) return ans;

    stack <Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node *node = s.top();
        s.pop();

        if (node -> right != NULL) s.push(node -> right);
        if (node -> left != NULL) s.push(node -> left);

        ans.push_back(node -> val);
    }
    return ans;
}

int main() {
    class Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);

    vector <int> ans = preOrder(root);

    for (auto x : ans) cout << x << " ";

    return 0;
}