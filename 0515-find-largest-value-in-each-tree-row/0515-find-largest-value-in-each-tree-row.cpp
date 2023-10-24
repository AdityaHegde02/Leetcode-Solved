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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int mx=INT_MIN;
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            if(top){
                mx = max(mx,top->val);
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            else{
                if(!q.empty()){
                    ans.push_back(mx);
                    q.push(NULL);
                    mx = INT_MIN;
                }
            }
        }
        ans.push_back(mx);
        return ans;
    }
};