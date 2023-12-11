class Solution {
public:
    int minTimeToType(string s) {
        int n = s.size(), ans = 0;
        char prev = 'a';
        for(int i = 0; i < n; i++){
            int moves = abs(prev - s[i]);
            ans += min(moves,26 - moves);
            prev = s[i];
        }
        return ans + n;
    }
};