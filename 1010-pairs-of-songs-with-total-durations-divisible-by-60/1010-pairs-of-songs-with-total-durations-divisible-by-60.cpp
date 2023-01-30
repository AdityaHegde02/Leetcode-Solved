class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;      // {rem,fre}
        for(int &i : time){
            mp[i%60]++;
        }
        long long ans = 0;
        if(mp.count(0)){
            ans += (long long)mp[0]*(mp[0]-1)/2;
        }
        for(auto &i : mp){
            if(i.first < 30 and mp.find(60 - i.first) != mp.end()){
                ans += (long long)(i.second)*(mp[60-i.first]);
            }
        }
        if(mp.count(30)){
            ans += (long long)mp[30]*(mp[30] - 1)/2;
        }
        return ans;
    }
};