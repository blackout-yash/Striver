// 863. All Nodes Distance K in Binary Tree
// Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/



// Approach I
class Solution {
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		vector <int> ans;
		if (root == NULL) return ans;

		map <TreeNode*, TreeNode*> parent;
		queue <TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode* curr = q.front();
			q.pop();

			if (curr -> left != NULL) {
				q.push(curr -> left);
				parent[curr -> left] = curr;
			}
			if (curr -> right != NULL) {
				q.push(curr -> right);
				parent[curr -> right] = curr;
			}
		}

		map <TreeNode*, int> dis;
		q.push(target);
		dis[target] = 0;

		while (!q.empty()) {
			TreeNode* curr = q.front();
			q.pop();

			if (parent.count(curr) && !dis.count(parent[curr])) {
				q.push(parent[curr]);
				dis[parent[curr]] = 1 + dis[curr];
			}

			if (curr -> left != NULL && !dis.count(curr -> left)) {
				q.push(curr -> left);
				dis[curr -> left] = 1 + dis[curr];
			}

			if (curr -> right != NULL && !dis.count(curr -> right)) {
				q.push(curr -> right);
				dis[curr -> right] = 1 + dis[curr];
			}
		}

		for (auto x : dis) {
			if (x.second == k) ans.push_back(x.first -> val);
		}

		return ans;
	}
};




// Approach II
class Solution {
public:
	void insert(int a, int b, vector <vector <int>> &graph) {
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	void bfs(TreeNode* root, int par, vector <vector <int>> &graph) {
		if (root == NULL) return;

		int curr = root -> val;
		if (par != -1) insert(curr, par, graph);

		bfs(root -> left, curr, graph);
		bfs(root -> right, curr, graph);
	}

	void dfs(int root, vector <int> &dis, vector <vector <int>> &graph) {
		vector <int> vis(600);
		queue <int> q;
		q.push(root);
		dis[root] = 0;
		vis[root] = 1;

		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			for (auto x : graph[curr]) {
				if (vis[x]) continue;
				dis[x] = 1 + dis[curr];
				q.push(x);
				vis[x] = 1;
			}
		}
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		vector <int> ans;
		if (root == NULL) return ans;

		vector <vector <int>> graph(600);
		bfs(root, -1, graph);

		vector <int> dis(600, -1);
		dfs(target -> val, dis, graph);

		for (int i = 0; i < 600; i++) {
			if (dis[i] == k) ans.push_back(i);
		}

		return ans;
	}
};