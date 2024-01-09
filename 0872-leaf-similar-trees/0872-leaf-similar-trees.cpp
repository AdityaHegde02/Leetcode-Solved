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
    void inorder(TreeNode* root,vector<int> &a){
        if(!root){
            return;
        }

        inorder(root->left,a);
        if(!root->left and !root->right){
            a.push_back(root->val);
        }
        inorder(root->right,a);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2){
            return true;
        }
        if(!root1 or !root2){
            return false;
        }

        vector<int> a,b;
        inorder(root1,a);
        inorder(root2,b);

        if(a.size() != b.size()){
            return false;
        }

        for(int i = 0; i < a.size() ; i++){
            if(a[i] != b[i]){
                return false;
            }
        }

        return true;
    }
};