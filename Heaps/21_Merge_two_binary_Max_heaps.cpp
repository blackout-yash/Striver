// Merge two binary Max heaps
// Link - https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1



class Solution {
public:
	void heapify(int i, int n, vector <int> &arr)  {
		int left = (2 * i) + 1,
		    right = (2 * i) + 2;

		if (left < n && right < n && arr[i] < arr[left] && arr[i] < arr[right]) {
			if (arr[left] > arr[right]) {
				swap(arr[i], arr[left]);
				heapify(left, n, arr);
			} else {
				swap(arr[i], arr[right]);
				heapify(right, n, arr);
			}
		} else if (left < n && arr[i] < arr[left]) {
			swap(arr[i], arr[left]);
			heapify(left, n, arr);
		} else if (right < n && arr[i] < arr[right]) {
			swap(arr[i], arr[right]);
			heapify(right, n, arr);
		}
	}

	vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
		vector <int> c = a;
		for (auto x : b) c.push_back(x);

		int size = c.size();
		for (int i = size / 2; i >= 0; i--) {
			heapify(i, size, c);
		}
		return c;
	}
};