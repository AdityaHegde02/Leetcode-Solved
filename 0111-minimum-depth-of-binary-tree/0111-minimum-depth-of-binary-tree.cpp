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
    int mn = INT_MAX;
    
    void solve(TreeNode* &root,int level){
        if(!root){
            return ;
        }
        
        if(!root->left and !root->right){
            mn = min(mn,level);
        }
        
        solve(root->left,level + 1);
        solve(root->right,level+1);
    }
    
    int minDepth(TreeNode* root) {
        solve(root,1);
        return (mn == INT_MAX)?0:mn;
    }
};