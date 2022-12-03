class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int,long long int> mp;
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i]] += i;
        }
        long long int mx = 0;
        int node = 0;
        for(auto &pair : mp){
            if(mx < pair.second){
                mx = pair.second;
                node = pair.first;
            }
        }
        return node;
    }
};