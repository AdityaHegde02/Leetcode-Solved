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
    pair<int,int> getMinMax(TreeNode* root, int &maxDiff){
        if(!root){                          // when node is null
            return {INT_MAX,INT_MIN};
        }
        
        if(!root->left and !root->right){
            return {root->val,root->val};
        }
        
        auto leftMinMax = getMinMax(root->left, maxDiff);
        auto rightMinMax = getMinMax(root->right, maxDiff);
        
        int Min = min( leftMinMax.first , rightMinMax.first );
        int Max = max( leftMinMax.second , rightMinMax.second );
        
        int x = 0 , y = 0;
        if(Min != INT_MAX)
            x = abs( root->val - Min );
        if(Max != INT_MIN)
            y = abs( root->val - Max );
        
        maxDiff = max( maxDiff , max( x,y ) );
        Min = min(Min,root->val);
        Max = max(Max,root->val);
        return {Min,Max};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = INT_MIN;
        getMinMax(root, maxDiff);
        return maxDiff;
    }
};