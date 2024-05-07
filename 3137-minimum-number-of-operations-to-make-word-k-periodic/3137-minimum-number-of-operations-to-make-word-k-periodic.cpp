class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> mp;
        int mx = 0, n = word.size();
        for(int i = 0; i <= n - k; i += k){
            string s = word.substr(i,k);
            mp[s]++;
            mx = max(mx,mp[s]);
        }
        return (n - (mx*k))/k;
    }
};