//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void solve(int vfirst,vector<int> &count,vector<int> &vowels,string &s,int N){
        int v = 0;
        int c = 1;
        
        if(vfirst){
            while(N){
                while(!count[vowels[v] - 'a']){
                    v++;
                }
                s += vowels[v];
                count[vowels[v] - 'a']--;
                while(c < 26 and (c == 4 or c== 8 or c == 14 or c == 20) or !count[c]){
                    c++;
                }
                if(c >= 26){
                    break;
                }
                s += c + 'a';
                count[c]--;
                N -= 2;
            }
        }
        else{
            while(N){
                while(c < 26 and (c == 4 or c== 8 or c == 14 or c == 20) or !count[c]){
                    c++;
                }
                if(c >= 26){
                    break;
                }
                s += c + 'a';
                count[c]--;
                while(v < 5 and !count[vowels[v] - 'a']){
                    v++;
                }
                if(v == 5){
                    break;
                }
                s  += vowels[v];
                count[vowels[v] - 'a']--;
                N -= 2;
            }
        }
    }
    
    string rearrange (string S, int N)
    {
        vector<int> vowels = {'a','e','i','o','u'}, count(26,0);
        
        for(char &c : S){
            count[c - 'a']++;
        }
        
        int vo = count[0] + count[4] + count[8] + count[14] + count[20];
       
        int co = (N - vo);
        
        if(abs(co - vo) > 1){
            return "-1";
        }
        
        string s = "";
        
        if(co == vo - 1 or co == vo){
            solve(1,count,vowels,s,N);
        }
        else{
            solve(0,count,vowels,s,N);
        }
        
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends