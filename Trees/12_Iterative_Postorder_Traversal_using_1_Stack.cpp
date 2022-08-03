// 145. Binary Tree Postorder Traversal
// Link - https://leetcode.com/problems/binary-tree-postorder-traversal/



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

vector<int> postOrder(Node *root) {
    vector <int> ans;
    if (root == NULL) return ans;

    stack <Node*> s;
    s.push(root);

    Node *node = root -> left;
    while (node != NULL || !s.empty()) {
        if (node != NULL) {
            s.push(node);
            node = node -> left;
        } else {
            Node *temp = s.top() -> right;

            if (temp == NULL) {
                temp = s.top();
                s.pop();
                ans.push_back(temp -> val);

                while (!s.empty() && temp == s.top() -> right) {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp -> val);
                }

            } else node = temp;
        }
    }

    return ans;
}

int main() {
    class Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);

    vector <int> ans = postOrder(root);

    for (auto x : ans) cout << x << " ";

    return 0;
}