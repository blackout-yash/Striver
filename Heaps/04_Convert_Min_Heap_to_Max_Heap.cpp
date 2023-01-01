// Convert Min Heap to Max Heap
// Link - https://practice.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1



class Solution {
public:
	void heaify(int i, int n, vector <int> &arr) {
		int left = (2 * i) + 1,
		    right = (2 * i) + 2;

		if (left < n && right < n && arr[i] <= arr[left] && arr[i] <= arr[right]) {
			if (arr[left] >= arr[right]) {
				swap(arr[i], arr[left]);
				heaify(left, n, arr);
			} else {
				swap(arr[i], arr[right]);
				heaify(right, n, arr);
			}
		} else if (left < n && arr[i] <= arr[left]) {
			swap(arr[i], arr[left]);
			heaify(left, n, arr);
		} else if (right < n && arr[i] <= arr[right]) {
			swap(arr[i], arr[right]);
			heaify(right, n, arr);
		}
	}

	void convertMinToMaxHeap(vector<int> &arr, int n) {
		for (int i = n / 2; i >= 0; i--) {
			heaify(i, n, arr);
		}
	}
};