//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> st;
        int mx = -1, j = 0;
        for(int i = 0; i < s.size(); i++){
            if(st.size() == k){
                mx = max(mx, i - j);
                if(st.find(s[i]) == st.end()){
                    while(j < s.size() and st.size() == k){
                        st[s[j]]--;
                        if(st[s[j]] == 0){
                            st.erase(s[j]);
                        }
                        j++;
                    }
                    i--;
                }
                else{
                    st[s[i]]++;
                    mx = max(mx, i - j + 1);
                }
            }
            else{
                st[s[i]]++;
            }
        }
        
        return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends