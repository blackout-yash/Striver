// 84. Largest Rectangle in Histogram
// Ḷink - https://leetcode.com/problems/largest-rectangle-in-histogram/



#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size(), ans = 0;

        stack <int> s;
        for (int i = 0; i <= n; i++) {
            while (!s.empty()) {
                if (i == n || heights[s.top()] > heights[i]) {

                    int height = heights[s.top()], width;
                    s.pop();

                    if (s.empty()) width = i;
                    else width = (i - s.top()) - 1;

                    ans = max(ans, height * width);
                } else break;
            } s.push(i);
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
