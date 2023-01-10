// Check if strings are rotations of each other or not
// Link - https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1



class Solution {
public:
	bool areRotations(string s1, string s2) {
		int n = s1.size(), m = s2.size();
		if (n != m) return false;

		s1 += s1;
		if (s1.find(s2) == string::npos) return false;
		return true;
	}
};