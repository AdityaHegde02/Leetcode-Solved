//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 7 + 1e9;
    
    int sumOfNaturals(int n) {
        return ((long long)n*(n+1) % mod)/2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends