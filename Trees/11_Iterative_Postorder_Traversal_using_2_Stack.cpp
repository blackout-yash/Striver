// 145. Binary Tree Postorder Traversal
// Link - https://leetcode.com/problems/binary-tree-postorder-traversal/



#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class Node {
public:
	int val;
	class Node *left;
	class Node *right;

	Node(int data) {
		val = data;
		left = right = NULL;
	}
};

vector<int> postOrder(Node *root) {
	vector <int> ans;
	if (root == NULL) return ans;

	stack <Node*> s1, s2;
	s1.push(root);

	while (!s1.empty()) {
		Node *node = s1.top();
		s1.pop();

		if (node -> left != NULL) s1.push(node -> left);
		if (node -> right != NULL) s1.push(node -> right);

		s2.push(node);
	}

	while (!s2.empty()) {
		Node *node = s2.top();
		s2.pop();

		ans.push_back(node -> val);
	}
	return ans;
}

int main() {
	class Node *root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	root -> left -> right = new Node(4);

	vector <int> ans = postOrder(root);

	for (auto x : ans) cout << x << " ";

	return 0;
}