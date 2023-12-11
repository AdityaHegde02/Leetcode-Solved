class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            int v = 0, c = 0;
            for(int j = i; j < n; j++){
                if((s[j] == 'a') or (s[j] == 'e') or (s[j] == 'i') or (s[j] == 'o') or (s[j] == 'u')){
                    v++;
                }
                else{
                    c++;
                }
                if(v and ((v*v) % k) == 0 and v == c){
                    ans++;
                }
            }
        }
        return ans;
    }
};