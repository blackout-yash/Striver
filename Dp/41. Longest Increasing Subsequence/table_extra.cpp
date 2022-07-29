class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return n;
        vector <vector<int>> dp(n + 1, vector<int> (n + 1));

        nums.insert(nums.begin(), -1e9);
        for (int i = n; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                int taken = 0;
                if (nums[j] < nums[i]) {
                    if (i != n) taken = 1 + dp[i + 1][i];
                    else taken = 1;
                }

                int notTaken = 0;
                if (i != n) notTaken = dp[i + 1][j];

                dp[i][j] = max(taken, notTaken);
            }
        }

        return dp[1][0];
    }
};