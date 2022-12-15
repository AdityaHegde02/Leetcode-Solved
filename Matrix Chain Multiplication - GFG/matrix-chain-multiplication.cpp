//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    
    int solve(int i,int j,int N,int arr[]){
        if(i >= j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            int temp = solve(i,k,N,arr) + solve(k+1,j,N,arr) + (arr[i-1]*arr[j]*arr[k]);
            ans = min(ans,temp);
        }
        
        return dp[i][j] = ans;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        int i = 1, j = N - 1;
        memset(dp,-1,sizeof(dp));
        return solve(i,j,N,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends