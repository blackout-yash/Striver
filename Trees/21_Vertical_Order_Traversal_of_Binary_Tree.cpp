// 987. Vertical Order Traversal of a Binary Tree
// Link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/



// Approach I
class Solution {
public:
	void verticalTraversal(int col, int row, TreeNode *root, vector <pair<pair<int, int>, int>> &store) {
		if (root == NULL) return;
		else store.push_back({{col, row}, root -> val});

		verticalTraversal(col - 1, row + 1, root -> left, store);
		verticalTraversal(col + 1, row + 1, root -> right, store);
	}

	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector <vector<int>> ans;
		if (root == NULL) return ans;

		vector <pair<pair<int, int>, int>> store;
		verticalTraversal(0, 0, root, store);
		sort(store.begin(), store.end());

		vector <int> level;
		int j = store[0].first.first, n = store.size();
		for (int i = 0; i < n; i++) {
			level.push_back(store[i].second);
			if (i + 1 == n || j != store[i + 1].first.first) {
				ans.push_back(level);
				level.clear(); j++;
			}
		}
		return ans;
	}
};