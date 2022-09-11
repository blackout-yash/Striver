// 22. Top View of Binary Tree
// Link - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1



class Solution {
public:
	vector<int> topView(Node *root) {
		vector <int> ans;
		if (root == NULL) return ans;

		map <int, int> m;
		queue <pair <Node*, int>> q;
		q.push({root, 0});

		while (!q.empty()) {
			auto curr = q.front();
			q.pop();

			Node *temp = curr.first;
			int index = curr.second;

			if (m.count(index)) m[index] = temp -> data;

			if (temp -> left != NULL) q.push({temp -> left, index - 1});
			if (temp -> right != NULL) q.push({temp -> right, index + 1});
		}

		for (auto x : m) ans.push_back(x.second);

		return ans;
	}
};