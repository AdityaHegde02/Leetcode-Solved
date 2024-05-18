/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x),2` left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    
    // return how much coins subtree needs +,- (+ for excess, - for deficient)
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int l = solve(root->left), r = solve(root->right);
        ans += abs(l) + abs(r);
        return (root->val - 1) + (l + r);
    }
    
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};