class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<pair<int,int>> st;
        unordered_map<int,int> f;
    
        for(auto &i : roads){
            f[i[0]]++;
            f[i[1]]++;
            st.insert({i[0],i[1]});
        }
        
        vector<pair<int,int>> arr;
        for(auto &i : f){
            arr.push_back({i.second,i.first});
        }
    
        int mx = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                pair<int,int> a = {arr[i].second,arr[j].second};
                pair<int,int> b = {arr[j].second,arr[i].second};
                int ans = arr[i].first + arr[j].first;
                if(st.count(a) or st.count(b)){
                    mx = max(mx,ans - 1);
                }
                else{
                    mx = max(mx,ans);
                }
            }
        }
        
        return mx;
    }
};