//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> ans;
        vector<int> tmp;
        set<int> s(A.begin(),A.end());
        A.clear();
        for(auto &i:s){
            A.push_back(i);
        }
        helper(A, B, 0, tmp, ans);
        return ans;
    }
    
    void helper(vector<int> &A, int B, int idx, vector<int> &tmp, vector<vector<int>> &ans){
        if(B == 0) ans.push_back(tmp);
        if(B <= 0) return;
        
        for(int i=idx;i<A.size();i++){
            tmp.push_back(A[i]);
            helper(A, B - A[i], i, tmp, ans);
            tmp.pop_back();
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends