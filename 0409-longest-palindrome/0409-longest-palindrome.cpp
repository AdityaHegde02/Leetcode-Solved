class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto &c : s){
            mp[c]++;
        }
        int ans = 0,once = 0;
        for(auto &i : mp){
            if(i.second % 2 == 0){
                ans += (i.second);
            }
            else{
                if(once == 0){
                    once = 1;
                    ans += i.second;
                }
                else{
                    ans += (i.second - 1);
                }
            }
        }
        return ans;
    }
};