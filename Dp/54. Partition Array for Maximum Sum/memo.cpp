// 1043. Partition Array for Maximum Sum
// Link - https://leetcode.com/problems/partition-array-for-maximum-sum/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(int n, int k, vector <int> &arr, vector <int> &dp) {
        if (n < 0) return 0;
        else if (dp[n] != -1) return dp[n];

        int ans = 0, _max = 0, size = 0;
        for (int j = n; j > max(-1, (n - k)); j--) {
            size++; _max = max(_max, arr[j]);
            int curr = maxSumAfterPartitioning(j - 1, k, arr, dp);
            ans = max(ans, (_max * size) + curr);
        }
        return dp[n] = ans;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
        vector <int> dp(n, -1);

        int ans = maxSumAfterPartitioning(n - 1, k, arr, dp);

        return ans;
    }
};

int main() {
    Solution sol;

    int n, k;
    cin >> n >> k;

    vector <int> arr(n);
    for (auto &xx : arr) cin >> xx;

    cout << sol.maxSumAfterPartitioning(arr, k);

    return 0;
}