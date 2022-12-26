// Count of distinct substrings
// Link - https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1



class Node {
public:
	Node* links[26];
	bool flag = false;

	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}

	Node* get(char ch) {
		return links[ch - 'a'];
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

	int insert(string word) {
		int cnt = 1, n = word.size();
		for (int i = 0; i < n; i++) {
			string str;
			Node* node = root;
			for (int j = i; j < n; j++) {
				if (!node -> containsKey(word[j])) {
					cnt++;
					node -> put(word[j], new Node());
				}
				node = node -> get(word[j]);
			}
		}
		return cnt;
	}
};

int countDistinctSubstring(string s) {
	Trie T;

	int ans = T.insert(s);

	return ans;
}