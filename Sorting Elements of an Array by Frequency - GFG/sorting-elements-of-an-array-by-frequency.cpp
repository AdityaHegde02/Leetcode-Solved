//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    static bool myCmp(pair<int,int> &a,pair<int,int> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        
        return a.first > b.first;
    }
    
    vector<int> sortByFreq(int arr[],int n)
    {
        vector<pair<int,int>> pairs;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        for(auto &i : mp){
            pairs.push_back({i.second,i.first});
        }
        
        sort(pairs.begin(),pairs.end(),myCmp);
        
        vector<int> ans;
        
        for(int i = 0; i < pairs.size(); i++){
            for(int j = 0; j < pairs[i].first; j++){
                ans.push_back(pairs[i].second);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends