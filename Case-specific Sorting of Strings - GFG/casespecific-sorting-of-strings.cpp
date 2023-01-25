//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string low, high;
        for(char &c : str){
            if(c >= 'A' and c <= 'Z'){
                low += c;
            }
            else{
                high += c;
            }
        }
        sort(low.begin(),low.end());
        sort(high.begin(),high.end());
        
        int i = 0, j = 0;
        for(char &c : str){
            if(c >= 'A' and c <= 'Z'){
                c = low[j++];
            }
            else{
                c = high[i++];
            }
        }
        return str;
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends