// 124. Binary Tree Maximum Path Sum
// Link - https://leetcode.com/problems/binary-tree-maximum-path-sum/



class Solution {
public:
    int maxPathSum(int &ans, TreeNode* root) {
        if (root == NULL) return 0;

        int left = max(0, maxPathSum(ans, root -> left));
        int right = max(0, maxPathSum(ans, root -> right));

        int curr = (root -> val) + left + right;
        ans = max(ans, curr);

        return (root -> val) + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        maxPathSum(ans, root);

        return ans;
    }
};