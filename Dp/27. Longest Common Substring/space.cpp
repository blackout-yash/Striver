// 29. Longest Common Substring
// Link - https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lcs(string &str1, string &str2) {
        int n = str1.size(), m = str2.size(), ans = 0;

        vector <int> dp(m + 1);
        for (int i = 0; i < n; i++) {

            vector <int> curr(m + 1);
            for (int j = 0; j < m; j++) {
                if (str1[i] == str2[j]) {
                    int temp = 0;
                    if (i && j) temp = dp[j - 1];

                    ans = max(ans, 1 + temp);
                    curr[j] = 1 + temp;
                }
            }

            for (int j = 0; j < m; j++) dp[j] = curr[j];
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string str1, str2;
    cin >> str1 >> str2;

    cout << sol.lcs(str1, str2);

    return 0;
}