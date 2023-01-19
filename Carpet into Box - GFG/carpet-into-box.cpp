//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int atoc = 0, atod = 0, btoc = 0, btod = 0;
        int a = A, b = B, c = C, d = D;
        while(a > c){
            a /= 2;
            atoc++;
        }
        a = A;
        while(a > d){
            a /= 2;
            atod++;
        }
        while(b > c){
            b /= 2;
            btoc++;
        }
        b = B;
        while(b > d){
            b /= 2;
            btod++;
        }
        int ans = min(atoc + btod,atod + btoc);
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends