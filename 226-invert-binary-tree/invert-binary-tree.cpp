class Solution {
public:
    void solve(TreeNode* root){
        if(root==NULL) return;
        TreeNode* l=root->left;
        root->left=root->right;
        root->right=l;
        solve(root->left);
        solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};