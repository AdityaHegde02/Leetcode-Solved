//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string s) {
    int n = s.size(), groups = 0;
    int i = 0;
    while(i < n){
        char c = s[i];
        while(i < n and s[i] == c){
            i++;
        }
        groups++;
    }
    
    return (groups / 2) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends