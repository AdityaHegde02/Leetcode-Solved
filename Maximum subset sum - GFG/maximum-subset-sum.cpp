//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int dp[100001][2];
    
    long long solve(int idx,bool shouldTake,vector<int> &A){
        if(idx >= A.size()){
            return 0;
        }    
        
        if(dp[idx][shouldTake] != -1){
            return dp[idx][shouldTake];
        }
        
        if(shouldTake){
            return (long long)(A[idx] + solve(idx + 1,!shouldTake,A));
        }
        
        return dp[idx][shouldTake] = max(((long long)A[idx] + solve(idx + 1,shouldTake,A)), solve(idx + 1,!shouldTake,A));
    }
    
    long long findMaxSubsetSum(int N, vector<int> &A) {
        memset(dp,-1,sizeof(dp));
        bool shouldTake = false;
        return solve(0,shouldTake,A);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends