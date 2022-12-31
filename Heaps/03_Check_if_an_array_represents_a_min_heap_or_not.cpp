// Does array represent Heap
// Link - https://practice.geeksforgeeks.org/problems/does-array-represent-heap4345/1




class Solution {
public:
	bool isMaxHeapUtil(int a[], int n, int i) {
		if (i >= n) return true;
		int left = (2 * i) + 1,
		    right = (2 * i) + 2;
		if (left < n && a[i] < a[left]) return false;
		else if (right < n && a[i] < a[right]) return false;
		return isMaxHeapUtil(a, n, left) && isMaxHeapUtil(a, n, right);
	}

	bool isMaxHeap(int a[], int n) {
		return isMaxHeapUtil(a, n, 0);
	}
};