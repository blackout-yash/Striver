// 173. Binary Search Tree Iterator
// Link - https://leetcode.com/problems/binary-search-tree-iterator/



class BSTIterator {
public:
	stack<TreeNode *> s;

	BSTIterator(TreeNode *root) {
		pushAll(root);
	}

	bool hasNext() {
		return !s.empty();
	}

	int next() {
		TreeNode* curr = s.top();
		s.pop();

		pushAll(curr -> right);

		return curr -> val;
	}

	void pushAll(TreeNode *root) {
		while (root != NULL) {
			s.push(root);
			root = root -> left;
		}
	}
};