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
    int sum = 0;
    
    int addValues(vector<int> &path){
        int n = path.size();
        int num = 0;
        for(int i = 0 ; i < n ; i++){
            num = num*10 + (path[i]);
        }
        return num;
    }
    
    void pathSums(TreeNode* root, vector<int> &path){
        if(!root){
            return ;
        }
        
        path.push_back( root->val );
        
        if(!root->left and !root->right){
            sum += addValues(path);
            path.pop_back();
            return ;
        }
        
        pathSums(root->left , path);
        
        pathSums(root->right , path);
        
        path.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        vector<int> path;
        pathSums(root , path);
        return sum;
    }
};