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
    int ans = 0;
    // curr node,next dir
    int solve(TreeNode* &root,int dir){
        if(!root){
            return 0;
        }  
        
        int left = solve(root->left,2);
        int right = solve(root->right,1);
        
        ans = max(ans,max(left,right));
        
        if(dir == 1){
            return 1 + left;
        }
        if(dir == 2){
            return 1 + right;
        }
        
        return 0;
    }
    
    int longestZigZag(TreeNode* root) {
        int t = max(solve(root,1),solve(root,2));
        return ans;
    }
};