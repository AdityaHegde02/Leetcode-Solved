class Solution {
public:
    TreeNode* startNode = NULL;
    TreeNode* find(TreeNode* root,int start){
        if(!root){
            return NULL;
        }
        if(root->val == start){
            startNode = root;
        }
        find(root->left,start);
        find(root->right,start);
        return NULL;
    }
    
    void findParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &par){
        if(!root){
            return ;
        }
        
        if(root->left){
            par[root->left] = root;
        }
        if(root->right){
            par[root->right] = root;
        }
        
        findParents(root->left,par);
        findParents(root->right,par);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        find(root,start);
        queue<TreeNode*> q;
        q.push(startNode);
        int t = 0;
        unordered_set<TreeNode*> vis;
        vis.insert(startNode);
        unordered_map<TreeNode*,TreeNode*> par;
        par[root] = NULL;
        findParents(root,par);
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* top = q.front();
                q.pop();
                
                if(top->left and vis.find(top->left) == vis.end()){
                    q.push(top->left);
                    vis.insert(top->left);
                }
                if(top->right and vis.find(top->right) == vis.end()){
                    q.push(top->right);
                    vis.insert(top->right);
                }
                if(par[top] != NULL and vis.find(par[top]) == vis.end()){
                    q.push(par[top]);
                    vis.insert(par[top]);
                }
            }
            t++;
        }
        return t-1;
    }
};