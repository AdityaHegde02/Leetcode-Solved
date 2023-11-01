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
    unordered_map<int,int> mp;
    
    void inorder(TreeNode* root){
        if(!root){
            return ;
        }
        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        vector<int> ans;
        int mx = 0;
        for(auto &i:mp){
            mx = max(i.second,mx);
        }
        for(auto &i:mp){
            if(i.second==mx){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};