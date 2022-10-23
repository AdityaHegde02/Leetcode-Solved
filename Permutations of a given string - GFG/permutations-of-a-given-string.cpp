//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string> unique;
	
	    void generate(int idx,int n,string &s,vector<string> &ans){
	        if(idx == n){
	            if(unique.count(s) == 0){
	                ans.push_back(s);
	                unique.insert(s);
	            }
	            return ;
	        }
	        
	        for(int i = idx; i < s.size() ; i++){
	            swap(s[i],s[idx]);
	            generate(idx + 1,n,s,ans);
	            swap(s[i],s[idx]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    generate(0,S.size(),S,ans);
		    sort(ans.begin(),ans.end());
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