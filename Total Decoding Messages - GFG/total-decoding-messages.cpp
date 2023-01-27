//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    const long int mod = 1e9 + 7;
	    int dp[100001];
	    
	    int solve(int i,string &str){
	        if(i >= str.size()){
	            return 1;
	        }
	        
	        if(i == str.size() - 1){
	            if(str[i] == '0'){
	                return 0;
	            }
	            return 1;
	        }
	        
	        if(dp[i] != -1){
	            return dp[i];
	        }
	        
	        char c = str[i];
	        int temp = 0;
	        if(c >= '1' and c <= '9'){
	            temp += solve(i + 1,str);
	        }
	        
	        string a = str.substr(i,2);
	        int num = stoi(a);
	        if(num >= 10 and num <= 26){
	            temp += solve(i + 2,str);
	        }
	        
	        return dp[i] = temp % mod;
	    }
	    
		int CountWays(string str){
		    memset(dp,-1,sizeof(dp));
		    return solve(0,str) % mod;
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
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends