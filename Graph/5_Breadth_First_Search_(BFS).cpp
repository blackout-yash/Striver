// BFS of graph
// Link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1



class Solution {
public:
	// Function to return Breadth First Traversal of given graph.
	vector<int> bfsOfGraph(int v, vector<int> adj[]) {
		int vis[v] = {0};
		queue <int> q;
		q.push(0);
		vis[0] = 1;

		vector <int> bfs;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			bfs.push_back(curr);

			for (int child : adj[curr]) {
				if (vis[child]) continue;
				q.push(child);
				vis[child] = 1;
			}
		}
		return bfs;
	}
};