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
class CBTInserter {
public:
    TreeNode* rootNode;
    queue<TreeNode*> q;
    
    CBTInserter(TreeNode* root) {
        rootNode = root;
        q.push(root);
        while(!q.empty()){
            auto front = q.front();
            if(front->left and front->right){
                q.push(front->left);
                q.push(front->right);
                q.pop();
            }
            else if(front->left){
                q.push(front->left);
                return ;
            }
            else{
                return ;
            }
        }
    }
    
    int insert(int val) {
        auto front = q.front();
        TreeNode* newNode = new TreeNode(val);
        if(!front->left){
            front->left = newNode;
        }
        else{
            front->right = newNode;
            q.pop();
        }
        q.push(newNode);
        return front->val;
    }
    
    TreeNode* get_root() {
        return rootNode;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */