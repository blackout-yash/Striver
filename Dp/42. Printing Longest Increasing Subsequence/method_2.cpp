// Printing Longest Increasing Subsequence



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void printLIS(int n, vector <int> &nums, vector <int> &dp) {

        int ans = *max_element(dp.begin(), dp.end()), index;
        for (int i = 0; i < n; i++) {
            if (dp[i] == ans) {
                index = i;
                break;
            }
        }

        vector <int> store(ans);
        for (int i = index; i >= 0; i--) {
            int index = dp[i] - 1;
            if (dp[i] == ans) store[index] = nums[i];
            else if (store[index + 1] > nums[i]) store[index] = max(store[index], nums[i]);
        }

        for (auto x : store) cout << x << " ";
        cout << endl;
    }

    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        vector <int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
                ans = max(ans, dp[i]);
            }
        }

        printLIS(n, nums, dp);

        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector <int> nums(n);
    for (auto &xx : nums) cin >> xx;

    cout << sol.lengthOfLIS(nums);

    return 0;
}