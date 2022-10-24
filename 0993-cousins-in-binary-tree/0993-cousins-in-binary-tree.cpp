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
    void create(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        if(!root){
            return ;
        }
        if(root->left){
            parent[root->left] = root;
            create(root->left,parent);
        }
        if(root->right){
            parent[root->right] = root;
            create(root->right,parent);
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root] = NULL;
        create(root,parent);
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                auto front = q.front();
                q.pop();
                if(front->val == x){
                    while(!q.empty() and i < n){
                        auto a = q.front();
                        q.pop();
                        i++;
                        if(i < n and a->val == y and parent[a] != parent[front]){
                            return true;
                        }
                    }
                    return false;
                }
                else if(front->val == y){
                    while(!q.empty() and i < n){
                        auto a = q.front();
                        q.pop();
                        i++;
                        if(i < n and a->val == x and parent[a] != parent[front]){
                            return true;
                        }
                    }
                    return false;
                }
                else{
                    if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                }
            }
        }
        return false;
    }
};