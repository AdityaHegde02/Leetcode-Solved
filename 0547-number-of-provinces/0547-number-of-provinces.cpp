class Solution {
public:
    void dfs(int i,vector<int> adj[],vector<int> &vis){
        vis[i] = 1;
        for(auto &j : adj[i]){
            if(!vis[j]){
                dfs(j,adj,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n + 1];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j and isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<int> vis(n + 1,0);
        int comp = 0;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                comp++;
            }
        }
        
        return comp;
    }
};