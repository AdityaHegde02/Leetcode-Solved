//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    #define ll long long
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr,arr + n);
        for(ll i = 0; i < n; i++){
            ll req = (-1)*(arr[i]);
            ll l = i + 1,r = n - 1;
            while(l < r){
                ll sum = arr[l] + arr[r];
                if(sum == req){
                    // cout << l << " " << r << i;
                    return true;
                }
                else if(sum > req){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends