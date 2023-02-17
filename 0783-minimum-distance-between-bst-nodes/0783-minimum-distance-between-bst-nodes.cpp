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
    // inorder
    void solve(TreeNode* root,TreeNode* &prevNode,int &minDiff){
        if(!root){
            return ;
        }
        // if(root->left)
            solve(root->left,prevNode,minDiff);
        
        if(prevNode != NULL){
            minDiff = min(minDiff, root->val - (prevNode->val));
        }
                          
        prevNode = root;
        
        // if(root->right)
            solve(root->right, prevNode, minDiff);
    }
    
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        
        TreeNode* prevNode = NULL;
        
        solve(root,prevNode,minDiff);
        
        return minDiff;
    }
};