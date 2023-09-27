//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int a = 0,b = 0, mn = INT_MAX;
        for(int i = 0; i < n; i++){
            int need = x - arr[i];
            int low = 0, high = m - 1;
            int justbig = -1;
            while(low <= high){
                int mid = (low + high)/2;
                if(brr[mid] >= need){
                    justbig = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            
            if(justbig == -1){
                if(mn > need - brr[m - 1]){
                    mn = need - brr[m - 1];
                    a = arr[i];
                    b = brr[m - 1];
                }
            }
            else if(justbig == 0){
                if(mn > brr[0] - need){
                    mn = brr[0] - need;
                    a = arr[i];
                    b = brr[0];
                }
            }
            else{
                if(mn > need - brr[justbig - 1]){
                    mn = need - brr[justbig - 1];
                    a = arr[i];
                    b = brr[justbig - 1];
                }
                if(mn > brr[justbig] - need){
                    mn = brr[justbig] - need;
                    a = arr[i];
                    b = brr[justbig];
                }
            }
        }
        return {a,b};
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends