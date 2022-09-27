// Alien Dictionary
// Link - https://practice.geeksforgeeks.org/problems/alien-dictionary/1



class Solution {
public:
	int toInt(char ch) {
		int ans = ch - 'a';
		return ans;
	}

	char toChar(int num) {
		char ch = ('a' + num);
		return ch;
	}

	string findOrder(string dict[], int N, int K) {
		vector <vector<int>> graph(K);
		for (int i = 0; i < N - 1; i++) {
			int range = min(dict[i].size(), dict[i + 1].size());
			for (int j = 0; j < range; j++) {
				int num1 = toInt(dict[i][j]),
				    num2 = toInt(dict[i + 1][j]);
				if (num1 != num2) {
					graph[num1].push_back(num2);
					break;
				}
			}
		}

		vector <int> inorder(K);
		for (int i = 0; i < K; i++) {
			for (int child : graph[i]) inorder[child]++;
		}

		queue <int> q;
		for (int i = 0; i < K; i++) {
			if (inorder[i]) continue;
			q.push(i);
		}

		string ans;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			ans.push_back(toChar(curr));

			for (int child : graph[curr]) {
				inorder[child]--;
				if (!inorder[child]) q.push(child);
			}
		}

		return ans;
	}
};