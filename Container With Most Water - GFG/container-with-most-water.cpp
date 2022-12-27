//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    long long int ans = 0;
    int j = len - 1;
    int i = 0;
    while(i <= j){
        ans = max(ans,(j - i)*(long long)(min(A[j],A[i])));
        if(A[i] <= A[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends