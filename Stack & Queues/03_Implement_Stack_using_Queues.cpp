// 225. Implement Stack using Queues
// Link -



// Approah I: 1 Stack
class MyStack {
public:
	queue <int> q;
	MyStack() {}

	void push(int x) {
		q.push(x);
		int size = q.size();
		for (int i = 0; i < size - 1; i++) {
			q.push(q.front());
			q.pop();
		}
	}

	int pop() {
		int ans = q.front();
		q.pop();
		return ans;
	}

	int top() {
		return q.front();
	}

	bool empty() {
		return q.empty();
	}
};



// Approah I: 2 Stack
class MyStack {
public:
	queue <int> q1, q2;
	MyStack() {}

	void push(int x) {
		q2.push(x);
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}
		swap(q1, q2);
	}

	int pop() {
		int ans = q1.front();
		q1.pop();
		return ans;
	}

	int top() {
		return q1.front();
	}

	bool empty() {
		return q1.empty();
	}
};
