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
    unordered_map<string,TreeNode*> nodes;
    
    string solve(TreeNode* &root){
        if(!root){
            return "";
        }
        
        string a = solve(root->left);
        string b = solve(root->right);
        
        a += to_string(root->val) + '_' + a + '_'+ b + '_';
        if(count.find(a) != count.end()){
            count[a]++;
        }
        else{
            count[a] = 1;
        }
        
        if(nodes.find(a) == nodes.end())
            nodes[a] = root;
        
        return a;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        solve(root);
        for(auto &i:count){
            if(i.second > 1){
                ans.push_back(nodes[i.first]);
            }
        }
        return ans;
    }
};