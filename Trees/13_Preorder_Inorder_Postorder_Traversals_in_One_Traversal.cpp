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

void preInPostOrder(Node *root) {
    if (root == NULL) return;

    vector <int> pre, in, post;

    stack <pair<Node*, int>> s;
    s.push({root, 1});

    while (!s.empty()) {
        auto it = s.top();
        s.pop();

        if (it.second == 1) {
            pre.push_back(it.first -> val);
            it.second++;
            s.push(it);

            if (it.first -> left != NULL) {
                s.push({it.first -> left, 1});
            }
        }

        else if (it.second == 2) {
            in.push_back(it.first -> val);
            it.second++;
            s.push(it);

            if (it.first -> right != NULL) {
                s.push({it.first -> right, 1});
            }
        }

        else {
            post.push_back(it.first -> val);
        }
    }

    cout << "Pre: ";
    for (auto x : pre) cout << x << " ";
    cout << endl;

    cout << "In: ";
    for (auto x : in) cout << x << " ";
    cout << endl;

    cout << "postOrder: ";
    for (auto x : post) cout << x << " ";
}

int main() {
    class Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> right = new Node(4);

    preInPostOrder(root);

    return 0;
}