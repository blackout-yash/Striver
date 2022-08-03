// 543. Diameter of Binary Tree
// Link - https://leetcode.com/problems/diameter-of-binary-tree/



#include <iostream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        val = data;
        left = right = NULL;
    }
};

class Solution {
public:
    int maxDepth(int &diameter, TreeNode* root) {
        if (root == NULL) return 0;

        int left = maxDepth(diameter, root -> left);
        int right = maxDepth(diameter, root -> right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxDepth(diameter, root);

        return diameter;
    }
};

int main() {
    class TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> left -> right -> left = new TreeNode(6);
    root -> right -> left = new TreeNode(7);
    root -> right -> right = new TreeNode(8);
    root -> right -> right ->left = new TreeNode(9);
    root -> right -> right ->right = new TreeNode(10);

    Solution sol;
    cout << sol.diameterOfBinaryTree(root);

    return 0;
}