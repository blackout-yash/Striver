// Parenthesis Checker
// Link - https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1



class Solution {
public:
	bool ispar(string str) {
		stack <char> s;
		for (auto x : str) {
			if (x == '(' || x == '{' || x == '[') s.push(x);
			else if (s.empty()) return 0;
			else if (x == ')') {
				if (s.top() != '(') return 0;
				s.pop();
			} else if (x == '}') {
				if (s.top() != '{') return 0;
				s.pop();
			} else {
				if (s.top() != '[') return 0;
				s.pop();
			}
		}
		return s.empty();
	}
};