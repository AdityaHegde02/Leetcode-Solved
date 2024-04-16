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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root){
            return NULL;
        }
        
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }
        
        queue<pair<int,TreeNode*>> q;
        q.push({1,root});
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            TreeNode* x = top.second;
            int level = top.first;
            
            if(level == depth - 1){
                TreeNode* prevLeft = x->left;
                TreeNode* prevRight = x->right;
                x -> left = new TreeNode(val);
                x -> right = new TreeNode(val);
                x -> left -> left = prevLeft;
                x -> right -> right = prevRight;
            }
            else{
                if(x->left){
                    q.push({level+1,x->left});
                }
                if(x->right){
                    q.push({level+1,x->right});
                }
            }
        }
        
        return root;
    }
};