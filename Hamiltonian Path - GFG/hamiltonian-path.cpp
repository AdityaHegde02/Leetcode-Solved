//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool solve(int curr,vector<bool> visited,vector<vector<int>> Edges,unordered_map<int,vector<int>> adj,int N,int M){
        if(curr > N){
            return false;
        }
        visited[curr] = true;
        
        bool allOver = 1;
        for(int i = 1 ; i <= N ; i++){
            if(!visited[i]){
                allOver = 0;
                break;
            }
        }
        
        if(allOver){
            return true;
        }
        
        for(auto &node : adj[curr]){
            if(!visited[node]){
                bool f = solve(node,visited,Edges,adj,N,M);
                if(f){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<bool> visited(N+1,0);
        unordered_map<int,vector<int>> adj;
        
        for(int i = 0 ; i < M; i++){
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        
        for(int i = 1; i <= N; i++){
            bool path = solve(i,visited,Edges,adj,N,M);
            if(path == true){
                return true;
            }
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends