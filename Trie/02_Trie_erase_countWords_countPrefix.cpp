// Trie | (Delete)
// Link - https://practice.geeksforgeeks.org/problems/trie-delete/1



class Node {
public:
	Node* links[26];
	int cntEndWith = 0;
	int cntPrefix = 0;

	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	Node* get(char ch) {
		return links[ch - 'a'];
	}

	void put(char ch, Node * node) {
		links[ch - 'a'] = node;
	}

	void increaseEnd() {
		cntEndWith++;
	}

	void increasePrefix() {
		cntPrefix++;
	}

	void deleteEnd() {
		cntEndWith--;
	}

	void reducePrefix() {
		cntPrefix--;
	}

	int getEnd() {
		return cntEndWith;
	}

	bool isEnd() {
		return cntEndWith;
	}

	int getPrefix() {
		return cntPrefix;
	}
};

class Trie {
public:
	Node* root;
	Trie() {
		root = new Node();
	}

	void insert(string &word) {
		Node* node = root;
		for (auto x : word) {
			if (!node -> containsKey(x)) {
				node -> put(x, new Node());
			}
			node = node -> get(x);
			node -> increasePrefix();
		}
		node -> increaseEnd();
	}

	int countWord(string &word) {
		Node* node = root;
		for (auto x : word) {
			if (node -> containsKey(x)) {
				node = node -> get(x);
			} else {
				return 0;
			}
		}
		return node -> getEnd();
	}

	int countPrefix(string &prefix) {
		Node* node = root;
		for (auto x : prefix) {
			if (node -> containsKey(x)) {
				node = node -> get(x);
			} else {
				return 0;
			}
		}
		return node -> getPrefix();
	}

	// removes one by one
	// cntEndWith-- vs cntEndWith = 0
	void erase(string &word) {
		Node* node = root;
		for (auto x : word) {
			if (node -> containsKey(x)) {
				node = node -> get(x);
				node -> reducePrefix();
			} else {
				return;
			}
		}

		if (node -> isEnd()) node -> deleteEnd();
	}
};



// GFG
class Solution {
public:
	void deleteKey(trie_node_t *root, char key[]) {
		trie_node_t* node = root;
		for (int i = 0; i < strlen(key); i++) {
			int ind = key[i] - 'a';
			if (node -> children[ind] != NULL) node = node -> children[ind];
			else return;
		}
		if (node -> value) node -> value = 0;
	}
};