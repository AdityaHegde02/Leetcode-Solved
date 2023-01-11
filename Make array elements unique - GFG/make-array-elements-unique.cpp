//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        sort(arr.begin(),arr.end());
        long long int ans = 0;
        unordered_map<int,int> mp;
        int last = -1;
        for(int &i : arr){
            if(mp.find(i) != mp.end()){     // already present
                ans += (last + 1 - i);
                mp[last + 1]++;
                last++;
            }
            else{
                last = i;
                mp[i]++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends