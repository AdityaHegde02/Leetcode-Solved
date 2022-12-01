class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int mod = 7 + 1e9;
        int ans = 0;
        for(int i = 0; i < n; i++){
            long long int o = 0;
            while(s[i] == '1'){
                o++;
                i++;
            }
            ans += (o*(o+1))/2 % mod;
        }
        return ans % mod;
    }
};