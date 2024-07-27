class Solution {
public:
    void solve(int& ans, TreeNode* &prev, TreeNode* root) {
        if (root == NULL) return;
        solve(ans, prev, root->left);
        if (prev) ans = min(ans, abs(prev->val - root->val));
        prev = root;
        solve(ans, prev, root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = NULL;
        solve(ans, prev, root);
        return ans;
    }
};
