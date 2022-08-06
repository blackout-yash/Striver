// Boundary Traversal in Binary Tree
// Link - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0



// Approach I
class Solution {
public:
	bool isLeaf(Node *root) {
		return (root -> left == NULL) && (root -> right == NULL);
	}

	void leftBoundary(Node *root, vector <int> &ans) {
		if (root == NULL) return;

		stack <Node*> s;
		s.push(root);
		while (!s.empty()) {
			Node *node = s.top();
			s.pop();

			if (!isLeaf(node)) ans.push_back(node -> data);

			if (node -> left != NULL) s.push(node -> left);
			else if (node -> right != NULL) s.push(node -> right);
		}
	}

	void leaf(Node *root, vector <int> &ans) {
		if (root == NULL) return;

		stack <Node*> s;
		s.push(root);

		while (!s.empty()) {
			Node *node = s.top();
			s.pop();

			if (isLeaf(node)) ans.push_back(node -> data);

			if (node -> right != NULL) s.push(node -> right);
			if (node -> left != NULL) s.push(node -> left);
		}
	}

	void rightBoundary(Node *root, vector <int> &ans) {
		if (root == NULL) return;

		stack <Node*> s;
		s.push(root);


		stack <int> store;
		while (!s.empty()) {
			Node *node = s.top();
			s.pop();

			if (!isLeaf(node)) store.push(node -> data);

			if (node -> right != NULL) s.push(node -> right);
			else if (node -> left != NULL) s.push(node -> left);
		}

		while (!store.empty()) {
			ans.push_back(store.top());
			store.pop();
		}
	}

	vector <int> boundary(Node *root) {
		vector <int> ans;
		if (root == NULL) return ans;
		if (root -> left != NULL || root -> right != NULL) ans.push_back(root -> data);

		leftBoundary(root -> left, ans);
		leaf(root, ans);
		rightBoundary(root -> right, ans);

		return ans;
	}
};




// Arroach II
class Solution {
public:
	void leftBoundary(Node *root, vector <int> &ans) {
		if (root == NULL) return;

		if (root -> left != NULL) {
			ans.push_back(root -> data);
			leftBoundary(root -> left, ans);
		} else if (root -> right != NULL) {
			ans.push_back(root -> data);
			leftBoundary(root -> right, ans);
		}
	}

	void leaf(Node *root, vector <int> &ans) {
		if (root == NULL) return;

		if (root -> left == NULL && root -> right == NULL) ans.push_back(root -> data);

		leaf(root -> left, ans);
		leaf(root -> right, ans);
	}

	void rightBoundary(Node *root, vector <int> &ans) {
		if (root == NULL) return;

		if (root -> right != NULL) {
			rightBoundary(root -> right, ans);
			ans.push_back(root -> data);
		} else if (root -> left != NULL) {
			rightBoundary(root -> left, ans);
			ans.push_back(root -> data);
		}
	}

	vector <int> boundary(Node *root) {
		vector <int> ans;
		if (root == NULL) return ans;
		if (root -> left != NULL || root -> right != NULL) ans.push_back(root -> data);

		leftBoundary(root -> left, ans);
		leaf(root, ans);
		rightBoundary(root -> right, ans);

		return ans;
	}
};