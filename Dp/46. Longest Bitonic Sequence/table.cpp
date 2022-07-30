// 11. Longest Bitonic Sequence
// Link - https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
#include <algorithm>

    int longestBitonicSequence(vector<int> &arr, int n) {
        vector <int> dp1(n, 1), dp2(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (arr[i] > arr[j]) dp1[i] = max(dp1[i], 1 + dp1[j]);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) dp2[i] = max(dp2[i], 1 + dp2[j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    ans = max({ans, dp1[i], dp2[j]});
                } else if (arr[i] > arr[j]) ans = max(ans, dp1[i] + dp2[j]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector <int> arr(n);
    for (auto &xx : arr) cin >> xx;

    cout << sol.longestBitonicSequence(arr, n);

    return 0;
}