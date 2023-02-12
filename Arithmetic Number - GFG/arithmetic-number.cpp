//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        if(A == B){
            return true;
        }
        if(C == 0){
            return false;
        }
        if(C >= 0){
            if(B < A){
                return false;
            }
        }
        else{
            if(B > A){
                return false;
            }
        }
        long long d = (B - A);
        return (abs(d) % C == 0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends