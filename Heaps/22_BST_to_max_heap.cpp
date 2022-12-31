// BST to max heap
// Link - https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1



class Solution {
public:
	void inorder(Node* root, vector <int> &path) {
		if (root == NULL) return;

		inorder(root -> left, path);
		path.push_back(root -> data);
		inorder(root -> right, path);
	}

	void convertToMaxHeap(Node* root, int &ind, vector <int> &inorder) {
		if (root == NULL) return;

		root -> data = inorder[ind--];
		convertToMaxHeap(root -> right, ind, inorder);
		convertToMaxHeap(root -> left, ind, inorder);
	}

	void convertToMaxHeapUtil(Node* root) {
		vector <int> path;
		inorder(root, path);
		int n = path.size() - 1;
		convertToMaxHeap(root, n, path);
	}
};