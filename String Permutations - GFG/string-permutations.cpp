//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> ans;
    
    void solve(int i,string &S){
        if(i >= S.size()){
            ans.push_back(S);
            return ;
        }
        for(int j = i; j < S.size(); j++){
            swap(S[i],S[j]);
            solve(i + 1,S);
            swap(S[i],S[j]);
        }
    }
    
    vector<string> permutation(string S)
    {
        solve(0,S);
        sort(ans.begin(),ans.end());
        return ans;    
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends