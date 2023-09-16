//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod = 7 + 1e9;
    long long dp[100001];
    long long i = 0;
    
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        if(i == 0){
            memset(dp,-1,sizeof(dp));
        }
        i++;
        
        if(n == 0){
            return 1LL;
        }
        
        if(n < 0){
            return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = (countWays(n - 1) + countWays(n - 2) + countWays(n - 3))% mod;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends