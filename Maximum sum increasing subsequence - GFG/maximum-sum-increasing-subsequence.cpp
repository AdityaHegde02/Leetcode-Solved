//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int dp[1001][1001];
	
	int solve(int i,int prev,int arr[],int n){
	    if(i >= n){
	        return 0;
	    }   
	    
	    if(prev != -1 and dp[i][prev] != -1){
	        return dp[i][prev];
	    }
	    
	    // take
	    int take = 0;
	    if(prev == -1 or arr[prev] < arr[i]){
	        take = arr[i] + solve(i + 1,i,arr,n);
	    }
	    
	    int notake = solve(i + 1,prev,arr,n);
	    
	    if(prev == -1){
	        return max(take,notake);
	    }
	    
	    return dp[i][prev] = max(take,notake);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    memset(dp,-1,sizeof(dp));
	    return solve(0,-1,arr,n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends