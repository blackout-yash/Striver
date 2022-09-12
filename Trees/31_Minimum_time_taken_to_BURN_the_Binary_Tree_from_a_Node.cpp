// Burning Tree
// Link - https://practice.geeksforgeeks.org/problems/burning-tree/1



class Solution {
public:
	int minTime(Node* root, int _target) {
		int ans = 0;
		if (root == NULL) return ans;

		map <Node*, Node*> par;
		queue <Node*> q;
		q.push(root);

		Node* target;
		while (!q.empty()) {
			Node* curr = q.front();
			q.pop();

			if (curr -> data == _target) target = curr;

			if (curr -> left != NULL) {
				par[curr -> left] = curr;
				q.push(curr -> left);
			}
			if (curr -> right != NULL) {
				par[curr -> right] = curr;
				q.push(curr -> right);
			}
		}

		map <Node*, int> dis;
		dis[target] = 0;
		q.push(target);

		while (!q.empty()) {
			Node* curr = q.front();
			q.pop();

			if (par.count(curr) && !dis.count(par[curr])) {
				dis[par[curr]] = 1 + dis[curr];
				q.push(par[curr]);
			}

			if (curr -> left != NULL && !dis.count(curr -> left)) {
				dis[curr -> left] = 1 + dis[curr];
				q.push(curr -> left);
			}

			if (curr -> right != NULL && !dis.count(curr -> right)) {
				dis[curr -> right] = 1 + dis[curr];
				q.push(curr -> right);
			}

			ans = max(ans, dis[curr]);
		}
		return ans;
	}
};