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
    TreeNode* solve(TreeNode* root,TreeNode* parent,int low,int high){
        if(!root){
            return NULL;
        }
        
        if(parent == NULL){
            if(root->val < low){
                return solve(root->right,NULL,low,high);
            }
            
            else if(root->val > high){
                return solve(root->left,NULL,low,high);
            }
            
            else{
                solve(root->left,root,low,high);
                solve(root->right,root,low,high);
            }
            
            return root;
        }
        
        else{
            if(root->val < low){
                return parent -> left =  solve(root->right,parent,low,high);
            }
            
            else if(root->val > high){
                return parent -> right = solve(root->left,parent,low,high);
            }
            
            else{
                solve(root->left,root,low,high);
                solve(root->right,root,low,high);
            }
            
            return root;
        }
        
        return root;
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       if(!root){
           return NULL;
       } 
        
       return solve(root,NULL,low,high);
    }
};