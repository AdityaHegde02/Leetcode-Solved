//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &s) {
        vector<int> ans;
        stack<int> st;
        for(int i = 0; i < N; i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i] < 0){                   // left 
                    if(st.top() < 0){
                        st.push(s[i]);
                    }
                    else{
                        bool broke = 0;
                        while(!st.empty() and st.top() > 0){
                            if(abs(st.top()) == abs(s[i])){
                                broke = 1;
                                st.pop();
                                break;
                            }
                            else if(abs(st.top()) > abs(s[i])){
                                broke = 1;
                                break;
                            }
                            else{
                                st.pop();
                            }
                        }
                        if(!broke){
                            st.push(s[i]);
                        }
                    }
                }
                else{                           // right
                    st.push(s[i]);
                }
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends