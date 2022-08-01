// 85. Maximal Rectangle
// Link - https://leetcode.com/problems/maximal-rectangle/



#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &heights) {
		int n = heights.size(), ans = 0;

		stack <int> s;
		for (int i = 0; i <= n; i++) {
			while (!s.empty()) {
				if (i == n || heights[s.top()] > heights[i]) {

					int height = heights[s.top()], width;
					s.pop();

					if (s.empty()) width = i;
					else width = (i - s.top()) - 1;

					ans = max(ans, height * width);
				} else break;
			} s.push(i);
		}

		return ans;
	}

	int maximalRectangle(vector<vector<char>> &matrix) {

		int n = matrix.size(), m = matrix[0].size();
		vector <int> value(m);

		int ans = 0;
		for (int i = 0; i < n; i++) {
			vector <int> curr = value;
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == '1') curr[j]++;
				else curr[j] = 0;
			} value = curr;
			ans = max(ans, largestRectangleArea(value));
		}
		return ans;
	}
};

int main() {
	Solution sol;

	int n, m;
	cin >> n >> m;

	vector <vector<char>> matrix(n, vector<char> (m));
	for (auto &x : matrix) {
		for (auto &y : x) cin >> y;
	}

	cout << sol.maximalRectangle(matrix);

	return 0;
}
