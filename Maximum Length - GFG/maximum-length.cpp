//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        int mn1 = min({a,b,c});
        int mx = max({a,b,c}), mn2 = -1;
        if(mn1 == a and mx == b or mn1 == b and mx == a){
            mn2 = c;
        }
        else if(mn1 == b and mx == c or mn1 == c and mx == b){
            mn2 = a;
        }
        else{
            mn2 = b;
        }
        
        if(2*(mn1 + mn2 + 1) >= mx){
            return (a + b + c);
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends