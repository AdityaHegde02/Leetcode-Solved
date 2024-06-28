class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> mp;
        for(auto &i : roads){
            mp[i[0]]++;
            mp[i[1]]++;
        }
        
        vector<int> f;
        for(auto &i : mp){
            f.push_back(i.second);
        }
        
        sort(f.rbegin(),f.rend());
        long long imp = 0;
        
        for(int i = 0; i < f.size(); i++){
            imp += (long long)(n--)*(f[i]);
        }
        return imp;
    }
};