//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int n,string s, vector<int> &p)
    {
        int ans=0,count=0 ,temp=0;
        unordered_map<int,char> mp;
        for(int i=0; i<n; i++)
        {
            mp[i]=s[i];
        }
        for(int i=0; i<p.size(); i++)
        {
            temp++;
            char aa='A',bb='B',cc=s[p[i]];
            if(mp.find(p[i]-1)!=mp.end()) aa=s[p[i]-1];
            if(mp.find(p[i]+1)!=mp.end()) bb=s[p[i]+1];
            if(aa==cc || bb==cc) 
            {
                count=temp;
                mp.erase(p[i]);
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends