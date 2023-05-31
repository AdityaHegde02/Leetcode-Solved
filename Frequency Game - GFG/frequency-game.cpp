//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        int minFreq = INT_MAX;
        for(auto &i : mp){
            minFreq = min(minFreq,i.second);
        }
        
        int l = 0;
        for(auto &i : mp){
            if(i.second == minFreq){
                l = max(l,i.first);
            }
        }
        
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends