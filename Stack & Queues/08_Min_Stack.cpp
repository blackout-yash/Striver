// 155. Min Stack
// Link - https://leetcode.com/problems/min-stack/



// Approach I: Space = O(n)
class MinStack {
public:
	long _min;
	stack <long> s;

	MinStack() {}

	void push(int val) {
		if (s.empty()) {
			_min = val;
			s.push(val);
		} else if (_min > val) {
			s.push(2l * val - _min);
			_min = val;
		} else s.push(val);
	}

	void pop() {
		if (_min >= s.top()) _min = 2l * _min - s.top();
		s.pop();
	}

	int top() {
		if (_min <= s.top()) return s.top();
		return _min;
	}

	int getMin() {
		return _min;
	}
};



// Approach II: Space = O(2n)
class MinStack {
public:
	stack <pair <int, int>> s;
	MinStack() {}

	void push(int val) {
		if (s.empty()) s.push({val, val});
		else s.push({val, min(s.top().second, val)});
	}

	void pop() {
		s.pop();
	}

	int top() {
		return s.top().first;
	}

	int getMin() {
		return s.top().second;
	}
};
