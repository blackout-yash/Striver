// 1781. Sum of Beauty of All Substrings
// Link - https://leetcode.com/problems/sum-of-beauty-of-all-substrings/



class Solution {
public:
	int beautySum(string s) {
		int ans = 0, n = s.size();
		for (int i = 0; i < n; i++) {
			vector <int> arr(26);
			for (int j = i; j < n; j++) {
				arr[s[j] - 'a']++;
				int _min = 1e9, _max = -1e9;
				for (auto x : arr) {
					if (x) _min = min(_min, x);
					_max = max(_max, x);
				}
				if (_min != 1e9) ans += (_max - _min);
			}
		}
		return ans;
	}
};