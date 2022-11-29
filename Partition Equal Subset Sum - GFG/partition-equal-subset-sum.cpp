//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[202][10002];
    
    bool subsetSum(int n,int nums[],int target){
        if(target == 0){
            return 1;
        }
        
        if(n <= 0 or target < 0){
            return 0;
        }
        
        if(dp[n - 1][target] != -1){
            return dp[n - 1][target];
        }
        
        if(nums[n - 1] <= target){
            return dp[n - 1][target] = (subsetSum(n-1,nums,target - nums[n - 1])) or (subsetSum(n - 1,nums,target));
        }
        
        return dp[n - 1][target] = subsetSum(n - 1,nums,target);
    }
    
    int equalPartition(int N, int nums[])
    {
        int totalSum = 0;
        for(int i = 0; i < N; i++){
            totalSum += nums[i];
        }
        
        if(totalSum % 2){
            return false;
        }
        
        int target = (totalSum)/2;
        memset(dp,-1,sizeof(dp));
        
        return subsetSum(N,nums,target);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends