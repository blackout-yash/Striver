// 208. Implement Trie (Prefix Tree)
// Link - https://leetcode.com/problems/implement-trie-prefix-tree/



// Initialization
// Trie T;
// Not, Trie T = new Trie();

// Calling
// T.insert("yash");
// T -> insert("yash");

class Node {
public:
	Node* links[26];
	bool flag = false;

	bool containKey(char ch) {
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

	void insert(string word) {
		Node* node = root;
		for (auto x : word) {
			if (node -> containKey(x) == false) {
				node -> put(x, new Node());
			}
			node = node -> get(x);
		}
		node -> setEnd();
	}

	bool searchWord(string &word) {
		Node* node = root;
		for (auto x : word) {
			if (node -> containKey(x) == false) return false;
			node = node -> get(x);
		}
		return node -> isEnd();
	}

	bool searchPrefix(string prefix) {
		Node* node = root;
		for (auto x : prefix) {
			if (node -> containKey(x) == false) return false;
			node = node -> get(x);
		}
		return true;
	}
};
