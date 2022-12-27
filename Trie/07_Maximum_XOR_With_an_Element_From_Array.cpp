// 1707. Maximum XOR With an Element From Array
// Link - https://leetcode.com/problems/maximum-xor-with-an-element-from-array/



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
		int _xor = 0;
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

struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const {
		auto hash1 = hash<T1> {}(p.first);
		auto hash2 = hash<T2> {}(p.second);

		if (hash1 != hash2) {
			return hash1 ^ hash2;
		}
		return hash1;
	}
};

class Solution {
public:
	vector<int> maximizeXor(vector <int> &nums, vector<vector<int>> &queries) {
		vector <pair<pair<int, int>, int>> arr;
		int n = nums.size(), m = queries.size();
		for (int i = 0; i < m; i++) {
			arr.push_back({{queries[i][1], queries[i][0]}, i});
		}
		sort(arr.begin(), arr.end());
		sort(nums.begin(), nums.end());

		Trie T;

		int j = 0;
		vector <int> ans(m);
		for (int i = 0; i < m; i++) {
			int m = arr[i].first.first,
			    x = arr[i].first.second,
			    ind = arr[i].second;
			while (j < n) {
				if (nums[j] <= m) {
					T.insert(nums[j]);
					j++;
				} else break;
			}

			if (j) ans[ind] = T.maxXor(x);
			else ans[ind] = -1;
		}

		return ans;
	}
};