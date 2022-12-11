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
    int ans = INT_MIN;
    
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int leftS = solve(root->left);          // hypothesis
        int rightS = solve(root->right);
        
        int temp = max(leftS + root->val,rightS + root->val);
        ans = max({ans,temp,leftS + rightS + root->val,root->val});
        
        return max(0,temp);
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};