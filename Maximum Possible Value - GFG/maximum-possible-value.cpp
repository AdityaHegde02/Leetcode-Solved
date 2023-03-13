//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        long long sum = 0;
        int n = A.size();
        
        int leastVal = INT_MAX,pairs = 0;
        
        for(int i = 0; i < n; i++){
            pairs += (B[i]/2);
            int p = (B[i]/2);
            sum += (p*A[i]*2);
            if(B[i] >= 2)
                leastVal = min(leastVal,A[i]);
        }
        
        if(pairs % 2){
            sum -= leastVal*2;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends