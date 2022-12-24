//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int N){
      long long int ans = 0;
      vector<int> negs;
      for(int i = 0; i < N; i++){
          if(arr[i] < 0){
              negs.push_back(i);
          }
      }
      int j = 0;
      for(int i = 0; i < N; i++){
          if(arr[i] > 0){
            while(arr[i] != 0){
                if(abs(arr[negs[j]]) >= arr[i]){
                    ans += (arr[i])*abs(negs[j] - i);
                    arr[negs[j]] += arr[i];
                    arr[i] = 0;
                } 
                else{
                    ans += (abs(arr[negs[j]]))*abs(negs[j]-i);
                    arr[i] -= (abs(arr[negs[j]]));
                    arr[negs[j]] = 0;
                    j++;
                }
            }
          }
      }
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends