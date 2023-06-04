//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            int n = s.size();
            string ans = "";
            stack<string> st;
            
            string temp = "";
            for(int i = 0; i < n; i++){
               if(s[i] >= '0' and s[i] <= '9'){
                   temp += s[i];
               } 
               else{
                   if(temp.size() > 0){
                       st.push(temp);
                       temp = "";
                   }
                   if(s[i] == '+'){
                       st.push("+");
                   }
                   else if(s[i] == '-'){
                       st.push("-");
                   }
                   else if(s[i] == '*'){
                       st.push("*");
                   }
                   else if(s[i] == '/'){
                       st.push("/");
                   }
               }
            }
            
            if(temp != ""){
                st.push(temp);
            }
            
            while(!st.empty()){
                string t = st.top();
                st.pop();
                if(t == "*" or t == "-" or t == "+" or t == "/")
                    ans += (t);
                else
                    ans += t;
            }
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends