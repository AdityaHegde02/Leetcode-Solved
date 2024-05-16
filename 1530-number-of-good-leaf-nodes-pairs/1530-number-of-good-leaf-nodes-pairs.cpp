class Solution {
public:
    vector<TreeNode*> leaves;
    unordered_map<TreeNode*,TreeNode*> parent;
    
    void getLeaves(TreeNode* root){
        if(!root->left and !root->right){
            leaves.push_back(root);
            return ;
        }
        
        if(root->left){
            parent[root->left] = root;
            getLeaves(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            getLeaves(root->right);
        }
    }
    
    int countPairs(TreeNode* root, int distance) {
        getLeaves(root);
        parent[root] = NULL;
        int good = 0;
        for(int i = 0; i < leaves.size(); i++){
            queue<TreeNode*> q;
            q.push(leaves[i]);
            unordered_set<TreeNode*> vis;
            int l = 0;
            while(!q.empty() and l <= distance){
                int n = q.size();
                for(int j = 0; j < n; j++){
                    auto f = q.front();
                    q.pop();
                    vis.insert(f);
                    if(l != 0 and !f->left and !f->right){
                        good++;
                    }
                    if(f->left and !vis.count(f->left)){
                        q.push(f->left);
                    }
                    if(f->right and !vis.count(f->right)){
                        q.push(f->right);
                    }
                    if(parent[f] and !vis.count(parent[f])){
                        q.push(parent[f]);
                    }
                }
                l++;
            }
        }
        return good/2;
    }
};