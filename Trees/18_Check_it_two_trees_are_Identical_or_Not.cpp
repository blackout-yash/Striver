// 100. Same Tree
// Link - https://leetcode.com/problems/same-tree/



class Solution {
public:
	bool isSameTreeUtil(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return 1;
		else if (p == NULL && q != NULL) return 0;
		else if (p != NULL && q == NULL) return 0;
		else if (p -> val != q -> val) return 0;

		bool ans1 = isSameTreeUtil(p -> left, q -> left);
		bool ans2 = isSameTreeUtil(p -> right, q -> right);

		return (ans1 && ans2);
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		bool ans = isSameTreeUtil(p, q);

		return ans;
	}
};