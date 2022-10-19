//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
	    vector<int> ans;
	    vector<vector<int>> sum(2*n - 1);
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < n; j++){
	            sum[i+j].push_back(A[i][j]);
	        }
	    }
	    for(int i = 0 ; i < 2*n - 1 ; i++){
	        for(int j = 0 ; j < sum[i].size(); j++){
	            ans.push_back(sum[i][j]);
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends