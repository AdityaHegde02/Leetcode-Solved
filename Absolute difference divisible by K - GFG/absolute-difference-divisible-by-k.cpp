//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        long long ans = 0;
        unordered_map<int ,int> rem;
        for(int i = 0; i < n; i++){
            arr[i] = (arr[i] % k);
        }
        for(int i = 0; i < n; i++){
            if(rem.find(arr[i]) != rem.end()){
                ans += (rem[arr[i]]);
            }
            rem[arr[i]]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends