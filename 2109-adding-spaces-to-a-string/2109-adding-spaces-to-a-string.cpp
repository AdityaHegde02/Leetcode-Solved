class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int idx = 0;
        int n = s.size(), m = spaces.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(idx < spaces.size() and i == spaces[idx]){
                ans += " ";
                ans += s[i];
                idx++;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};