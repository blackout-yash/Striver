// 297. Serialize and Deserialize Binary Tree
// Link - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/



class Codec {
public:
	int toChar(char ch) {
		int ans = ch - '0';
		return ans;
	}

	int change(int &j, string &s) {
		j++;
		string ans;

		int minus = 1;
		if (s[j] == '-') j++;
		else minus = 0;

		for (int i = j; i < s.size(); i++) {
			if (s[i] == '*' || s[i] == '#') break;
			else ans.push_back(s[i]), j++;
		}

		int num = 0, pow = 1;
		for (int i = ans.size() - 1; i >= 0; i--) {
			num += toChar(ans[i]) * pow;
			pow *= 10;
		}

		if (minus) return -num;
		return num;
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string ans;
		if (root == NULL) return ans;

		queue <TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode* curr = q.front();
			q.pop();

			if (curr == NULL) {
				ans.push_back('#');
				continue;
			} else {
				ans.push_back('*');
				ans += to_string(curr -> val);
			}

			q.push(curr -> left);
			q.push(curr -> right);
		}
		return ans;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty()) return NULL;

		int i = 0;
		TreeNode* root = new TreeNode(change(i, data));
		queue <TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode *curr = q.front();
			q.pop();

			if (data[i] != '#') {
				curr -> left = new TreeNode(change(i, data));
				q.push(curr -> left);
			} else i++;

			if (data[i] != '#') {
				curr -> right = new TreeNode(change(i, data));
				q.push(curr -> right);
			} else i++;
		}

		return root;
	}
};