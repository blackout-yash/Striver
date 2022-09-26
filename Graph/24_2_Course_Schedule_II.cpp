// 210. Course Schedule II
// Link - https://leetcode.com/problems/course-schedule-ii/



class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
		vector <vector <int>> graph(numCourses);
		vector <int> inorder(numCourses), ans;
		for (auto x : prerequisites) graph[x[0]].push_back(x[1]);

		for (int i = 0; i < numCourses; i++) {
			for (int child : graph[i]) inorder[child]++;
		}

		queue <int> q;
		for (int i = 0; i < numCourses; i++) {
			if (inorder[i]) continue;
			q.push(i);
		}

		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			ans.push_back(curr);

			for (int child : graph[curr]) {
				inorder[child]--;
				if (!inorder[child]) q.push(child);
			}
		}

		if (ans.size() != numCourses) ans.clear();
		else reverse(ans.begin(), ans.end());

		return ans;
	}
};