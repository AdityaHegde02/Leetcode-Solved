class Solution {
public:
    int ans = 1;
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        dfs(0, -1, s, adj);
        return ans;
    }

    int dfs(int curr, int parent, string& s,     vector<vector<int>>& adj) {
        int maxLen = 1;
        for(auto child: adj[curr]) {
            if(child != parent) {
                int temp = dfs(child, curr, s, adj);
                if(s[curr] != s[child]) {
                    ans = max(ans, maxLen + temp);
                    maxLen = max(maxLen, 1 + temp);
                }
            }
        }
        return maxLen;
    }
};