//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<int>adj[],int src,vector<bool>&vis,vector<int>&v){

        vis[src]=1;

        v.push_back(src);

        for(auto i:adj[src]){

            if(!vis[i])

            dfs(adj,i,vis,v);

        }

    }

    int findNumberOfGoodComponent(int v, vector<vector<int>>&graph) {

        vector<int>adj[v+1];

        for(int i=1;i<=v;i++){

            for(auto j:graph[i]){

                adj[i].push_back(j);

            }
        }

        vector<vector<int>>st;

        vector<bool>vis(v+1,0);

        for(int i=1;i<=v;i++){

            if(!vis[i]){

                vector<int>v;

                dfs(adj,i,vis,v);

                st.push_back(v);

            }

        }

        int ans=0;

        for(auto i:st){

            int n=i.size();

            int count=0;

            for(auto j:i){

                if(adj[j].size()==(n-1))

                count++;

            }

            if(count==n)

            ans++;

        }

        return ans;

    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends