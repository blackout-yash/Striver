// Longest Common Prefix in an Array
// Link - https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1



class Solution {
public:
	string longestCommonPrefix (string arr[], int n) {
		if (n == 1) return arr[0];

		vector <int> size(arr[0].size());
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < max(arr[0].size(), arr[i].size()); j++) {
				if (arr[0][j] == arr[i][j]) size[j]++;
				else break;
			}
		}

		string ans;
		for (int i = 0; i < arr[0].size(); i++) {
			if (size[i] + 1 == n) ans.push_back(arr[0][i]);
			else break;
		}
		if (ans.empty()) return "-1";
		return ans;
	}
};