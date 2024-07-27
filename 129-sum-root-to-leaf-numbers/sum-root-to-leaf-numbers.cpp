class Solution {
public:
    void solve(TreeNode* root,int& ans,int num){ //self
        if(root==NULL) return; 
        num= num*10 + root->val;
        if(root->left==NULL && root->right==NULL) ans+=num;
        solve(root->left,ans,num);
        solve(root->right,ans,num);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0,num=0;
        solve(root,ans,num);
        return ans;
    }
};