// Shortest Distance in a Binary Maze
// Ḷink - https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1



class Solution {
public:
	vector <vector <int>> movements = {
		{ -1, 0}, {0, -1}, {0, 1}, {1, 0}
	};

	bool isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
		int n = grid.size(), m = grid[0].size();
		vector <vector<int>> dist(n, vector<int> (m, 1e9));
		dist[source.first][source.second] = 0;

		queue <pair<int, pair<int, int>>> pq;
		pq.push({0, source});

		while (!pq.empty()) {
			int wt = pq.front().first,
			    x = pq.front().second.first,
			    y = pq.front().second.second;
			pq.pop();

			for (auto it : movements) {
				int currX = x + it[0],
				    currY = y + it[1];
				if (isValid(currX, currY, n, m) && grid[currX][currY]) {
					if (1 + wt < dist[currX][currY]) {
						dist[currX][currY] = 1 + wt;
						pq.push({dist[currX][currY], {currX, currY}});
					}
				}
			}
		}

		int x = destination.first, y = destination.second;
		if (dist[x][y] == 1e9) return -1;
		return dist[x][y];
	}
};