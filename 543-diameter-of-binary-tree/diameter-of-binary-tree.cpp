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
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){return 0;}
        return max(height(root->left),height(root->right)) +1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int a=diameterOfBinaryTree(root->left);
        int b=diameterOfBinaryTree(root->right);
        int c=height(root->left)+height(root->right);
        return max(a,max(b,c));
    }
};

// // another method mine
// class Solution {
// public:

//     int maxdiameter = 0;

//     int diameterOfBinaryTree(TreeNode* root) {
//         maxHeight(root);
//         return maxdiameter;
//     }

//     int maxHeight(TreeNode* root) {
//         if (root==NULL) return 0; 

//         int x = maxHeight(root->left);
//         int y = maxHeight(root->right);

//         maxdiameter = max(maxdiameter, x+y);

//         return max(x,y) + 1;
//     }
// };