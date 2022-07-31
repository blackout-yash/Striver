// TLE => O(N ^ 3)

// 1043. Partition Array for Maximum Sum
// Link - https://leetcode.com/problems/partition-array-for-maximum-sum/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSubarray(int i, int j, int len, vector<int> &num, vector <vector<int>> &dp) {
        if (i == j) return num[i];
        else if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if (j - i < len) {
            int _max = *max_element(num.begin() + i, num.begin() + j + 1);
            ans = _max * (j - i + 1);
        }

        for (int k = i; k < j; k++) {
            int left = maximumSubarray(i, k, len, num, dp);
            int right = maximumSubarray(k + 1, j, len, num, dp);
            ans = max(ans, left + right);
        } return dp[i][j] = ans;

    }

    int maximumSubarray(vector<int> &num, int k) {
        int n = num.size();
        vector <vector<int>> dp(n, vector<int> (n, -1));

        int ans = maximumSubarray(0, n - 1, k, num, dp);

        return ans;
    }
};

int main() {
    Solution sol;

    int n, k;
    cin >> n >> k;

    vector <int> num(n);
    for (auto &xx : num) cin >> xx;

    cout << sol.maximumSubarray(num, k);

    return 0;
}