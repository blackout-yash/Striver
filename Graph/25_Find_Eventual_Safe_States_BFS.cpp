// 802. Find Eventual Safe States
// Link - https://leetcode.com/problems/find-eventual-safe-states/



class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
		int n = graph.size();
		vector <vector <int>> rgraph(n);
		for (int i = 0; i < n; i++) {
			for (auto child : graph[i]) rgraph[child].push_back(i);
		}

		vector <int> inorder(n), ans;
		for (int i = 0; i < n; i++) {
			for (int child : rgraph[i]) inorder[child]++;
		}

		queue <int> q;
		for (int i = 0; i < n; i++) {
			if (inorder[i]) continue;
			q.push(i);
		}

		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			ans.push_back(curr);

			for (int child : rgraph[curr]) {
				inorder[child]--;
				if (!inorder[child]) q.push(child);
			}
		} sort(ans.begin(), ans.end());

		return ans;
	}
};