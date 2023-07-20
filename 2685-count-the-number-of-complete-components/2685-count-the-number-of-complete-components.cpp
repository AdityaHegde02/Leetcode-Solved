class Solution {
public:
    void solve(int i,int &nodes,int &edges,vector<int> &vis,vector<vector<int>> &adj){
        vis[i] = 1;
        nodes++;
        for(auto &j : adj[i]){
            edges++;
            if(!vis[j]){
                solve(j,nodes,edges,vis,adj);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int complete = 0;
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int nodes = 0, edges = 0;
                solve(i,nodes,edges,vis,adj);
                complete += (edges == (nodes)*(nodes - 1));
            }
        }
        
        return complete;
    }
};