//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    int len = 0;
	    int N = n;
	    while(N){
	        len++;
	        N /= 2;
	    }
	    
	    int start = max(1,n - len);
	    for(int i = start; i < n; i++){
	        int N = i, set = 0;
	        while(N){
	            if(N % 2){
	                set++;
	            }
	            N /= 2;
	        }
	        
	        if(i + set == n){
	            return 0;
	        }
	    }
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends