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
    unordered_map<string,int> count;
    vector<TreeNode*> ans;
    
    string solve(TreeNode* &root){
        if(!root){
            return "";
        }
        
        string a = solve(root->left);
        string b = solve(root->right);
        
        a += to_string(root->val) + '_' + a + '_'+ b + '_';
        if(count[a] == 1){
            ans.push_back(root);
        }
    
        count[a]++;
        
        return a;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};