class Solution {
public: 
    vector<int> in;
    unordered_map<int,TreeNode*> mp;
    
    void inorder(TreeNode* &root){
        if(!root){
            return ;
        }
        
        mp[root->val] = root;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<int> cpy = in;
        sort(cpy.begin(),cpy.end());
        vector<int> a;
        for(int i = 0; i < in.size(); i++){
            if(cpy[i] != in[i]){
                a.push_back(cpy[i]);
            }
        }
        mp[a[0]]->val = a[1];
        mp[a[1]]->val = a[0];
    }
};