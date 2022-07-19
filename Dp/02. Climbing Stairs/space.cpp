// 70. Climbing Stairs
// Link - https://leetcode.com/problems/climbing-stairs/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int climbStairs(int n) {

		int onePrev = 1, twoPrev = 1;
		for (int i = 2; i <= n; i++) {
			int curr = onePrev + twoPrev;
			onePrev = twoPrev;
			twoPrev = curr;
		}

		return twoPrev;
	}
};

int main() {
	Solution sol;

	cout << sol.climbStairs(45);

	return 0;
}