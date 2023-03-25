class Solution {
public:
    void dfs(int i,int &size,vector<int> &vis,vector<vector<int>> &adj){
        vis[i] = 1;
        
        size++;
        
        for(auto &neighbour : adj[i]){
            if(!vis[neighbour]){
                dfs(neighbour,size,vis,adj);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        
        vector<vector<int>> adj(n);
        
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> vis(n,0);
        
        long long int got = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int size = 0;
                dfs(i,size,vis,adj);
                ans += (got)*size;
                got += size;
            }
        }
        
        return ans;
    }
};