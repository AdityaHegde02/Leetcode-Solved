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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root){
            return NULL;
        }
        
        if(!root->left and !root->right){
            if(root->val == target){
                return NULL;
            }
            return root;
        }
        
        TreeNode* l = removeLeafNodes(root->left,target);
        TreeNode* r = removeLeafNodes(root->right,target);
        
        if(root->val == target){
            if(l == NULL and r == NULL){
                return NULL;
            }
        }
        
        root->left = l; 
        root->right = r;
        return root;
    }
};