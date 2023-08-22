/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution { //100% self
// public://in particuler level update values each time
//     // for left view if there is value exist in particular level then dont update it
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         if(root==NULL)return ans;
//         map<int,int> leftnode;
//         // lvl,value
//         queue<pair<TreeNode*,int>> q;
//         //            node , lvl
//         q.push({root,0});
//         while(!q.empty())
//         {
//             auto temp=q.front();
//             q.pop();
//             TreeNode* frontnode=temp.first;
//             int lvl=temp.second;
//             leftnode[lvl]=frontnode->val;
//             if(frontnode->left!=NULL)
//             {
//                 q.push({frontnode->left,lvl+1});
//             }
//             if(frontnode->right!=NULL)
//             {
//                 q.push({frontnode->right,lvl+1});
//             }
//         }
//     for(auto i:leftnode){
//         ans.push_back(i.second);
//     }
//     return ans;
//     }
// };

// method 2
class Solution{
public:
void solve(TreeNode* root,vector<int>& ans,int level)
{
    if(root==NULL)return;
    if(level==ans.size()){
        ans.push_back(root->val);
    }
    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}

vector<int> rightSideView(TreeNode* root){
   vector<int> ans;
   int level=0;
   solve(root,ans,level);
   return ans;
}
};

