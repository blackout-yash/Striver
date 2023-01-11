// 151. Reverse Words in a String
// Link - https://leetcode.com/problems/reverse-words-in-a-string/



class Solution {
public:
	string reverseWords(string s) {
		string ans;
		int n = s.size(), j = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			if (i == 0 || s[i] == ' ') {
				if (i == j && s[i] == ' ') j = i - 1;
				else {
					if (ans.size()) ans.push_back(' ');
					for (int k = i; k <= j; k++) {
						if (s[k] != ' ') ans.push_back(s[k]);
					}
					j = i - 1;
				}
			}
		}
		return ans;
	}
};