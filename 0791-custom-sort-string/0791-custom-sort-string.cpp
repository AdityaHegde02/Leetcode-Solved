class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> chars;
        for(int i = 0; i < s.size(); ++i){
            chars[s[i]]++;
        }
        
        string ans = "";
        unordered_map<char,int> ord;
        for(int i = 0; i < order.size(); ++i){
            char c = order[i];
            ord[c]++;
            if(chars.find(c) != chars.end()){
                for(int j = 0; j < chars[c]; ++j){
                    ans += c;
                }
            }
        }
        
        for(int i = 0; i < s.size(); ++i){
            if(ord.find(s[i]) == ord.end()){
                ans += s[i];
            }
        }
        
        return ans;
    }
};