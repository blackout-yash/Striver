// 84. Largest Rectangle in Histogram
// Ḷink - https://leetcode.com/problems/largest-rectangle-in-histogram/



#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector <int> _leftToRight(int n, vector <int> &heights) {
        vector <int> leftToRight(n, -1);
        stack <int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty()) {
                if (heights[s.top()] < heights[i]) {
                    leftToRight[i] = s.top();
                    break;
                } else s.pop();
            } s.push(i);
        }
        return leftToRight;
    }

    vector <int> _rightToLeft(int n, vector <int> &heights) {
        vector <int> rightToLeft(n, n);
        stack <int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty()) {
                if (heights[s.top()] < heights[i]) {
                    rightToLeft[i] = s.top();
                    break;
                } else s.pop();
            } s.push(i);
        }
        return rightToLeft;
    }

    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector <int> leftToRight = _leftToRight(n, heights);
        vector <int> rightToLeft = _rightToLeft(n, heights);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = (rightToLeft[i] - leftToRight[i]) - 1;
            ans = max(ans, width * heights[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector <int> heights(n);
    for (auto &xx : heights) cin >> xx;

    cout << sol.largestRectangleArea(heights);

    return 0;
}
