// 5. Longest Palindromic Substring
// Link - https://leetcode.com/problems/longest-palindromic-substring/



class Solution {
public:
	bool isValid(int i, int j, int n) {
		return i >= 0 && j < n;
	}

	string isPalindrome(int i, int j, string &s) {
		int n = s.size();
		while (true) {
			if (isValid(i, j, n) && s[i] == s[j]) i--, j++;
			else {
				i++; j--;
				break;
			}
		}

		string ans;
		for (int k = i; k <= j; k++) ans.push_back(s[k]);
		return ans;
	}

	string longestPalindrome(string s) {
		string ans;
		for (int i = 0; i < s.size(); i++) {
			string temp1 = isPalindrome(i - 1, i + 1, s),
			       temp2 = isPalindrome(i, i + 1, s),
			       temp3 = isPalindrome(i - 1, i, s);
			if (temp1.size() > ans.size()) ans = temp1;
			if (temp2.size() > ans.size()) ans = temp2;
			if (temp3.size() > ans.size()) ans = temp3;
		}
		return ans;
	}
};