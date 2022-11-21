//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
	    if(B > A){
	        swap(A,B);
	    }
	    while(A % B != 0){
	        int r = A % B;
	        A = B;
	        B = r;
	    }
	    return B;
	} 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends