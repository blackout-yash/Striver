// 215. Kth Largest Element in an Array
// Link - https://leetcode.com/problems/kth-largest-element-in-an-array/



// Approach I: Quick Select
class Solution {
public:
	int partition(vector <int> &arr, int l, int r) {
		int pivot = arr[r], i = l;
		for (int j = l; j <= r - 1; j++) {
			if (arr[j] >= pivot) {
				swap(arr[i], arr[j]);
				i++;
			}
		}
		swap(arr[i], arr[r]);
		return i;
	}

	int findKthLargest(vector<int> &arr, int k) {
		int l = 0, r = arr.size() - 1;
		while (l <= r) {
			int index = partition(arr, l, r);
			if (index + 1 == k) return arr[index];
			else if (index >= k) r = index - 1;
			else l = index + 1;
		}
		return -1;
	}
};



// Approach II
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue <int, vector <int>, greater <int>> pq;
		for (auto x : nums) {
			pq.push(x);
			if (pq.size() > k) pq.pop();
		}
		return pq.top();
	}
};