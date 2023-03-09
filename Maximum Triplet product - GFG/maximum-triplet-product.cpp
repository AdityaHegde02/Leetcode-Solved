//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	sort(arr,arr+n);
    	long long ans = 1;
    	ans *= arr[n - 1];
    	ans *= arr[n - 2];
    	ans *= arr[n - 3];
    	if(arr[n - 1] <= 0){
    	    return ans;
    	}
    	long long temp1 = 1;
    	temp1 *= arr[0];
    	temp1 *= arr[1];
    	temp1 *= arr[n - 1];
    	return max(temp1,ans);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends