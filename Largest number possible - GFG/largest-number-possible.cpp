//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(S == 0){
            if(N == 1){
                return "0";
            }
            return "-1";
        }
        string ans(N,'0');
        int i = 0;
        while(i < N and S){
            if(S >= 9){
                ans[i] = '9';
                S -= 9;
            }
            else{
                ans[i] = S + '0';
                S = 0;
            }
            i++;
        }
        if(i == 0 or S){
            return "-1";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends