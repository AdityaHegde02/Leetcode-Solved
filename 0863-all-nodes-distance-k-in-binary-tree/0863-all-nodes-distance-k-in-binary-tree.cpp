class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    
    void parents(TreeNode* root){
        if(!root){
            return ;
        }
        
        if(root->left){
            parent[root->left] = root;
        }
        if(root->right){
            parent[root->right] = root;
        }
        
        parents(root->left);
        parents(root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent[root] = NULL;
        parents(root);
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> st;
        st.insert(target);
        k++;
        while(!q.empty() and k){
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++){
                auto top = q.front();
                st.insert(top);
                if(k == 1){
                    temp.push_back(top->val);
                }
                q.pop();
                if(top->left and st.find(top->left) == st.end()){
                    q.push(top->left);
                }
                if(top->right and st.find(top->right) == st.end()){
                    q.push(top->right);
                }
                if(parent[top] != NULL and st.find(parent[top]) == st.end()){
                    q.push(parent[top]);
                }
            }
            k--;
            if(k == 0){
                return temp;
            }
        }
        return {};
    }
};