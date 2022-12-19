class Solution {
public:
    void dfs(int i,int n,vector<vector<int>>& adj,vector<int> &vis){
        if(i >= n){
            return ;
        }
        vis[i] = 1;
        for(auto &a : adj[i]){
            if(vis[a] == 0)
                dfs(a,n,adj,vis);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(source,n,adj,vis);
        return (vis[destination] == 1);
    }
};