// 1277. Count Square Submatrices with All Ones
// Link - https://leetcode.com/problems/count-square-submatrices-with-all-ones/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;

        vector <vector<int>> dp(n, vector<int> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j]) {
                    if (i && j) {
                        int up = dp[i - 1][j];
                        int diagonal = dp[i - 1][j - 1];
                        int left = dp[i][j - 1];
                        dp[i][j] = 1 + min({left, diagonal, up});
                    } else dp[i][j] = 1;
                } ans += dp[i][j];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int n, m;
    cin >> n >> m;

    vector <vector<int>> matrix(n, vector<int> (m));
    for (auto &x : matrix) {
        for (auto &y : x) cin >> y;
    }

    cout << sol.countSquares(matrix);

    return 0;
}