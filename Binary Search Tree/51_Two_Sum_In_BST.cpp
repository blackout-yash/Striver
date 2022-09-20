// 653. Two Sum IV - Input is a BST
// Link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/



class BITIterator {
public:
	bool reverse;
	stack <TreeNode*> s;

	BITIterator(TreeNode* root, bool isReverse) {
		reverse = isReverse;
		pushAll(root);
	}

	int next() {
		TreeNode* curr = s.top();
		s.pop();

		if (reverse) pushAll(curr -> left);
		else pushAll(curr -> right);

		return curr -> val;
	}

	void pushAll(TreeNode* root) {
		while (root != NULL) {
			s.push(root);
			if (reverse) root = root -> right;
			else root = root -> left;
		}
	}
};

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		if (root == NULL) return false;

		BITIterator l = BITIterator(root, false);
		BITIterator r = BITIterator(root, true);

		int i = l.next(), j = r.next();
		while (i < j) {
			if (i + j == k) return true;
			else if (i + j > k) j = r.next();
			else i = l.next();
		}
		return false;
	}
};