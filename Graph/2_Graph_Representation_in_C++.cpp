// Print adjacency list
// Link - https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1



class Solution {
public:
	vector<vector<int>> printGraph(int V, vector<int> adj[]) {
		vector <vector <int>> graph;
		for (int i = 0; i < V; i++) {
			vector <int> temp;
			temp.push_back(i);
			for (int j = 0; j < adj[i].size(); j++) {
				temp.push_back(adj[i][j]);
			}
			graph.push_back(temp);
		}
		return graph;
	}
};