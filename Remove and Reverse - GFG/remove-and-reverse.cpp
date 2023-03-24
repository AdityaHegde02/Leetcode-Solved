//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        int n = S.size();
        int i = 0, j = n - 1;
        int dir = 1;
        vector<int> count(26,0);
        for(char &c : S){
            count[c - 'a']++;
        }
        
        while(i < j){
            if(dir == 1){
                if(count[S[i] - 'a'] > 1){
                    count[S[i] - 'a']--;
                    S.erase(i,1);
                    dir = -1;
                    j--;
                }
                else{
                    i++;
                }
            }
            else{
               if(count[S[j] - 'a'] > 1){
                   count[S[j] - 'a']--;
                    S.erase(j,1);
                    dir = 1;
                }
                j--;
            }
        }
        
        if(dir == -1){
            reverse(S.begin(),S.end());
        }
        
        return S;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends