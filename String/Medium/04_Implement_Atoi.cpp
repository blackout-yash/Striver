// Implement Atoi
// Link - https://practice.geeksforgeeks.org/problems/implement-atoi/1



class Solution {
public:
	int atoi(string s) {
		int n = s.size(), ans = 0, fact = 1;
		for (int i = n - 1; i >= 0; i--) {
			int digit = s[i] - '0';
			if (0 <= digit && digit <= 9) {
				ans += (fact * digit);
				fact *= 10;
			} else if (i == 0 && s[i] == '-') ans *= -1;
			else return -1;
		}
		return ans;
	}
};