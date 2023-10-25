//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    
    int solve(int i,int N,int W,int val[],int wt[]){
        if(i >= N){
            return 0;
        }
        
        if(dp[i][W] != -1){
            return dp[i][W];
        }
        
        int take = 0;
        if(wt[i] <= W)
            take = val[i] + solve(i,N,W - wt[i],val,wt);
            
        int notake = solve(i + 1,N,W,val,wt);
        
        return dp[i][W] = max(take,notake);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,N,W,val,wt);
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