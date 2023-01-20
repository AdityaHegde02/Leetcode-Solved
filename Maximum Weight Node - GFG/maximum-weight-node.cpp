//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      vector<vector<int>> adj(N);
      for(int i = 0; i < N; i++){
        if(Edge[i] != -1)
            adj[Edge[i]].push_back(i);
      }
      
      int mx = 0;
      int cell = -1;
      
      for(int i = 0; i < N; i++){
          int sum = 0;
          for(int &j : adj[i]){
              sum += j;
          }
          if(sum >= mx){
              mx = sum;
              cell = i;
          }
      }
      return cell;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends