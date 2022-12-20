//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        vector<int> xplusi;
        vector<int> xminusi;
        for(int i = 0; i < n; i++){
            xplusi.push_back(arr[i] + i);
            xminusi.push_back(arr[i] - i);
        }
        sort(xplusi.begin(),xplusi.end());
        sort(xminusi.begin(),xminusi.end());
        return max(xplusi[n-1] - xplusi[0],xminusi[n-1] - xminusi[0]);
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends