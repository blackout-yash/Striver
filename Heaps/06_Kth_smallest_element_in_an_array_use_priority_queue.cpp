// Kth smallest element
// Link - https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1



// Approach I: Quick Select
class Solution {
public:
	int partition(int arr[], int l, int r) {
		int pivot = arr[r], i = l;
		for (int j = l; j <= r - 1; j++) {
			if (arr[j] <= pivot) {
				swap(arr[i], arr[j]);
				i++;
			}
		}
		swap(arr[i], arr[r]);
		return i;
	}

	int kthSmallest(int arr[], int l, int r, int k) {
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
	int kthSmallest(int arr[], int l, int r, int k) {
		priority_queue <int> pq;
		for (int i = l; i <= r; i++) {
			pq.push(arr[i]);
			if (pq.size() > k) pq.pop();
		}
		return pq.top();
	}
};