// Largest BST
// Link - https://practice.geeksforgeeks.org/problems/largest-bst/1



class NodeVal {
public:
	int minNode, maxNode, size;

	NodeVal (int minNode, int maxNode, int size) {
		this -> minNode = minNode;
		this -> maxNode = maxNode;
		this -> size = size;
	}
};

class Solution {
public:
	NodeVal largestBstUtil(Node *root) {
		if (root == NULL) return NodeVal(INT_MAX, INT_MIN, 0);

		auto left = largestBstUtil(root -> left);
		auto right = largestBstUtil(root -> right);

		if (left.maxNode < root -> data && root -> data < right.minNode) {
			return NodeVal(min(root -> data, left.minNode), max(root -> data, right.maxNode), left.size + 1 + right.size);
		}

		return NodeVal(INT_MIN, INT_MAX, max(left.size, right.size));
	}

	int largestBst(Node *root) {
		return largestBstUtil(root).size;
	}
};