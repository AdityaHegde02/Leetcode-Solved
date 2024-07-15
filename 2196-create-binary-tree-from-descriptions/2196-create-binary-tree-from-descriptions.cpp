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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> parents;
        for(auto &i : d){
            int parent = i[0], child = i[1], isLeft = i[2];
            parents.insert(parent);
            if(!mp.count(parent)){
                TreeNode* par = new TreeNode(parent);
                mp[parent] = par;
            }
            if(!mp.count(child)){
                TreeNode* c = new TreeNode(child);
                mp[child] = c;
            }
            if(isLeft){
                mp[parent]->left = mp[child];
            }
            else{
                mp[parent]->right = mp[child];
            }
        }
        for(auto &i : d){
            int parent = i[0], child = i[1];
            if(parents.count(child)){
                parents.erase(child);
            }
            
        }
        return mp[*parents.begin()];
    }
};