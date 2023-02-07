// 232. Implement Queue using Stacks
// Link - https://leetcode.com/problems/implement-queue-using-stacks/



class MyQueue {
public:
	stack <int> input, output;
	MyQueue() {}

	void push(int x) {
		input.push(x);
	}

	int pop() {
		if (empty()) return -1;

		int ans = peek();
		output.pop();
		return ans;
	}

	int peek() {
		if (empty()) return -1;

		if (output.empty()) {
			while (input.size()) {
				output.push(input.top());
				input.pop();
			}
		}
		return output.top();
	}

	bool empty() {
		return (input.size() + output.size()) == 0;
	}
};
