//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int &i : arr){
            minHeap.push(i);
        }
        int sum = 0;
        while(minHeap.size() > 1){
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();
            sum += (a + b);
            minHeap.push(a + b);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends