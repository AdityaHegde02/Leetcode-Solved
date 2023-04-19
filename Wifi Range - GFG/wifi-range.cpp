//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        vector<pair<int,int>> a;
        for(int i = 0; i < N; i++){
            if(S[i] == '1'){
                a.push_back({max(0,i - X),i + X});
            }
        }
        
        int last = -1;
        for(int i = 0; i < a.size(); i++){
            if(a[i].first > (last+1)){
                return false;
            }
            else{
                last = a[i].second;
            }
        }
        
        return  (last >= N - 1);
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends