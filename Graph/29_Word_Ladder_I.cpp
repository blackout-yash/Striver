// 127. Word Ladder
// Link - https://leetcode.com/problems/word-ladder/



class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
		map <string, bool> isPresent;
		for (auto x : wordList) isPresent[x] = true;

		map <string, int> vis;
		queue <string> q;
		q.push(beginWord);
		vis[beginWord] = 1;

		while (!q.empty()) {
			string str = q.front();
			q.pop();

			if (str == endWord) return vis[endWord];

			for (int i = 0; i < str.size(); i++) {
				string temp = str;
				for (int j = 0; j < 26; j++) {
					char ch = temp[i];
					temp[i] = char('a' + j);
					if (isPresent.count(temp)) {
						if (!vis.count(temp)) {
							q.push(temp);
							vis[temp] = 1 + vis[str];
						}
					}
					temp[i] = ch;
				}
			}
		}

		return 0;
	}
};