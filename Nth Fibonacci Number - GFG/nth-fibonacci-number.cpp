//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long mod = 7 + 1e9;
    int nthFibonacci(int n){
        if(n == 1){
            return 0;
        }
        if(n <= 3){
            return 1;
        }
        
        long int p1 = 0, p2 = 1;
        for(int i = 2; i <= n; i++){
            long int curr = (p1 + p2) % mod;
            p1 = p2 % mod;
            p2 = curr % mod;
        }
        
        return p2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends