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
    pair<int,int> sumandcount(TreeNode* root,int &ans){
        
        if(root==NULL){
            return {0,0};
        }
        
        auto left=sumandcount(root->left,ans);
        auto right=sumandcount(root->right,ans);
        
        int sum=(root->val)+left.first+right.first;
        int n=(1)+left.second+right.second;
        int avg=(sum/n);
        
        if(avg==(root->val)){
            ans++;
        }
        
        return {sum,n};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        pair<int,int> x=sumandcount(root,ans);
        return ans;
    }
};