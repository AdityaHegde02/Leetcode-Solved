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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
         if(root==NULL)
             return ans;
        queue<pair<TreeNode*,int>>q;
        unordered_map<int,int>mp;
        
        q.push({root,0});

        while(!q.empty())
        {
            TreeNode* temp=q.front().first;
            int lvl=q.front().second;
            q.pop();
            
            mp[lvl]=temp->val;
            if(temp->left)
            {
                q.push({temp->left,lvl+1});
            }
            if(temp->right)
            {
                q.push({temp->right,lvl+1});
            }
        }

        int sz = mp.size();
   
        for(int i = 0; i < sz; i++)
        {
            ans.push_back(mp[i]);
        }

        return ans;
    }
};