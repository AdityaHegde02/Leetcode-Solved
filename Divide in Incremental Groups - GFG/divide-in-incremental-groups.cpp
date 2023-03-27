//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[101][101][101];
    
    int solve(int N,int K,int prev){
        if(K < 0 or N < 0 or prev < 0){
            return 0;
        }
        
        if(K == 0){
            return (N == 0);
        }    
        
        if(dp[N][K][prev] != -1){
            return dp[N][K][prev];
        }
        
        int ans = 0;
        
        for(int i = prev; i > 0; i--){
            ans += solve(N - i, K - 1, i);
        }
        
        dp[N][K][prev] = ans;
        return ans;
    }
    
    int countWaystoDivide(int N, int K) {
        memset(dp,-1,sizeof(dp));
        return solve(N,K,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends