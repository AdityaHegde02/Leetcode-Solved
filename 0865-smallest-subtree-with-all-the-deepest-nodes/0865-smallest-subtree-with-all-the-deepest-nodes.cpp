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
    unordered_map<TreeNode*,TreeNode*> parent;
    
    void Parents(TreeNode* a){
        if(!a){
            return ;
        }
        
        if(a->left){
            parent[a->left] = a;
        }
        if(a->right){
            parent[a->right] = a;
        }
        
        Parents(a->left);
        Parents(a->right);
    }
    
    TreeNode* LCA(TreeNode* a,TreeNode* b){
        while(a != b){
            a = parent[a];
            b = parent[b];
        }
        
        return a;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root){
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* first = root;
        TreeNode* last = root;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* top = q.front();
                q.pop();
                if(i == 0){
                    first = top;
                }
                if(i == n - 1){
                    last = top;
                }
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
        
        Parents(root);
        
        return LCA(first,last);
    }
};