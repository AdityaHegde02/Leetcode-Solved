//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(),range.end());
        vector<vector<int>> newRange;
        newRange.push_back(range[0]);
        for(int i = 1; i < n; i++){
            if(range[i][0] <= newRange.back()[1]){
                newRange.back()[1] = max(newRange.back()[1],range[i][1]);
            }
            else{
                newRange.push_back(range[i]);
            }
        }
        
        n = newRange.size();
        vector<int> size,ans;
        for(int i = 0; i < n; i++){
            size.push_back(newRange[i][1] - newRange[i][0] + 1);
        }
        
        for(int i = 1; i < n; i++){
            size[i] += size[i - 1];
        }
        
        for(int i = 0; i < q; i++){
            int search = queries[i];
            if(search > size[n - 1]){
                ans.push_back(-1);
                continue;
            }
            int idx = lower_bound(size.begin(),size.end(),search) - size.begin();
            if(idx == 0){
                ans.push_back(newRange[idx][0] + search - 1);
            }
            else if(idx >= n){
                if(search == size[n - 1])
                    ans.push_back(newRange[idx][0] + search - 1);
                else{
                    ans.push_back(-1);
                }
            }
            else{
                ans.push_back(newRange[idx][0] + (search - size[idx - 1] - 1));
            }
        }
        
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends