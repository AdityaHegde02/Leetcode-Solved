//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    int MOD = 1e9 + 7;
	public:
	int solve(int arr[], int n, int sum,vector<vector<int>> &dp)
	{
        if(n<0){
            return 0;
        }
        if(n==0){
            if(sum==0) 
                return 1;
            return 0;
        }
        else if(sum<0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        
        return dp[n][sum] = (solve(arr,n-1,sum,dp) + solve(arr,n-1,sum-arr[n-1],dp))%MOD;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n+1,vector<int> (sum+1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                dp[i][j] = -1;
            }
        }
        
        return (solve(arr,n,sum,dp))%MOD;
	}
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends