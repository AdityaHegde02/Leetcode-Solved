//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    long long mod = 1e9 + 7;
    
    public:
    long long int solve(int num,int sum,int n,int x,vector<vector<int>> &dp){
        if(sum == 0){
            return 1;    
        }

        if(sum < 0 or num > n){
            return 0;
        }
        
        if(dp[num][sum] != -1){
            return dp[num][sum];
        }
        
        //take
        long long int ans = 0;
        
        ans = (ans + solve(num + 1,sum - pow(num,x),n,x,dp)) % mod;
        
        ans = (ans + solve(num + 1,sum,n,x,dp)) % mod;
        
        return dp[num][sum] = ans % mod;
    }
    
    int numOfWays(int n, int x)
    {
        vector<vector<int>> dp(n + 1,vector<int> (n + 1,-1));
        return solve(1,n,n,x,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends