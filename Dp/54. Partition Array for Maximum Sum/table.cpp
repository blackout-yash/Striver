// 1043. Partition Array for Maximum Sum
// Link - https://leetcode.com/problems/partition-array-for-maximum-sum/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();

        vector <int> dp(n);
        for (int i = 0; i < n; i++) {
            int _max = 0, size = 0;
            for (int j = i; j > max(-1, (i - k)); j--) {
                size++; _max = max(_max, arr[j]);

                if (j) dp[i] = max(dp[i], (_max * size) + dp[j - 1]);
                else dp[i] = max(dp[i], _max * size);
            }
        }

        return dp[n - 1];
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