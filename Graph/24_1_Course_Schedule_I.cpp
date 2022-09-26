// 207. Course Schedule
// Link - https://leetcode.com/problems/course-schedule/



// BFS
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		vector <int> inorder(numCourses);
		vector <vector <int>> graph(numCourses);
		for (auto x : prerequisites) graph[x[0]].push_back(x[1]);

		for (int i = 0; i < numCourses; i++) {
			for (int child : graph[i]) inorder[child]++;
		}

		queue <int> q;
		for (int i = 0; i < numCourses; i++) {
			if (inorder[i]) continue;
			q.push(i);
		}

		int cnt = 0;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			cnt++;

			for (int child : graph[curr]) {
				inorder[child]--;
				if (!inorder[child]) q.push(child);
			}
		}

		return cnt == numCourses;
	}
};


// DFS
class Solution {
public:
	bool isCycle(int root, vector <int> &vis, vector <int> &path, vector <vector <int>> &graph) {
		vis[root] = path[root] = 1;
		for (int child : graph[root]) {
			if (vis[child]) {
				if (path[child]) return true;
				continue;
			}
			if (isCycle(child, vis, path, graph)) return true;
		}
		path[root] = 0;
		return false;
	}

	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		vector <vector <int>> graph(numCourses);
		vector <int> vis(numCourses), path(numCourses);

		for (auto x : prerequisites) graph[x[0]].push_back(x[1]);

		for (int i = 0; i < numCourses; i++) {
			if (vis[i]) continue;
			else if (isCycle(i, vis, path, graph)) return false;
		}

		return true;
	}
};