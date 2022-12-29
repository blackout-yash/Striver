// 846. Hand of Straights
// Link - https://leetcode.com/problems/hand-of-straights/



#define pp pair<int, int>
class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int groupSize) {
		int n = hand.size();
		if (n % groupSize) return false;

		map <int, int> m;
		priority_queue <pp> pq;
		for (auto x : hand) m[x]++;
		for (auto x : m) pq.push({x.first, x.second});

		int prev = -1, cnt = 0;
		vector <pp> temp;
		for (auto x : hand) {
			int num = pq.top().first,
			    freq = pq.top().second;
			pq.pop();

			if (prev == -1 || prev - num == 1) {
				if (freq > 1) temp.push_back({num, freq - 1});
				cnt++; prev = num;
			} else return false;

			if (cnt % groupSize == 0) {
				prev = -1;
				for (auto x : temp) pq.push(x);
				temp.clear();
			}
		}
		return true;
	}
};