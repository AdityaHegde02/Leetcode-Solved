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
    bool isEvenOddTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            if(level & 1){          // odd level
                int prev = INT_MAX;
                for(int i = 0; i < sz; i++){
                    auto top = q.front();
                    q.pop();
                    if(top-> val % 2 != 0 or prev <= top->val){
                        return false;
                    }
                    if(top -> left){
                        q.push(top -> left);
                    }
                    if(top -> right){
                        q.push(top -> right);
                    }
                    prev = top->val;
                }
            }
            else{
                int prev = INT_MIN;
                for(int i = 0; i < sz; i++){
                    auto top = q.front();
                    q.pop();
                    if(top-> val % 2 == 0 or prev >= top->val){
                        return false;
                    }
                    if(top -> left){
                        q.push(top -> left);
                    }
                    if(top -> right){
                        q.push(top -> right);
                    }
                    prev = top->val;
                }
            }
            level++;
        }
        return true;
    }
};