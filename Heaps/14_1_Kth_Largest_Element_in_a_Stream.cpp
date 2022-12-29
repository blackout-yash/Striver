// 703. Kth Largest Element in a Stream
// Link - https://leetcode.com/problems/kth-largest-element-in-a-stream/



class KthLargest {
public:
	int k;
	priority_queue <int, vector <int>, greater <int>> pq;

	KthLargest(int k, vector <int> &nums) {
		this -> k = k;
		for (auto x : nums) pq.push(x);
	}

	int add(int val) {
		pq.push(val);
		while (k < pq.size()) pq.pop();
		return pq.top();
	}
};