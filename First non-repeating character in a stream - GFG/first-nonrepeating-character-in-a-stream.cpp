//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    string ans = "";
		    vector<int> count(26,0);
		    vector<int> idx(26,-1);
		    for(int i = 0; i < A.size(); i++){
		        count[A[i] - 'a']++;
		        if(idx[A[i] - 'a'] == -1){
		            idx[A[i] - 'a'] = i;
		        }
		        
		        int mn = INT_MAX,ind = INT_MAX;
		        for(int j = 0; j < 26; j++){        // to get freq 1 and min idx
		            if(count[j] == 1){
		                mn = min(mn,idx[j]);
		            }
		        }
		        
		        if(mn == INT_MAX){
		            ans += '#';
		        }
		        else{
		            ans += A[mn];
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends