// Topological sort
// Link - https://practice.geeksforgeeks.org/problems/topological-sort/1



class Solution {
public:
	vector<int> topoSort(int V, vector<int> adj[]) {
		vector <int> inorder(V);
		for (int i = 0; i < V; i++) {
			for (int child : adj[i]) inorder[child]++;
		}

		queue <int> q;
		for (int i = 0; i < V; i++) {
			if (inorder[i]) continue;
			q.push(i);
		}

		vector <int> ans;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			ans.push_back(curr);

			for (int child : adj[curr]) {
				inorder[child]--;
				if (!inorder[child]) q.push(child);
			}
		}

		return ans;
	}
};