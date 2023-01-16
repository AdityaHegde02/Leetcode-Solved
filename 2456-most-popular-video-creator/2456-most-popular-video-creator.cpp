class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& id, vector<int>& v) {
        vector<vector<string>> ans;
        unordered_map<string,long long int> cv;    // {creator,total views}
        long long int mx = INT_MIN;
        for(int i = 0; i < c.size(); i++){
            cv[c[i]]+=v[i];
            mx = max(mx,cv[c[i]]);
        }
        unordered_map<string,int> mostViewPer;
        for(int i = 0; i < c.size(); i++){
            if(mostViewPer.find(c[i]) == mostViewPer.end()){
                mostViewPer[c[i]] = v[i];
            }
            else{
                mostViewPer[c[i]] = max(mostViewPer[c[i]],v[i]);
            }
        }
        unordered_map<string,string> mostViewId;
        for(int i = 0; i < c.size(); i++){
            string small = "zzzzzz";
            if(mostViewPer[c[i]] == v[i]){
                small = min(small,id[i]);
            }
            if(mostViewId.find(c[i]) == mostViewId.end()){
                mostViewId[c[i]] = small;
            }
            else{
                mostViewId[c[i]] = min(mostViewId[c[i]],small);
            }
        }
        for(auto &p : cv){
            if(p.second == mx){
                string creator = p.first;
                ans.push_back({creator,mostViewId[creator]});
            }
        }
        return ans;
    }
};