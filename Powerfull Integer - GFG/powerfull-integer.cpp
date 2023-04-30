//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx,intervals[i][1]);
        }
        
        vector<int> a(mx + 2,0);
        for(int i = 0; i < n; i++){
            a[intervals[i][0]]++;
            a[intervals[i][1] + 1]--;
        }
        
        int sum = 0,ans = -1;
        for(int i = 0; i < a.size(); i++){
            sum += a[i];
            if(sum >= k){
                ans = i;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends