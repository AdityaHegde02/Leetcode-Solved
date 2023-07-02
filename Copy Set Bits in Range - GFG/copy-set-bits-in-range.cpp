//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        int X = x;
        string a = "",b = "";
        while(x){
            a += to_string(x % 2);
            x /= 2;
        }
        
        reverse(a.begin(),a.end());
        
        while(y){
            b += to_string(y % 2);
            y /= 2;
        }
        
        reverse(b.begin(),b.end());
        
        while(a.size() < 32){
            a.insert(0,"0");
        }
        
        while(b.size() < 32){
            b.insert(0,"0");
        }
        
        int ans = 0;
        for(int i = l; i <= r; i++){
            if(b[32 - i] == '1'){
                if(a[32 - i] == '0'){
                    ans += pow(2,i - 1);
                }
            }
        }
        
        return X + ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends