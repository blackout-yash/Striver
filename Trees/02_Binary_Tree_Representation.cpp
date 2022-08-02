#include <iostream>

using namespace std;

class Node {
public:
    int data;
    class Node *left;
    class Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int main() {
    class Node *root = new Node(1);

    root -> left = new Node(2);
    root -> left = new Node(3);

    root -> left -> right = new Node(4);

    return 0;
}