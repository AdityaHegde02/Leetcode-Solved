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
    int calcSwaps(vector<int> &temp){
        int n = temp.size();
        unordered_map<int,int> valIdx;    //{val,idx}
        for(int i = 0; i < n; i++){
            valIdx[temp[i]] = i;
        }
        int s = 0;
        vector<int> copy = temp;
        sort(temp.begin(),temp.end());
        for(int i = 0; i < n; i++){
            if(temp[i] != copy[i]){
                int crctIdx = valIdx[temp[i]];
                valIdx[temp[i]] = i;
                valIdx[copy[i]] = crctIdx;
                swap(copy[i],copy[crctIdx]);
                s++;
            }
        }
        return s;
    }
    
    int minimumOperations(TreeNode* root) {
        int ops = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i = 0; i < n; i++){
                auto top = q.front();
                q.pop();
                temp[i] = (top->val);
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            ops += calcSwaps(temp);
        }
        return ops;
    }
};
