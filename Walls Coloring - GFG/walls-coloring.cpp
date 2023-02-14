//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    int dp[100001][3];
    
    int solve(int i,int n,vector<vector<int>> &colors,int prev){
        if(i >= n){
            return 0;
        }
        
        if(prev != -1 and dp[i][prev] != INT_MAX){
            return dp[i][prev];
        }
        
        if(prev == -1){
            return dp[i][prev] = min({colors[i][0] + solve(i + 1,n,colors,0),colors[i][1] + solve(i + 1,n,colors,1),colors[i][2] + solve(i + 1,n,colors,2)});
        }
        
        else if(prev == 0){
            return dp[i][prev] = min({colors[i][1] + solve(i + 1,n,colors,1),colors[i][2] + solve(i + 1,n,colors,2)});
        }
        
        else if(prev == 1){
            return dp[i][prev] = min({colors[i][0] + solve(i + 1,n,colors,0),colors[i][2] + solve(i + 1,n,colors,2)});
        }
        
        else{
            return dp[i][prev] = min({colors[i][0] + solve(i + 1,n,colors,0),colors[i][1] + solve(i + 1,n,colors,1)});
        }
        
        return 0;
    }
    
    int minCost(vector<vector<int>> &colors, int N) {
        for(int i = 0; i < 100001; i++){
            for(int j = 0; j < 3; j++){
                dp[i][j] = INT_MAX;
            }
        }
        return solve(0,N,colors,-1);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends