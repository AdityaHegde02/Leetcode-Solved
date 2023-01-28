//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        if(a == b){
            return 0;
        }
        string s,t;
        while(a){
            s += to_string((a % 2));
            a /= 2;
        }
        reverse(s.begin(),s.end());
        while(b){
            t += to_string(b % 2);
            b /= 2;
        }
        reverse(t.begin(),t.end());
        int x = 0;
        int onesA = 0,onesB = 0;
        
        if(s.size() >= t.size()){
            int d = s.size() - t.size();
            for(int i = 0; i < d; i++){
                if(s[i] == '1'){
                    onesA++;
                }
            }
            
            for(int i = d; i < s.size(); i++){
                if(s[i] != t[i - d]){
                    if(s[i] == '1'){
                        onesA++;
                    }
                    else{
                        onesB++;
                    }
                }
            }
        }
        
        else{
            int d = t.size() - s.size();
            for(int i = 0; i < d; i++){
                if(t[i] == '1'){
                    onesB++;
                }
            }
            
            for(int i = d; i < t.size(); i++){
                if(t[i] != s[i - d]){
                    if(s[i - d] == '1'){
                        onesA++;
                    }
                    else{
                        onesB++;
                    }
                }
            }
        }
        
        if(onesA and onesB){
            return 2;
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends