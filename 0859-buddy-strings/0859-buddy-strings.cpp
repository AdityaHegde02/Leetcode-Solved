class Solution {
public:
    bool buddyStrings(string s, string t) {
        int m = s.size(),n = t.size();
        if(m != n){
            return false;
        }
        if(s==t){
            unordered_set<char> a(s.begin(),s.end());
            if(a.size()<m){
                return true;
            }
            return false;
        }
        int count=0;
        vector<char> ans;
        for(int i=0;i<m;i++){
            if(s[i]!=t[i]){
                ans.push_back(s[i]);
                ans.push_back(t[i]);
                count++;
            }
            if(count>2){
                return false;
            }
        }
        if(count==2){
            if(ans[0]==ans[3] and ans[1]==ans[2]){
                return true;
            }
            return false;
        }
        return false;
    }
};