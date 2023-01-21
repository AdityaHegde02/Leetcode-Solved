//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int setbitsB = 0 , n = 0;
        while(b){
            setbitsB += (b % 2);
            b /= 2;
            n++;
        }
        string s;
        int m = 0;
        while(a){
            s += to_string((a % 2));
            a /= 2;
            m++;
        }
        reverse(s.begin(),s.end());
        if(m <= setbitsB){
            int ans = 0;
            for(int i = 0; i < m; i++){
                ans += (pow(2,m-1-i));
            }
            return ans;        
        }
        int ans= 0;
        for(int i = 0;  i < m; i++){
            if(s[i] == '1' and setbitsB){
                ans += (pow(2,m-1-i));
                setbitsB--;
            }
        }
        if(setbitsB){
            for(int i = m - 1; i >= 0; i--){
                if(s[i] == '0' and setbitsB){
                    ans += (pow(2,m-i-1));
                    setbitsB--;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends