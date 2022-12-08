//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i = 0;i < n; i++){
	        sum += arr[i];
	    }
	    vector<vector<bool>> dp(n+1,vector<bool> (sum+1,-1));
	    for(int i = 0; i <= sum; i++){
	        dp[0][i] = false;
	    }
	    for(int j = 0; j <= n; j++){
	        dp[j][0] = true;
	    }
	   
	    for(int i = 1; i <= n; i++){            // items
	        for(int j = 1; j <= sum; j++){       // req sum
	            if(arr[i-1] <= j){
	                dp[i][j] = (dp[i-1][j]) or (dp[i-1][j-arr[i-1]]);
	            }
	            else{
	                dp[i][j] = (dp[i-1][j]);
	            }
	        }
	    }
	    
	    int minDiff = INT_MAX;
	    for(int i = sum; i >= 0; i--){
	        if(dp[n][i]){
	            int x = i;
	            int y = sum - i;
	            minDiff = min(minDiff,abs(y-x));
	        }
	    }
	    return minDiff;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends