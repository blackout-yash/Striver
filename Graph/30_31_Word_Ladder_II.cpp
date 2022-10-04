// 126. Word Ladder II
// Link - https://leetcode.com/problems/word-ladder-ii/



class Solution {
public:
	void dfs(int root, int index, string &beginWord, vector <int> &temp, vector <vector<string>> &ans, vector<string> &wordList, vector<int> &level, vector<int> &vis, vector <vector<int>> &graph) {
		if (root == index) {
			vector <string> alpha = {beginWord};
			for (int i = temp.size() - 1; i >= 0; i--) alpha.push_back(wordList[temp[i] - 1]);
			ans.push_back(alpha);
			return;
		} else {
			vis[root] = 1;
			temp.push_back(root);
		}

		for (int child : graph[root]) {
			if (vis[child] || level[root] != 1 + level[child]) continue;
			if (vis[child]) continue;
			dfs(child, index, beginWord, temp, ans, wordList, level, vis, graph);
		}

		temp.pop_back();
		vis[root] = 0;
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
		int n = wordList.size();
		map <string, int> index;
		for (int i = 0; i < n; i++) index[wordList[i]] = i + 1;

		map<string, int> vis;
		queue <string> q;
		q.push(beginWord);
		vis[beginWord] = 1;

		vector <int> level(n + 1, 1e9);
		vector <vector<int>> graph(n + 1);
		level[index[beginWord]] = 0;
		while (!q.empty()) {
			string curr = q.front();
			q.pop();

			if (curr == endWord) break;

			for (int i = 0; i < curr.size(); i++) {
				string str = curr;
				for (int j = 0; j < 26; j++) {
					str[i] = char('a' + j);
					if (index.count(str) && str != curr) {
						if (!vis.count(str)) {
							q.push(str);
							vis[str] = 1 + vis[curr];
						}
						level[index[str]] = min(level[index[str]], 1 + level[index[curr]]);
						graph[index[str]].push_back(index[curr]);
					}
					str[i] = curr[i];
				}
			}
		}

		vector <vector<string>> ans;
		if (!index.count(endWord)) return ans;

		vector <int> temp, dvis(n + 1);
		dfs(index[endWord], index[beginWord], beginWord, temp, ans, wordList, level, dvis, graph);

		return ans;
	}
};