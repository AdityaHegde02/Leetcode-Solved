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
    int geth(TreeNode* root){
        if(!root){
            return 0;
        }
        int lh = geth(root->left);
        int rh = geth(root->right);
        return max(lh,rh)+1;
    }
    
    int get(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh = geth(root->left);
        int rh = geth(root->right);
        int ld = get(root->left);
        int rd = get(root->right);
        int ans =max(ld,rd);
        return max(lh+rh+1,ans);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int a = get(root);
        return a-1;
    }
};