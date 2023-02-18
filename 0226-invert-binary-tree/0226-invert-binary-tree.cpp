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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
            
        invert(root,root->left,root->right);
        return root;
    }
    
    void invert(TreeNode* root,TreeNode* a,TreeNode* b){
        if(root==NULL){
            return ;
        }
        root->left=b;
        root->right=a;
        
        if(b!=nullptr)
            invert(root->left,b->left,b->right);
        if(a!=nullptr)
            invert(root->right,a->left,a->right);
    }
};