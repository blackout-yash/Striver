// 32. Boolean Evaluation
// Link - https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650



#include <iostream>
#include <vector>

using namespace std;
#define ll long long
int mod = 1e9 + 7;

class Solution {
public:
	int expression(char ch, int n, int m) {
		if (ch == '&') return (n & m);
		else if (ch == '|') return (n | m);
		return (n ^ m);
	}

	int evaluateExp(int i, int j, int set, string &exp, vector <vector<vector <ll>>> &dp) {
		if (i == j) {
			if (exp[i] == 'T') return (set == 1);
			else return (set == 0);
		} else if (dp[i][j][set] != -1) return dp[i][j][set];

		ll ans = 0;
		vector <ll> left(2), right(2);
		for (int k = i + 1; k < j; k += 2) {
			left[0] = evaluateExp(i, k - 1, 0, exp, dp);
			left[1] = evaluateExp(i, k - 1, 1, exp, dp);

			right[0] = evaluateExp(k + 1, j, 0, exp, dp);
			right[1] = evaluateExp(k + 1, j, 1, exp, dp);

			for (int ind1 = 0; ind1 < 2; ind1++) {
				for (int ind2 = 0; ind2 < 2; ind2++) {
					if (expression(exp[k], ind1, ind2) == set) ans = (ans + ((left[ind1] * right[ind2]) % mod)) % mod;
				}
			}
		} return dp[i][j][set] = ans;
	}

	int evaluateExp(string &exp) {
		int n = exp.size();
		vector <vector<vector <ll>>> dp(n + 2, vector<vector <ll>> (n + 2, vector <ll> (2, -1)));

		exp.push_back('&'); exp.push_back('T');
		exp.insert(exp.begin(), '&'); exp.insert(exp.begin(), 'T');

		int ans = evaluateExp(2, n + 1, 1, exp, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	string exp;
	cin >> exp;

	cout << sol.evaluateExp(exp);

	return 0;
}