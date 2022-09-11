// 24. Right/Left View of Binary Tree
// Link - https://leetcode.com/problems/binary-tree-right-side-view/



// Approch I
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector <int> ans;
		if (root == NULL) return ans;

		queue <pair <TreeNode*, int>> q;
		q.push({root, 0});

		while (!q.empty()) {
			auto curr = q.front();
			q.pop();

			TreeNode* temp = curr.first;
			int level = curr.second;

			if (ans.size() == level) ans.push_back(temp -> val);

			if (temp -> right != NULL) q.push({temp -> right, level + 1});
			if (temp -> left != NULL) q.push({temp -> left, level + 1});
		}

		return ans;
	}
};




// Approach II
class Solution {
public:
	void rightSideView(TreeNode* root, int level, vector <int> &ans) {
		if (root == NULL) return;

		if (ans.size() == level) ans.push_back(root -> val);

		rightSideView(root -> right, level + 1, ans);
		rightSideView(root -> left, level + 1, ans);
	}

	vector<int> rightSideView(TreeNode* root) {
		vector <int> ans;
		if (root == NULL) return ans;

		rightSideView(root, 0, ans);

		return ans;
	}
};