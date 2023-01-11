// Count number of substrings
// Link - https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1



#define ll long long
class Solution {
public:
	ll atMostK_distinct(string &s, int k) {
		vector <int> freq(26);
		ll ans = 0, n = s.size(), left = 0, size = 0;
		for (int i = 0; i < n; i++) {
			if (freq[s[i] - 'a'] == 0) size++;
			freq[s[i] - 'a']++;

			while (size > k) {
				freq[s[left] - 'a']--;
				if (freq[s[left] - 'a'] == 0) size--;
				left++;
			}
			ans += (i - left + 1);
		}
		return ans;
	}

	long long int substrCount (string &s, int k) {
		ll ans1 = atMostK_distinct(s, k),
		   ans2 = atMostK_distinct(s, k - 1),
		   ans3 = ans1 - ans2;

		return ans3;
	}
};