//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int dp[50001][3];
    
    long long int solve(int i,int N,int prev,int* r,int* g,int* b){
        if(i >= N){
            return 0;
        }
        
        if(prev != -1 and dp[i][prev] != LONG_MAX){
            return dp[i][prev];
        }
        
        long long int temp = LONG_MAX;
        if(prev == -1){
            temp = min(temp, (long long)r[i] + solve(i + 1,N,0,r,g,b));
            temp = min(temp, (long long)g[i] + solve(i + 1,N,1,r,g,b));
            temp = min(temp, (long long)b[i] + solve(i + 1,N,2,r,g,b));
        }
        
        else if(prev == 0){
            temp = min(temp, (long long)g[i] + solve(i + 1,N,1,r,g,b));
            temp = min(temp, (long long)b[i] + solve(i + 1,N,2,r,g,b));
        }
        
        else if(prev == 1){
            temp = min(temp, (long long)r[i] + solve(i + 1,N,0,r,g,b));
            temp = min(temp, (long long)b[i] + solve(i + 1,N,2,r,g,b));
        }
        
        else{
            temp = min(temp, (long long)r[i] + solve(i + 1,N,0,r,g,b));
            temp = min(temp, (long long)g[i] + solve(i + 1,N,1,r,g,b));
        }
        
        if(prev != -1){
            dp[i][prev] = temp;
        }
        
        return temp;
    }
    
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        for(int i = 0; i < 50001; i++){
            for(int j = 0; j < 3; j++){
                dp[i][j] = LONG_MAX;
            }
        }
        return solve(0,N,-1,r,g,b);    
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends