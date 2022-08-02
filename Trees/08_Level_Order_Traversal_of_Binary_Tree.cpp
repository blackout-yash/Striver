// 102. Binary Tree Level Order Traversal
// Link - https://leetcode.com/problems/binary-tree-level-order-traversal/



#include <iostream>
#include <vector>
#include <queue>


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

vector<vector<int>> levelOrder(Node *root) {
    vector <vector<int>> ans;
    if (root == NULL) return ans;

    queue <Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        vector <int> level;
        for (int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop();

            if (node -> left != NULL) q.push(node -> left);
            if (node -> right != NULL) q.push(node -> right);

            level.push_back(node -> val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    class Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);

    vector <vector<int>> ans = levelOrder(root);

    for (auto x : ans) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }

    return 0;
}