//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        int m = S.size();
        int n = W.size();
        int count = 0;
        vector<int> visited(m,-1);
        for(int i = 0; i < m; i++){
            int idx = 0;
            for(int j = i ; j < m and idx < n ; j++){
                if(visited[j] == -1 and S[j] == W[idx]){
                    idx++;
                }
            }
            if(idx == n){
                count++;
                int x = 0;
                for(int j = i ; j < m and x < n; j++){
                    if(visited[j] == -1 and S[j] == W[x]){
                        visited[j] = 1;
                        x++;
                    }
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends