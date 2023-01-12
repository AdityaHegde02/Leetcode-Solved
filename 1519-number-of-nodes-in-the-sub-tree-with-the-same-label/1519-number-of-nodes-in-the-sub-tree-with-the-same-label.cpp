class Solution {
public:

    vector<int> dfs(int src, vector<int> adj[], vector<int>& vis, string& labels, vector<int>& ans) {
        vis[src] = 1;
        
        vector<int> parentcnt(26,0), childcnt(26,0);

        parentcnt[labels[src] - 'a'] = 1;

        for(auto child : adj[src]) {
            if(!vis[child]) {
                childcnt = dfs(child,adj,vis,labels,ans);
                for(int k=0;k<26;k++) {
                    parentcnt[k] += childcnt[k];
                }
            }
        }

        ans[src] = parentcnt[labels[src] - 'a'];
        return parentcnt;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> vis(n,0);
        vector<int> ans(n);

        vector<int> adj[n];

        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,adj,vis,labels,ans);

        return ans;
    }
};