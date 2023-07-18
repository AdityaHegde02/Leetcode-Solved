//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int dp[1001][1001];
	    
	    int solve(int i,int j,string &str){
	        if(i >= str.size() or j >= str.size()){
	            return 0;
	        }    
	        
	        if(dp[i][j] != -1){
	            return dp[i][j];
	        }
	        
	        if(i != j and str[i] == str[j]){
	            return dp[i][j] = 1 + solve(i + 1,j + 1,str);
	        }
	        else{
	            return dp[i][j] = max(solve(i + 1,j,str),solve(i,j + 1,str));
	        }
	    }
	    
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    memset(dp,-1,sizeof(dp));
		    return solve(0,0,str);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends