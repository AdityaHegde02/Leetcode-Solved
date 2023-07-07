//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int i,vector<int> &vis,vector<int> &pathVis,vector<int> &cyc,vector<int> adj[]){
        vis[i] = 1;
        pathVis[i] = 1;
        
        for(auto &neg : adj[i]){
            if(vis[neg] and pathVis[neg]){
                cyc[i] = 1;
                return true;
            }
            if(!vis[neg]){
                if(dfs(neg,vis,pathVis,cyc,adj)){
                    cyc[i] = 1;
                    return true;
                }
            }
        }
        
        pathVis[i] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V,0),pathVis(V,0),cyc(V,0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,cyc,adj);
            }
        }
        
        vector<int> ans;
        
        for(int i = 0; i < V; i++){
            if(!cyc[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends