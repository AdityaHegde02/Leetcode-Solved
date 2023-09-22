class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        while(i < m){
            char need = s[i];
            while(j < n and t[j] != need){
                j++;
            }
            if(j >= n){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};
