//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int m = S.size(), n = T.size();
        int i = 0, j = 0;
        while(i < m and j < n){
            if(T[j] >= '0' and T[j] <= '9'){
                int c = 0;
                while(j <  n and isdigit(T[j])){
                    c = (10)*c + (T[j] -'0');
                    j++;
                }
                for(int k = 0; k < c; k++){
                    i++;
                }
                if(i > m){
                    return 0;
                }
            }
            else{
                if(S[i] != T[j]){
                    return 0;
                }
                else{
                    i++,j++;
                }
            }
        }
        if(i == m and j == n){
            return 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends