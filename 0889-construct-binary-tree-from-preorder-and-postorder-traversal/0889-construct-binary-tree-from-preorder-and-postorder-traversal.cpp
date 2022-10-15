class Solution {
public:
    TreeNode* constuctFromRange(vector<int>& pre, vector<int>& post, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return NULL;
        TreeNode *root = new TreeNode(pre[s1]);
        if (s1 == e1) return root;
        int m1 = s1 + 1, m2 = s2;
        int set1 = 0, set2 = 0;
        while (set1 == 0 || set1 != set2) {
            set1 = set1 | (1 << pre[m1++]);
            set2 = set2 | (1 << post[m2++]);
        }
        root->left = constuctFromRange(pre, post, s1 + 1, m1 - 1, s2, m2 - 1);
        root->right = constuctFromRange(pre, post, m1, e1, m2, e2);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return constuctFromRange(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }
};