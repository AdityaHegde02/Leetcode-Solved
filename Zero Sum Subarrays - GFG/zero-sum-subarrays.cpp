//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        long long int count = 0;
        vector<long long int> pre;
        for(int i = 0; i < n; i++){
            if(i == 0){
                pre.push_back(arr[i]);
            }
            else{
                pre.push_back(pre[i-1] + arr[i]);
            }
        }
        unordered_map<long long int,long long int> mp;
        
        for(int i = 0; i < n; i++){
            if(mp.find(pre[i]) == mp.end()){
                mp[pre[i]] = 1;
            }
            else{
                mp[pre[i]]++;
            }
        }
        for(auto &i : mp){
            if(i.first == 0){
                count += (long long)(i.second*(i.second-1))/2 + i.second;
            }
            else{
                count += (long long)(i.second*(i.second-1))/2;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends