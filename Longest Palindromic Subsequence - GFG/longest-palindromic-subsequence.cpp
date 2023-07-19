//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    
    int LCS(int i,int j,string &A,string &B){
        if(i >= A.size() or j >= B.size()){
            return 0;
        }    
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(A[i] == B[j]){
            return dp[i][j] = 1 + LCS(i + 1,j + 1,A,B);
        }
        
        return dp[i][j] = max(LCS(i + 1,j,A,B),LCS(i,j + 1,A,B));
    }
    
    int longestPalinSubseq(string A) {
        string B = A;
        reverse(B.begin(),B.end());
        memset(dp,-1,sizeof(dp));
        return LCS(0,0,A,B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends