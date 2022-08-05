// 987. Vertical Order Traversal of a Binary Tree
// Link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/



// Approach I
class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector <vector<int>> ans;
		if (root == NULL) return ans;

		map < int, map <int, multiset <int>>> store;
		queue < pair<TreeNode*, pair<int, int>>> q;
		q.push({root, {0, 0}});

		while (!q.empty()) {
			auto curr = q.front();
			q.pop();

			TreeNode *node = curr.first;
			int x = curr.second.first, y = curr.second.second;

			store[x][y].insert(node -> val);

			if (node -> left != NULL) q.push({node -> left, {x - 1, y + 1}});
			if (node -> right != NULL) q.push({node -> right, {x + 1, y + 1}});
		}

		for (auto x : store) {
			vector <int> level;
			for (auto y : x.second) {
				for (auto z : y.second) level.push_back(z);
			} ans.push_back(level);
		}

		return ans;
	}
};




// Approach II
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