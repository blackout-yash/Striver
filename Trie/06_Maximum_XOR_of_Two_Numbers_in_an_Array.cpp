// 421. Maximum XOR of Two Numbers in an Array
// Link - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/



class Node {
public:
	Node* links[2];
	bool flag = false;

	bool containKey(int ind) {
		return (links[ind] != NULL);
	}

	void put(int ind, Node *node) {
		links[ind] = node;
	}

	Node* get(int ind) {
		return links[ind];
	}

	void setEnd() {
		flag = true;
	}

	bool isEnd() {
		return flag;
	}
};

class Trie {
public:
	Node* root;
	Trie() {
		root = new Node();
	}

	void insert(int num) {
		Node* node = root;
		for (int i = 31; i >= 0; i--) {
			int bit = ((num >> i) & 1);
			if (!node -> containKey(bit)) {
				node -> put(bit, new Node());
			}
			node = node -> get(bit);
		}
	}

	int maxXor(int num) {
		Node* node = root;
		int _xor = 0, fact = 1;
		for (int i = 31; i >= 0; i--) {
			int bit = ((num >> i) & 1);
			if (node -> containKey(!bit)) {
				_xor |= (1 << i);
				node = node -> get(!bit);
			} else node = node -> get(bit);
		}
		return _xor;
	}
};

class Solution {
public:
	int findMaximumXOR(vector<int> &nums) {
		Trie T;
		for (auto x : nums) T.insert(x);

		int ans = 0;
		for (auto x : nums) ans = max(ans, T.maxXor(x));

		return ans;
	}
};