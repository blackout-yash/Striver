// 347. Top K Frequent Elements
// Link - https://leetcode.com/problems/top-k-frequent-elements/



class Solution {
public:
	vector <int> topKFrequent(vector<int>& nums, int k) {
		map <int, int> m;
		for (auto x : nums) m[x]++;

		vector <int> ans;
		int n = m.size();
		priority_queue <pair <int, int>> pq;
		for (auto x : m) {
			pq.push({x.second, x.first});
			if (pq.size() + k > n) {
				ans.push_back(pq.top().second);
				pq.pop();
			}
		}
		return ans;
	}
};