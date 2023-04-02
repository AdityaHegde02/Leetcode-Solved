//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string s)
    {
       int n = s.size();
       if(n == 1){
           return s[0] - '0';
       }
       
       int ans = 0;
       int curr = (s[0] - '0')*10;
       
       for(int i = 1; i < n; i++){
           curr += s[i] - '0';
           curr = (curr % 11);
           curr *= 10;
       }
       
       return (curr)/10;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends