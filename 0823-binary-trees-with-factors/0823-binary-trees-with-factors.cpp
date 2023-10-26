class Solution {
public:
    int mod = 7 + 1e9;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size(), ans = 1;
        vector<long> dp(n,1);
        unordered_map<int,int> mp;
        mp[arr[0]] = 0;
        for(int i = 1; i < n; i++){
            int root = arr[i];
            for(int j = 0; j < i; j++){
                int first = arr[j];
                if((root % first) == 0){
                    int second = (root/first);
                    if(mp.count(second)){
                        dp[i] += ((dp[mp[second]]*dp[j]) % mod);
                    }
                }
            }
            ans = (ans + dp[i]) % mod;
            mp[root] = i;
        }
        return ans;
    }
};