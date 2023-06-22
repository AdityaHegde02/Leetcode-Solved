class Solution {
public:
    int diff(string &a,string &b){
        int x = 0;
        for(int i = 0; i < a.size(); i++){
            x += (a[i] != b[i]);
        }    
        return x;
    }
    
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        vector<string> a,b;
        for(int i = 0; i < m; i++){
            for(int j = i + 1; j <= m; j++){
                string x = s.substr(i,j - i);
                a.push_back(x);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                string x = t.substr(i,j - i);
                b.push_back(x);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b.size(); j++){
                if(a[i].size() == b[j].size() and diff(a[i],b[j]) == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};