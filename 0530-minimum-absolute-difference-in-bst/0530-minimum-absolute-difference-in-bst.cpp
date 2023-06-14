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
    vector<int> in;
    
    void inorder(TreeNode* root){
        if(!root){
            return ;
        }
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        
        int mindiff = INT_MAX;
        
        for(int i = 0 ; i < in.size()-1 ;i++){
            mindiff = min( mindiff , in[i+1]-in[i] );
        }
        
        return mindiff;
    }
};