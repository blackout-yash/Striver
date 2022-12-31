// Build Min Heap
// Link - https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0



#include <bits/stdc++.h>

void heapify(int i, int n, vector <int> &arr) {
	int left = (2 * i) + 1,
	    right = (2 * i) + 2;

	if (left < n && right < n && arr[i] > arr[left] && arr[i] > arr[right]) {
		if (arr[left] < arr[right]) {
			swap(arr[i], arr[left]);
			heapify(left, n, arr);
		} else {
			swap(arr[i], arr[right]);
			heapify(right, n, arr);
		}
	} else if (left < n && arr[i] > arr[left]) {
		swap(arr[i], arr[left]);
		heapify(left, n, arr);
	} else if (right < n && arr[i] > arr[right]) {
		swap(arr[i], arr[right]);
		heapify(right, n, arr);
	}
}

vector <int> buildMinHeap(vector<int> &arr) {
	int n = arr.size();
	for (int i = n / 2; i >= 0; i--) {
		heapify(i, n, arr);
	}
	return arr;
}