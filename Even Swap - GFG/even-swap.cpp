//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            vector<int> ans;
            for(int i = 0; i < n;){
                int j = i;
                if(a[j] % 2){
                    vector<int> temp;
                    while(j < n and a[j] % 2){
                        temp.push_back(a[j++]);
                    }
                    sort(temp.rbegin(),temp.rend());
                    for(int &i : temp){
                        ans.push_back(i);
                    }
                    i = j;
                }
                else{
                    vector<int> temp;
                    while(j < n and a[j] % 2 == 0){
                        temp.push_back(a[j++]);
                    }
                    sort(temp.rbegin(),temp.rend());
                    for(int &i : temp){
                        ans.push_back(i);
                    }
                    i = j;
                }
            }
            
            return ans;
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
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends