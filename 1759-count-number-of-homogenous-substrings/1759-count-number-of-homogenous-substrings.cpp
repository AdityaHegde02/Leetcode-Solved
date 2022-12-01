class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int ans = 0;
        int mod = 7 + 1e9;
        for(int i = 0; i < n; i++){
            char c = s[i];
            long int x = 0;
            while(s[i] == c){
                i++;
                x++;
            }
            i--;
            ans += (x*(x + 1))/2 % mod;
        }
        return (ans % mod);
    }
};