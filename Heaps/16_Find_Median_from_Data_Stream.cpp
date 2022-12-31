// 295. Find Median from Data Stream
// Link - https://leetcode.com/problems/find-median-from-data-stream/



class MedianFinder {
public:
	priority_queue <int> maxHeap;
	priority_queue <int, vector <int>, greater <int>> minHeap;
	MedianFinder() {}

	void addNum(int num) {
		if (minHeap.empty() || num >= minHeap.top()) {
			minHeap.push(num);
			if (minHeap.size() > maxHeap.size() + 1) {
				maxHeap.push(minHeap.top());
				minHeap.pop();
			}
		} else {
			maxHeap.push(num);
			if (maxHeap.size() > minHeap.size()) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
		}
	}

	double findMedian() {
		if (maxHeap.size() == minHeap.size()) return (double) (maxHeap.top() + minHeap.top()) / 2;
		return minHeap.top();
	}
};