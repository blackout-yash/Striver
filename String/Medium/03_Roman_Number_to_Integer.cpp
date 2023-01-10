// Roman Number to Integer
// Link - https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1



class Solution {
public:
	int romanToDecimal(string &s) {
		map <char, int> m;
		m['I'] = 1;
		m['V'] = 5;
		m['X'] = 10;
		m['L'] = 50;
		m['C'] = 100;
		m['D'] = 500;
		m['M'] = 1000;
		int ans = 0, n = s.size();
		for (int i = 0; i < n; i++) {
			ans += m[s[i]];
			if (i && m[s[i]] > m[s[i - 1]]) ans -= (2 * m[s[i - 1]]);
		}
		return ans;
	}
};