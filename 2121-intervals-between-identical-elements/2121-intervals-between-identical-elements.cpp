class Solution {
public:
    #define ll long long
    
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<ll,vector<ll>> mp;
        for(ll i = 0; i < arr.size(); ++i){
            mp[arr[i]].emplace_back(i);
        }
        
        vector<ll> ans(arr.size());
        
        for(auto &i : mp){
            vector<ll> a = i.second;
            ll sz = a.size();
            long long curr = 0;
            long long sum = accumulate(a.begin(),a.end(),0LL);
            for(ll j = 0; j < sz; j++){
                sum -= (ll)a[j];
                ans[a[j]] = abs(sum - (sz - 2*j - 1)*a[j] - curr);
                curr += (ll)a[j];
            }
        }
        
        return ans;
    }
};