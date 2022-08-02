// 144. Binary Tree Preorder Traversal
// Link - https://leetcode.com/problems/binary-tree-preorder-traversal/



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

void preOrder(class Node *root) {
	if (root == NULL) return;

	cout << root -> val << " ";

	preOrder(root -> left);
	preOrder(root -> right);
}

int main() {
	class Node *root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	root -> left -> right = new Node(4);

	preOrder(root);

	return 0;
}