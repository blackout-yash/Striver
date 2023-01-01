// Implementation of Priority Queue using Binary Heap
// Link - https://practice.geeksforgeeks.org/problems/implementation-of-priority-queue-using-binary-heap/1



class Solution {
public:
	void heapify(int i, int n) {
		int left = (2 * i) + 1,
		    right = (2 * i) + 2;

		if (left < n && right < n && H[i] <= H[left] && H[i] <= H[right]) {
			if (H[left] >= H[right]) {
				swap(H[left], H[i]);
				heapify(left, n);
			} else {
				swap(H[right], H[i]);
				heapify(right, n);
			}
		} else if (left < n && H[i] <= H[left]) {
			swap(H[left], H[i]);
			heapify(left, n);
		} else if (right < n && H[i] <= H[right]) {
			swap(H[right], H[i]);
			heapify(right, n);
		}
	}

	int extractMax() {
		int ans = H[0];

		swap(H[0], H[s]);
		s--;

		heapify(0, s + 1);

		return ans;
	}
};