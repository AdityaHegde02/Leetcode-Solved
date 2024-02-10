class Solution {
public:
    bool isPal(string &sub){
        for(int i = 0; i <= (sub.size()/2); i++){
            if(sub[i] != sub[sub.size() - i - 1]){
                return 0;
            }
        }    
        return 1;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                string sub = s.substr(i,j - i + 1);
                ans += isPal(sub);
            }
        }
        return ans;
    }
};