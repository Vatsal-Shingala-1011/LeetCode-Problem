class Solution {
public:
    bool solve(TreeNode* root,long long max,long long min){
        if(root==NULL) return true;
        if(root->val<max && root->val>min){
            bool left=solve(root->left,root->val,min);
            bool right=solve(root->right,max,root->val);
            return left&&right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MAX,LLONG_MIN);
    }
};