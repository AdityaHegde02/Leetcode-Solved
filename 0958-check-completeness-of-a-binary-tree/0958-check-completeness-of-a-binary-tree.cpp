class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int gotNull = 0;
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> level;
            for(int i = 0; i < n; i++){
                auto top = q.front();
                q.pop();
                level.push_back(top);
                if(top){
                    if(gotNull == 1){
                        return false;
                    }
                    q.push(top->left);
                    q.push(top->right);
                }
            }
            
            int got = 0;
            for(int i = 0; i < level.size(); i++){
                if(got == 0 and level[i] == nullptr){
                    got++;
                }
                else if(got and level[i] != nullptr){
                    return false;
                }
                if(i == level.size() - 1 and level[i] == nullptr){
                    gotNull = 1;
                }
            }
        }
        
        return true;
    }
};