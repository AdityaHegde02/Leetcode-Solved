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
    
    int solve(TreeNode* &root,int value){
        if(!root){
            return 0;
        }
        
        int temp = 0;           // returning value
        if(root->val == value){
            int l = solve(root->left,value);
            int r = solve(root->right,value);
            if(l != 0 and r != 0){
                temp = 1 + max(l,r);
                ans = max(ans,l + r + 1);
            }
            else{
                temp = l + r + 1;
            }
            ans = max(ans,temp);
        }
        
        else{
            int l = solve(root->left,root->val), r = solve(root->right,root->val);
            if(l != 0 and r != 0){
                temp = max(l,r) + 1;
                ans = max(ans,l + r + 1);
            }
            else{
                temp = l + r + 1;
            }
            ans = max(ans,temp);
        }
                      
        return (root->val == value)?(temp):0;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        solve(root,root->val);
        
        return ans - 1;
    }
};