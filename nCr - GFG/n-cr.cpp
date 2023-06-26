//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 7 + 1e9;
    
    int nCr(int n, int r){
        if(n < r){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        vector<long long> temp = {1,1};
        for(long long level = 2; level <= n; level++){
            vector<long long> x = {1};
            for(long long i = 0; i < temp.size() - 1; i++){
                x.push_back((long long)(temp[i] + temp[i + 1]) % mod);
            }
            x.push_back(1);
            temp = x;
        }
        
        return temp[r]  % mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends