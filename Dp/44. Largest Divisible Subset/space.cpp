#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector <int> printLargestDivisibleSubset(int n, vector <int> &nums, vector <int> &dp) {
        int ans = *max_element(dp.begin(), dp.end()), index;

        for (int i = 0; i < n; i++) {
            if (dp[i] == ans) {
                index = i;
                break;
            }
        }

        vector <int> store(ans);
        int prev = nums[index];
        for (int i = index; i >= 0; i--) {
            if (dp[i] == ans && prev % nums[i] == 0) {
                store[ans - 1] = nums[i];
                prev = nums[i]; ans--;
            }
        }
        return store;
    }

    vector <int> largestDivisibleSubset(vector<int> &nums) {
        int n = nums.size();
        vector <int> dp(n);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        vector <int> ans = printLargestDivisibleSubset(n, nums, dp);

        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector <int> nums(n);
    for (auto &xx : nums) cin >> xx;

    vector <int> ans = sol.largestDivisibleSubset(nums);

    for (auto x : ans) cout << x << " ";

    return 0;
}