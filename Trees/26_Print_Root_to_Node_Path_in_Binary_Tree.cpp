// 257. Binary Tree Paths
// Link - https://leetcode.com/problems/binary-tree-paths/



class Solution {
public:
	bool isLeaf(TreeNode* root) {
		if (root -> left == NULL && root -> right == NULL) return true;
		return false;
	}

	void binaryTreePaths(TreeNode* root, string s, vector <string> &ans) {
		if (root == NULL) return;

		if (s.empty()) s += to_string(root -> val);
		else s += "->" + to_string(root -> val);

		if (isLeaf(root)) {
			ans.push_back(s);
			return;
		}

		binaryTreePaths(root -> left, s, ans);
		binaryTreePaths(root -> right, s, ans);
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector <string> ans;
		if (root == NULL) return ans;

		string s;
		binaryTreePaths(root, s, ans);

		return ans;
	}
};