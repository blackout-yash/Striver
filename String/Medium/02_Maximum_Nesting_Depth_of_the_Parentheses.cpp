// Maximum Nesting Depth of the Parentheses
// Link - https://practice.geeksforgeeks.org/problems/maximum-nesting-depth-of-the-parentheses/1



class Solution {
public:
	int maxDepth(string s) {
		int ans = 0, curr = 0;
		for (auto x : s) {
			if (x == '(') curr++;
			else if (x == ')') curr--;
			ans = max(ans, curr);
		}
		return ans;
	}
};