//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        bool first = true;
        int start = 1, end = N;
        while(start <= end){
            if(first){
                start += K;
                if(start > end){
                    return end;
                }
                first = false;
            }
            else{
                end -= K;
                if(start > end){
                    return start;
                }
                first = true;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends