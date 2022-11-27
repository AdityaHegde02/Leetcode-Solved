//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    int m = A.size();
	    int n = B.size();
	    
	    string ans;
	    
	    if(m < n){
	        int diff = n - m;
	        while(diff){
	            A = '0' + A;
	            diff--;
	        }
	    }
	    else if(m > n){
	        int diff = m - n;
	        while(diff){
	            B = '0' + B;
	            diff--;
	        }
	    }
	    
	    int size = A.size();
	    
	    int carry = 0;
	    for(int i = size - 1; i >= 0; i--){
	        if(carry){
	            if(A[i] == '1' and B[i] == '1'){
	                carry = 1;
	                ans += '1';
	            }
	            else if(A[i] == '0' and B[i] == '0'){
	                carry = 0;
	                ans += '1';
	            }
	            else{
	                carry = 1;
	                ans += '0';
	            }
	        }
	        else{
	            if(A[i] == '1' and B[i] == '1'){
	                carry = 1;
	                ans += '0';
	            }
	            else if(A[i] == '0' and B[i] == '0'){
	                carry = 0;
	                ans += '0';
	            }
	            else{
	                carry = 0;
	                ans += '1';
	            }
	        }
	    }
	    
	    if(carry){
	        ans += '1';
	    }
	    
	    reverse(ans.begin(),ans.end());
	    
	    int i = 0;
	    int a = ans.size();
	    while(ans[i] == '0'){
	        i++;
	    }
	    
	    ans = ans.substr(i,a - i);
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends