class Solution {
public:
    void dfs(int i,vector<int> &vis,vector<vector<int>> &adj){
        vis[i] = 1;
    
        for(auto &neg : adj[i]){
            if(!vis[neg]){
                dfs(neg,vis,adj);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0);
        int sz = connections.size();
        if(sz < (n - 1)){
            return -1;
        }
        vector<vector<int>> adj(n);
        for(int i = 0; i < sz; i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int components = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                components++;
            }
        }
        
        return components - 1;
    }
};