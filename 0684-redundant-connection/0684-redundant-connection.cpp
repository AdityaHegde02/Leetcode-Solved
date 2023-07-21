class Solution {
public:
    unordered_set<int> cycNodes;
    int cycNode = -1;
    
    void find(int cur,int parent,vector<int> adj[],vector<int> &vis){
        if(vis[cur]){
            cycNode = cur;
            return ;
        }
        vis[cur] = 1;
        
        for(auto &child : adj[cur]){
            if(parent == child){
                continue;
            }
            if(cycNodes.empty()){
                find(child,cur,adj,vis);
            }
            if(cycNode != -1){
                cycNodes.insert(cur);
            }
            if(cur == cycNode){
                cycNode = -1;
                return ;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int e = edges.size();
        int n = e;
        vector<int> adj[n + 1];
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        // detect cycle in undirected
        vector<int> vis(n + 1,0);
        find(1,-1,adj,vis);
        
        for(int i = e - 1; i >= 0; i--){
            if(cycNodes.count(edges[i][0]) and cycNodes.count(edges[i][1])){
                return edges[i];
            }
        }
        return {};
    }
};