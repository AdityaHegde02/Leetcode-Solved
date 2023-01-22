//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    
    bool isPal(string &a){
        string b = a;
        reverse(a.begin(),a.end());
        return (a == b);
    }
    
    int solve(int i,int j,string &str){
        if(i >= j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        string t = str.substr(i,j-i+1);
        if(isPal(t)){
            return dp[i][j] = 0;
        }
        
        int mn = INT_MAX;
        
        for(int k = i; k < j; k++){
            int temp = 1 + solve(i,k,str) + solve(k + 1,j,str);
            mn = min(temp,mn);
        }
        
        return dp[i][j] = mn;
    }
    
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,str.size() - 1,str);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends