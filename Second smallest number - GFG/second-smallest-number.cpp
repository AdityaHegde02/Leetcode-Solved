//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int sum, int D){
        int n = D;
        string ans;
        for(int i = n - 1; i >= 0 ; i--){
            if(sum  - 9 >= 1){
                ans += '9';
                sum -= 9;
            }
            else if(i == 0){
                ans += to_string(sum);
                sum = 0;
            }
            else{
                ans += to_string(sum - 1);
                int c = i - 1;
                while(c--){
                    ans += '0';
                }
                ans += '1';
                sum = 0;
                break;
            }
        }
        
        if(sum != 0){
            return "-1";
        }
        
        reverse(ans.begin(),ans.end());
        
        int idx = ans.size() - 1;
        for(int i = ans.size() - 1; i >= 0 ; i--){
            if(ans[i] == '9'){
                idx = i;
            }
            else{
                break;
            }
        }
        
        if(idx == 0){
            return "-1";
        }
        
        ans[idx] -= 1;
        ans[idx - 1] += 1;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends