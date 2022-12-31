// Is Binary Tree Heap
// Link - https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1



class Solution {
public:
	int totalNode(Node* node) {
		if (node == NULL) return 0;

		return 1 + totalNode(node -> left) + totalNode(node -> right);
	}

	bool isComplete(int ind, int total, Node* node) {
		if (node == NULL) return true;

		if (ind > total) return false;
		return isComplete(2 * ind, total, node -> left) && isComplete((2 * ind) + 1, total, node -> right);
	}

	bool maxOrder(Node* node) {
		if (node == NULL) return true;
		else if ((node -> left) && (node -> data) <= (node -> left -> data)) return false;
		else if ((node -> right) && (node -> data) <= (node -> right -> data)) return false;

		return maxOrder(node -> left) && maxOrder(node -> right);
	}

	bool isHeap(struct Node* tree) {
		int total = totalNode(tree);
		return isComplete(1, total, tree) && maxOrder(tree);
	}
};