//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            string s;
            string a;
            string b;
            while(n){
                int r = (n % 2);
                s += to_string(r);
                n /= 2;
            }
            
            d = (d % 16);
            
            reverse(s.begin(),s.end());
            while(s.size() < 16){
                s.insert(0,"0");
            }
            
            for(int i = d; i < 16; i++){
                a += s[i];
            }
            
            for(int i = 0; i < d; i++){
                a += s[i];
            }
            
            for(int i = 16 - d; i < 16; i++){
                b += s[i];
            }
            
            for(int i = 0; i < 16 - d; i++){
                b += s[i];
            }
            
            int p = 0, q = 0;
            for(int i = 0; i < 16; i++){
                p += (a[i] == '1')*pow(2,15 - i);
            }
            
            for(int i = 0; i < 16; i++){
                q += (b[i] == '1')*pow(2,15 - i);
            }
            
            return {p,q};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends