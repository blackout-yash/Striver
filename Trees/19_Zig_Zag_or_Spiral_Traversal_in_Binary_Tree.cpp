// 103. Binary Tree Zigzag Level Order Traversal
// Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/



class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL) return ans;

		queue <TreeNode*> q;
		q.push(root);

		int rightTOLeft = 0;
		while (!q.empty()) {
			int size = q.size();
			vector <int> level(size);

			for (int i = 0; i < size; i++) {
				TreeNode *node = q.front();
				q.pop();

				if (node -> left != NULL) q.push(node -> left);
				if (node -> right != NULL) q.push(node -> right);

				int index = (rightTOLeft) ? size - i - 1 : i;
				level[index] = node -> val;
			}

			rightTOLeft = !rightTOLeft;
			ans.push_back(level);
		} return ans;
	}
};