class Solution {
public:
    int solve(TreeNode* root, int& ans) {
        if (root == NULL) return 0;
        int left = max(0, solve(root->left, ans));
        int right = max(0, solve(root->right, ans));
        int curr = root->val + left + right;
        ans = max(ans, curr);
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};
