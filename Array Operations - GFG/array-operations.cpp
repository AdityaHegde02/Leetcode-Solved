//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int z = 0;
        for(int &i : arr){
            if(i == 0){
                z++;
            }
        }
        
        if(z == 0){
            return 1;
        }
        
        vector<int> modified;
        modified.push_back(arr[0]);
        int ze = 0;
        if(arr[0] == 0){
            ze++;
        }
        for(int i = 1; i < n; i++){
            if(modified.back() == 0 and arr[i] == 0){
                continue;
            }
            else{
                if(arr[i] == 0){
                    ze++;
                }
                modified.push_back(arr[i]);
            }
        }
        
        if(modified[0] == 0 and modified[modified.size() - 1] == 0){
            return ze - 1;
        }
        else if(modified[0] == 0 or modified[modified.size() - 1] == 0){
            return ze;
        }
        else{
            return ze + 1;
        }
        
        return 0;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends