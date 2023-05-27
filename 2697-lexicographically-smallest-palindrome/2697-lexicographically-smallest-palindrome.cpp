class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n - 1 - i]){
                if(s[i] > s[n - 1 - i]){
                    s[i] = s[n - 1 - i];
                }
                else{
                    s[n - 1 - i] = s[i];
                }
            }
        }
        return s;
    }
};