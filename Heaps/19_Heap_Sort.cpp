// Heap Sort
// Link - https://practice.geeksforgeeks.org/problems/heap-sort/1



class Solution {
public:
	void heapify(int arr[], int n, int i)  {
		int left = (2 * i) + 1,
		    right = (2 * i) + 2;

		if (left < n && right < n && arr[i] < arr[left] && arr[i] < arr[right]) {
			if (arr[left] > arr[right]) {
				swap(arr[i], arr[left]);
				heapify(arr, n, left);
			} else {
				swap(arr[i], arr[right]);
				heapify(arr, n, right);
			}
		} else if (left < n && arr[i] < arr[left]) {
			swap(arr[i], arr[left]);
			heapify(arr, n, left);
		} else if (right < n && arr[i] < arr[right]) {
			swap(arr[i], arr[right]);
			heapify(arr, n, right);
		}
	}

public:
	void buildHeap(int arr[], int n)  {
		for (int i = n / 2; i >= 0; i--) {
			heapify(arr, n, i);
		}
	}


public:
	void heapSort(int arr[], int n) {
		buildHeap(arr, n);

		for (int i = n - 1; i >= 0; i--) {
			swap(arr[i], arr[0]);
			heapify(arr, i, 0);
		}
	}
};