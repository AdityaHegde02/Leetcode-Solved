class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        int mx = 0 ;
        for(auto it:edges){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        for(auto it:mp){
            if(it.second==edges.size()){
                mx = it.first;
            }
        }
        return mx;
    }
};