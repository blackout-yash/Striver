// 72. Edit Distance
// Link - https://leetcode.com/problems/edit-distance/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (min(n, m) == 0) return max(n, m);

        vector <int> dp(m);
        for (int i = 0; i < n; i++) {

            vector <int> curr(m);
            for (int j = 0; j < m; j++) {

                int ans1 = (word1[i] != word2[j]);
                if (i && j) ans1 += dp[j - 1];
                else ans1 += (i + j);

                int ans2 = (j + 1) + 1;
                if (i) ans2 = 1 + dp[j];

                int ans3 = (i + 1) + 1;
                if (j) ans3 = 1 + curr[j - 1];

                curr[j] = min({ans1, ans2, ans3});
            }

            for (int j = 0; j < m; j++) dp[j] = curr[j];
        }

        return dp[m - 1];
    }
};

int main() {
    Solution sol;

    string word1, word2;
    cin >> word1 >> word2;

    cout << sol.minDistance(word1, word2);

    return 0;
}