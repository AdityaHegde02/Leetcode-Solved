class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int sz = s.size(), n = d.size(), mxSize = 0;
        string ans = "";
        for(int i = 0; i < n; i++){
            int j = 0, k = 0;           //j for s, k for t
            string t = d[i];
            while(j < sz and k < t.size()){
                if(s[j] == t[k]){
                    j++,k++;
                }
                else{
                    j++;
                }
            }
            if(k == t.size()){
                if(t.size() > mxSize){
                    mxSize = t.size();
                    ans = t;
                }
                else if(t.size() == mxSize){
                    ans = min(ans,t);
                }
            }
        }
        return ans;
    }
};