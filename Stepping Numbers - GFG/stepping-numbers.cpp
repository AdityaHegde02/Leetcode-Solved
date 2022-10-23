//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void generate(int curr,int num,map<int,int> &mp){
        if(num > 1e7){
            return ;
        }
        int x = num;
        for(int i = 0; i < 10; i++){
            if(abs(curr - i) == 1){
                num = num*10 + i;
                mp[num] = 1;
                generate(i,num,mp);
                num = x;
            }
        }
    }

    int steppingNumbers(int n, int m)
    {
        map<int,int> mp;
        int counts = 0;
        mp[0] = 1;
        
        for(int i = 1; i < 10; i++){
            mp[i] = 1;
            generate(i,i,mp);
        }
            
        for(auto &i : mp){
            if(i.first >= n and i.first <= m){
                counts++;
            }
        }
        
        return counts;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends