// Maximum Sum Combination
// Link - https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1



#define pp pair<int, int>
#define ppi pair<int, pair<int, int>>
class Solution {
public:
	void insert(int num, int x, int y, set <pp> &s, priority_queue <ppi> &pq) {
		s.insert({x, y});
		pq.push({num, {x, y}});
	}

	vector <int> maxCombinations(int n, int k, vector <int> &a, vector <int> &b) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		set <pp> s;
		vector <int> ans;
		priority_queue <ppi> pq;
		insert(a[n - 1] + b[n - 1], n - 1, n - 1, s, pq);

		while (k--) {
			auto it = pq.top();
			pq.pop();
			int num = it.first,
			    x = it.second.first,
			    y = it.second.second;
			ans.push_back(num);

			if (x && s.find({x - 1, y}) == s.end()) insert(a[x - 1] + b[y], x - 1, y, s, pq);
			if (y && s.find({x, y - 1}) == s.end()) insert(a[x] + b[y - 1], x, y - 1, s, pq);
		}
		return ans;
	}
};