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
    void inorder(TreeNode* root,vector<int> &sorted){
        if(!root){
            return ;
        }
        inorder(root->left,sorted);
        sorted.push_back(root->val);
        inorder(root->right,sorted);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> sorted;
        inorder(root,sorted);
        for(int i = 0; i < queries.size() ; i++){
            int st = -1,en = -1;
            int target = queries[i];
            auto it = lower_bound(sorted.begin(),sorted.end(),target);
            int idx = it - sorted.begin();
            if(it != sorted.end() and idx > 0){
                if(target == sorted[idx]){
                    st = target;
                    en = target;
                }
                else{
                    en = sorted[idx];
                    st = sorted[idx- 1];
                }
            }
            else if(idx == 0){
                if(target == sorted[idx]){
                    st = target;
                    en = target;
                }
                else{
                    en = sorted[0];
                }
            }
            else{
                st = sorted[sorted.size() - 1];
            }
            ans.push_back({st,en});
        }
        return ans;
    }
};