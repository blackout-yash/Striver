// Anagram
// Link - https://practice.geeksforgeeks.org/problems/anagram-1587115620/1



class Solution {
public:
	bool isAnagram(string a, string b) {
		vector <int> freq(26);
		for (auto x : a) freq[x - 'a']++;
		for (auto x : b) freq[x - 'a']--;
		for (auto x : freq) {
			if (x != 0) return false;
		}
		return true;
	}

};