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
    unordered_map<TreeNode*,int> mp;

    int rob(TreeNode* root) {
        if(!root){
            return 0;
        }

        if(mp.count(root)){
            return mp[root];
        }
        
        int robbed = 0;
        if(root->left){
            robbed += (rob(root->left->left) + rob(root->left->right));
        }

        if(root->right){
            robbed += (rob(root->right->left) + rob(root->right->right));
        }

        return mp[root] = max(root->val + robbed,rob(root->left)+rob(root->right));
    }
};