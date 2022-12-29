// Minimum Cost of ropes
// Link - https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1



#define ll long long
class Solution {
public:
	ll size(priority_queue <ll, vector <ll>, greater <ll>> &pq) {
		ll num = pq.top();
		pq.pop();
		return num;
	}

	long long minCost(long long arr[], long long n) {
		priority_queue <ll, vector <ll>, greater <ll>> pq;
		for (int i = 0; i < n; i++) pq.push(arr[i]);

		ll ans = 0;
		while (pq.size() != 1) {
			ll size1 = size(pq),
			   size2 = size(pq);

			ans += (size1 + size2);
			pq.push(size1 + size2);
		}
		return ans;
	}
};