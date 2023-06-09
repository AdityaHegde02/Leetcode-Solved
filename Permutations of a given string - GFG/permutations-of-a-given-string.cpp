//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string> st;
	    
	    void solve(int idx,string &temp,string &s,vector<int> &vis){
	        if(idx >= s.size()){
	            st.insert(temp);
	            return ;
	        }    
	        
	        for(int i = 0; i < s.size(); i++){
	            if(!vis[i]){
	                vis[i] = 1;
	                temp += s[i];
	                solve(idx + 1,temp,s,vis);
	                temp.pop_back();
	                vis[i] = 0;
	            }
	        }
	    }
	    
		vector<string>find_permutation(string s)
		{
		    int n = s.size();
		    vector<int> vis(n,0);
		    string temp = "";
		    solve(0,temp,s,vis);
		    vector<string> ans(st.begin(),st.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends