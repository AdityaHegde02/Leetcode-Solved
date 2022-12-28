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
    void bfs(TreeNode* root, vector<vector<int>> &ans ,int target){
        queue<pair<TreeNode*,pair<int,vector<int>>>> currLevel;       
        currLevel.push( {root , {root->val,{root->val}}} );
        
        while(!currLevel.empty()){
            auto top = currLevel.front();
            TreeNode* currNode = top.first;
            int currSum = top.second.first;
            auto path = top.second.second;
            currLevel.pop();
            
            if(!currNode->left and !currNode->right and currSum == target){
                ans.push_back(path);
            }
            
            if(currNode->left){
                path.push_back(currNode->left->val);
                currLevel.push({currNode->left , {currSum + currNode->left->val,path}});
                path.pop_back();
            }
            
            if(currNode -> right){
                path.push_back(currNode->right->val);
                currLevel.push({currNode->right , {currSum + currNode->right->val,path}});
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        
        if(!root){
            return ans;
        }
        
        bfs(root , ans ,targetSum);
        
        return ans;
    }
};