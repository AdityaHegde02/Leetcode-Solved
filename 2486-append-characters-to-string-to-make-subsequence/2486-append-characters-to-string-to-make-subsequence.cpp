class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = 0;
        for(int j = 0; j < m; j++){
            if(i < n and s[j] == t[i]){
                i++;
            }
        }
        if(i == n){
            return 0;
        }
        return (n - i);
    }
};