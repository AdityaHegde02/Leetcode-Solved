//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      long long amount = 0;
      
      int more = max(X,Y);
      int type = 0;
      if(more == X){
          type = 1;
      }
      else{
          type = 2;
      }
      
      stack<char> st;
      
      if(type == 1){
          for(int  i = 0; i < S.size(); i++){
              if(st.empty()){
                  st.push(S[i]);
              }
              else if(st.top() == 'p' and S[i] == 'r'){
                  amount += X;
                  st.pop();
              }
              else{
                  st.push(S[i]);
              }
          }
          
          string rem = "";
          while(!st.empty()){
              rem += st.top();
              st.pop();
          }
          
          reverse(rem.begin(),rem.end());
          
          for(int  i = 0; i < rem.size(); i++){
              if(st.empty()){
                  st.push(rem[i]);
              }
              else if(st.top() == 'r' and rem[i] == 'p'){
                  amount += Y;
                  st.pop();
              }
              else{
                  st.push(rem[i]);
              }
          }
      }
      
      else{
          for(int  i = 0; i < S.size(); i++){
              if(st.empty()){
                  st.push(S[i]);
              }
              else if(st.top() == 'r' and S[i] == 'p'){
                  amount += Y;
                  st.pop();
              }
              else{
                  st.push(S[i]);
              }
          }
          
          string rem = "";
          while(!st.empty()){
              rem += st.top();
              st.pop();
          }
          
          reverse(rem.begin(),rem.end());
          
          for(int  i = 0; i < rem.size(); i++){
              if(st.empty()){
                  st.push(rem[i]);
              }
              else if(st.top() == 'p' and rem[i] == 'r'){
                  amount += X;
                  st.pop();
              }
              else{
                  st.push(rem[i]);
              }
          }
      }
      
      return amount;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends