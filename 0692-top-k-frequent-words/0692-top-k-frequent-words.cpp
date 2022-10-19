class Solution {
public:
    static bool cmp(pair<string, int>& a,pair<string, int>& b){
        if(a.second == b.second ){
            return b > a;
        }
        return a.second > b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        
        for(string s:words){
            mp[s]++;
        }
        
        vector<pair<string,int>> copy;
        
        for(auto &i : mp){
            copy.push_back({i.first,i.second});
        }
            
        sort(copy.begin(),copy.end(),cmp);
        
        vector<string> ans;
        
        for(int i = 0; i < copy.size(); i++){
            if(k){
                ans.push_back(copy[i].first);
                k--;
            }
        }
        
        return ans;
    }
};