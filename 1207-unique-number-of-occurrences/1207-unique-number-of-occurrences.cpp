class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto i:arr){
            mp[i]++;
        }
        unordered_set<int> s;
        for(auto i:mp){
            s.insert(i.second);
        }
        if(mp.size()==s.size()){
            return true;
        }
        return false;
    }
};