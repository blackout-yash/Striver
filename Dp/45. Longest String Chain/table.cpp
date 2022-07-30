// 1048. Longest String Chain
// Link - https://leetcode.com/problems/longest-string-chain/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &s1, string &s2) {
	return s1.size() < s2.size();
}

class Solution {
public:
	int difference(string &a, string &b) {
		int ind1 = 0, ind2 = 0, cnt = 0;
		while (ind1 != size(a) || ind2 != size(b)) {
			if (ind1 == size(a)) {
				while (ind2 != size(b)) {
					cnt++; ind2++;
				}
			} else if (a[ind1] != b[ind2]) {
				ind1++; cnt++;
			} else {
				ind1++; ind2++;
			}
		} return cnt;
	}

	int longestStrChain(vector<string> &words) {
		int n = words.size();
		sort(words.begin(), words.end(), compare);

		int ans = 1;
		vector <int> dp(n, 1);
		for (int i = 0; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (difference(words[i], words[j]) == 1) {
					dp[i] = max(dp[i], 1 + dp[j]);
				}
			}
		}

		for (auto x : words) cout << x << " ";
		cout << endl;

		return *max_element(dp.begin(), dp.end());
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <string> words(n);
	for (auto &xx : words) cin >> xx;

	cout << sol.longestStrChain(words);

	return 0;
}