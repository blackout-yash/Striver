// 38. Count and Say
// Link - https://leetcode.com/problems/count-and-say/



class Solution {
public:
	void insert(int cnt, char ch, string &ans) {
		ans.push_back(char('0' + cnt));
		ans.push_back(ch);
	}

	string countAndSay(int n) {
		if (n == 1) return "1";
		string temp = countAndSay(n - 1), ans;

		int len = temp.size(), cnt = 1;
		for (int i = 0; i < len; i++) {
			if (i && temp[i] != temp[i - 1]) {
				insert(cnt, temp[i - 1], ans);
				cnt = 1;
			} else if (i) cnt++;

			if (i + 1 == len) insert(cnt, temp[i], ans);
		}

		return ans;
	}
};