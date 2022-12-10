class Solution {
public:
    int mod = 7 + 1e9;
    long long ans = 0;
    long long totalSum = 0;

    long long solve(TreeNode* root){
        if(!root){
            return 0;
        }

        long long left = solve(root->left);
        long long right = solve(root->right);

        return root->val += left + right;
    }

    void generate(TreeNode* root){
        if(!root){
            return ;
        }

        ans = max(ans,(long long)((root->val)*(totalSum - root->val)));

        generate(root->left);
        generate(root->right);
    }

    int maxProduct(TreeNode* root) {
        totalSum = solve(root);
        generate(root);
        return (ans)%mod;
    }
};