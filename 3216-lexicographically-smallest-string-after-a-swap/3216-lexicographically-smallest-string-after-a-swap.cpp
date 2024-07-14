class Solution {
public:
    string getSmallestString(string s) {
        for(int i = 0; i < s.size() - 1; i++){
            if(((s[i] - '0') % 2 == (s[i + 1] - '0') % 2) and ((s[i] - '0') > (s[i + 1] - '0'))){
                swap(s[i],s[i + 1]);
                return s;
            }
        }
        return s;
    }
};