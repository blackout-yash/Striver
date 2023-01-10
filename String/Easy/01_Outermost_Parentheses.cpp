// Outermost Parentheses
// Link - https://practice.geeksforgeeks.org/problems/outermost-parentheses/1



class Solution {
public:
	string removeOuter(string &str) {
		string ans;
		stack <char> s;
		for (auto x : str) {
			if (s.empty()) s.push(x);
			else if (x == '(') {
				s.push(x);
				ans.push_back(x);
			} else {
				if (s.size() == 1) s.pop();
				else {
					s.pop();
					ans.push_back(x);
				}
			}
		}
		return ans;
	}
};