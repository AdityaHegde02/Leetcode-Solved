//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N + 1][W + 1];
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= W; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i <= N; i++){            // each item
            for(int j = 1; j <= W; j++){
                if(wt[i - 1] <= j){
                    dp[i][j] = max(dp[i-1][j],val[i - 1] + dp[i][j - wt[i - 1]]);
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[N][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends