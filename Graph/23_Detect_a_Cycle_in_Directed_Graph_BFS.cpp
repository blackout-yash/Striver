// Detect cycle in a directed graph
// Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1



class Solution {
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		vector <int> inorder(V);
		for (int i = 0; i < V; i++) {
			for (int child : adj[i]) inorder[child]++;
		}

		queue <int> q;
		for (int i = 0; i < V; i++) {
			if (inorder[i]) continue;
			q.push(i);
		}

		int cnt = 0;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			cnt++;

			for (int child : adj[curr]) {
				inorder[child]--;
				if (!inorder[child]) q.push(child);
			}
		}

		return cnt != V;
	}
};