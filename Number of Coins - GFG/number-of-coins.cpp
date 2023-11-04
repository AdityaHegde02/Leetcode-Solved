//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int i,int M,int V,int coins[],vector<vector<int>> &dp){
	    if(i >= M){
	        if(V == 0){
	            return 0;
	        }
	        return INT_MAX;
	    }
	    
	    if(dp[i][V] != INT_MAX){
	        return dp[i][V];
	    }
	    
	    // take
	    int take = INT_MAX;
	    if(coins[i] <= V){
	        int t = solve(i,M,V - coins[i],coins,dp);
	        take = (t == INT_MAX) ? t : t + 1;
	    }
	    
	    // no take
	    int notake = solve(i + 1,M,V,coins,dp);
	   
	    return dp[i][V] = min(take,notake);
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	   vector<vector<int>> dp(M + 1,vector<int> (V + 1,INT_MAX)); 
	   int t = solve(0,M,V,coins,dp);
	   return (t == INT_MAX) ? -1 : t;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends