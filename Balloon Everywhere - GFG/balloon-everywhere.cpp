//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool isChar(int x){
        char c = x + 'a';
        return (c == 'b' or c == 'a' or c == 'l' or c == 'o' or c == 'n');
    }
    
    int maxInstance(string s){
        vector<int> count(26,0);
        for(auto &i : s){
            count[i - 'a']++;
        }
        int mn = INT_MAX;
        for(int i = 0; i < 26; i++){
            if(isChar(i)){
                if(i + 'a' == 'l' or i + 'a' == 'o'){
                    mn = min(count[i]/2,mn);
                }
                else{
                    mn = min(mn,count[i]);
                }
            }
        }
        return mn;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends