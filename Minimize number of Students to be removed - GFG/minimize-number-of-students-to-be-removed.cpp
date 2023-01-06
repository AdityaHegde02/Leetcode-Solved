//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int a[], int N) {
        //lis
       vector<int> lis;
       lis.push_back(a[0]);
       for(int i = 1; i < N; i++){
           if(a[i] > lis.back()){
               lis.push_back(a[i]);
           }
           else{
               int idx = lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
               lis[idx] = a[i];
           }
       }
       return N - lis.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends