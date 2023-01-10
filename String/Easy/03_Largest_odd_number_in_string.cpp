// Largest odd number in string
// Link - https://practice.geeksforgeeks.org/problems/largest-odd-number-in-string/1



class Solution {
public:
	string maxOdd(string s) {
		int n = s.size();
		for (int i = n - 1; i >= 0; i--) {
			int num = s[i] - '0';
			if (num & 1) break;
			else s.pop_back();
		}
		return s;
	}
};